#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hanoi.h"

/*
 * Display a disk of width p
 */
void DisplayDisk(int p)
{
    int i;
    int spaceAround = (MaxDiskSize - p) / 2;

    for(i=0; i<spaceAround;  i++)
        printf(" ");

    if(p == 0)
    {
        printf("|");
    }
    else
    {
        for(i=0;  i<p;  i++)
            printf("O");
    }

    for(i=0;  i<spaceAround;  i++)
        printf(" ");
}


/*
 * Display the Towers of Hanoi
 */
void DisplayTower(int tower[NumPins][NumDisks])
{
    int i;

    printf("\n ");

    DisplayDisk(0);
    printf("  ");
    DisplayDisk(0);
    printf("  ");
    DisplayDisk(0);
    printf("\n");

    for(i=0;  i<NumDisks;  i++)
    {
        printf(" ");

        /* We display from the top down */
        DisplayDisk( tower[0][5 - i] );
        printf("  ");
        DisplayDisk( tower[1][5 - i] );
        printf("  ");
        DisplayDisk( tower[2][5 - i] );
        printf("\n");
    }

    for(i=0;  i<NumPins * MaxDiskSize + (NumPins - 1) * 2 + 2; i++)
        printf("=");

    printf("\n");
}