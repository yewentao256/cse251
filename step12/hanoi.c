#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hanoi.h"
#include "autosolve.h"

/*
 * Name :  Peter Ye
 *
 * Simple Towers of Hanoi game. You can solve it yourself or
 * ask the game to solve it for you.
 */

bool CheckDone(int tower[NumPins][NumDisks]);

/*
 * The program main entry point
 */
int main()
{
    int tower[NumPins][NumDisks];
    int fm, to;

    /* Reset the tower to all disks on the first pin */
    Reset(tower);
    printf("\n");

    do
    {
        /* Display the tower before the move */
        DisplayTower(tower);

        /* Get a move from the user */
        fm = InputPin("Pin to move from: ", 0, 3);
        if(fm == 0)
        {
            Autosolve(tower);
            break;
        }

        to = InputPin("Pin to move to: ", 1, 3);

        /* Perform the move the user asked */
        MoveDisk(tower, fm, to);

    } while(!CheckDone(tower));

    return 0;
}

/*
 * Reset the tower to its initial state
 */
void Reset(int tower[NumPins][NumDisks])
{
    int i, j;

    for(j=0;  j<NumDisks;  j++)
    {
        tower[0][j] = 13 - j * 2;
    }

    for(i=1; i<NumPins;  i++)
    {
        for(j=0;  j<NumDisks;  j++)
        {
            tower[i][j] = 0;
        }
    }

}


/*
 * Move a disk from one pin to another
 */
void MoveDisk(int tower[NumPins][NumDisks], int fm, int to)
{
    int f;
    int t;
    int moving;

    /* Where is the pin to move? */
    for(f=NumDisks-1; f>=0;  f--)
    {
        if(tower[fm-1][f] > 0)
            break;
    }

    if(f < 0)
    {
        printf("No disks on that pin\n");
        return;
    }

    /* Size we are moving */
    moving = tower[fm-1][f];

    /* Where is an empty space to move to? */
    for(t=NumDisks-1; t>=0;  t--)
    {
        if(tower[to-1][t] > 0)
            break;
    }

    /* Test to move legality */
    if(t >= 0 && tower[to-1][t] < moving)
    {
        printf("\n!!! Illegal move !!!\n");
        return;
    }

    /* And move it */
    t++;
    tower[to-1][t] = moving;
    tower[fm-1][f] = 0;
}


/*
 * Get a pin from the user
 */
int InputPin(char *msg, int fm, int to)
{
    int val;

    /* Allow values in the range [fm, to] */
    do
    {
        printf("%s", msg);
        scanf("%d", &val);
        if(val < fm || val > to)
            val = fm-1;

    } while(val < fm);

    return val;
}

/*
 * Check to see if all disks moved to last pin
 */
bool CheckDone(int tower[NumPins][NumDisks])
{
    return tower[0][0] == 0 && tower[1][0] == 0;
}
