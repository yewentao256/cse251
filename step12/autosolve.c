#include <stdio.h>
#include "autosolve.h"


/*
 * Automatically solve the Towers of Hanoi problem.
 * This resets the tower to the initial state, then
 * solves it one step at a time.
 */
void Autosolve(int tower[NumPins][NumDisks])
{
    /* Always start with empty tower */
    Reset(tower);
    AutoMove(tower, NumDisks, 1, 3);
    DisplayTower(tower);
}


/*
 * Recursive solution for Towers of Hanoi. Moves num disks from
 * pin fm to pin to.
 */
void AutoMove(int tower[NumPins][NumDisks], int num, int fm, int to)
{
    int unused;
    char cmd[2];

    /* Base condition, moving one disk */
    if(num == 1)
    {
        /* This is the only time we actually move a disk */
        DisplayTower(tower);

        printf("Press return");
        fgets(cmd, sizeof(cmd), stdin);

        MoveDisk(tower, fm, to);
        return;
    }

    /* What is the unused pin? */
    for(unused=1;  unused <=3;  unused++)
    {
        if(unused != fm && unused != to)
            break;
    }

    /* Recursive solution for fewer pins */
    AutoMove(tower, num-1, fm, unused);
    AutoMove(tower, 1, fm, to);
    AutoMove(tower, num-1, unused, to);
}


