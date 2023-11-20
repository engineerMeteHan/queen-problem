/****************************************************************************
* - Engineer Name      : Metehan Gencer                                     *
* - Date               : 2023 - 11 -18                                      *
* - Version            : V0.0 Rev                                           *
* - Code Description   : Placing eight queens on a 8x8 chessboard, without  *
*                        overlapping eacg other. Two queens can take each   *
*                        other when they are in the same row, column or     *
*                        diagonal. In other words, there should not be two  *
*                        queens in the same row, column, or diagonal line   *
*                        in a solution                                      *
****************************************************************************/
#include <stdio.h>
#define VEZIRLER 8      // Number of wueens and board size
#define int unsigned    // Use unsigned integer

int sayi = 0;           // Number of solutions
int tahta[VEZIRLER];    // Each element represent a row

int tahtaTamam(register int sira)
{
    register int r;
    for(r = 0; r < sira; r++)   // Chect out all provious row
        if(tahta[sira] == tahta[r] || tahta[sira] == tahta[r] << sira - r || tahta[sira] == tahta[r] >> sira - r)
            return 0;       // If there is a dispute
    return 1;               // If there is no dispute
}

void cozumYaz(void)         // Show solution, increase number
{
    register int t, r;
    printf("\n\n\tCOZUM %u\n\n", ++sayi);
    for(r = 0; r < VEZIRLER; r++)   // sýra
    {
        for(t = 1 << VEZIRLER - 1; t > 0; t >>= 1)
            printf(" %c", tahta[r] == t ? 'V' : '.');
        printf("\n");
    }
}

/// This funsciton is an recursive function 
void yerlestir(int sira)        // Place it in the next row
{
    if (sira == VEZIRLER)       // All rows are full and checked
        cozumYaz();
    else
        for (tahta[sira] = 1; tahta[sira] < 1 << VEZIRLER; tahta[sira] <<= 1)
            if(tahtaTamam(sira))
                yerlestir(sira + 1);    // Try the next row
}

signed main(void)
{
    yerlestir(0);   // Start from the first row.
    printf("\n\n%d vezir probleminin %u cozumu vardir.\n", VEZIRLER, sayi);
    return 0;
}

