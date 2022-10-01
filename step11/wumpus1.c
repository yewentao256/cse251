#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/*
 * Name :  Peter Ye
 *
 * Simple Wumpus game in 1D
 */

/* Id's for things in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2
/* Number of rooms in our Cave */
#define CaveSize 20
#define ArraySize (CaveSize + 2)
/* Add any function prototypes here */
/* Directions I can face */
#define Left 0
#define Right 1

int *GetEmptyRoom(int cave[])
{
    int room;

    do
    {
        room = rand() % ArraySize;
    } while (cave[room] != Empty);

    return &cave[room];
}

void CreateWorld(int cave[])
{
    int *room;
    /* Initialize cave to empty */
    for (int i = 0; i < ArraySize; i++)
    {
        cave[i] = Empty;
    }
    /* Set the ends */
    cave[0] = End;
    cave[ArraySize - 1] = End;
    /* Get a random empty room and put the Wumpus in it */
    room = GetEmptyRoom(cave);
    *room = Wumpus;
}

void DisplayWorld(int cave[], int *agent, int agentDir)
{
    int *room;

    for (room = cave + 1; *room != End; room++)
    {
        if (room == agent)
        {
            switch (agentDir)
            {
            case Left:
                printf("<A  ");
                break;

            case Right:
                printf(" A> ");
            }

            continue;
        }
        switch (*room)
        {
        case Wumpus:
            printf("-W- ");
            break;

        default:
            printf(" .  ");
            break;
        }
    }
    printf("\n");
}

int DifferenceByDirection(int dir)
{
    if (dir == Left)
        return -1;
    else
        return 1;
}

bool DisplayStatus(int cave[], int *agent)
{
    if (*agent == Wumpus)
    {
        printf("You have been eaten by the Wumpus\n");
        return true;
    }
    if (*(agent - 1) == Wumpus || *(agent + 1) == Wumpus)
    {
        printf("I smell a Wumpus\n");
    }
    bool find = false;
    for (int *room = cave + 1; *room != End; room++)
    {
        if (*room == Wumpus)
        {
            find = true;
        }
    }
    if (!find)
    {
        printf("I killed a Wumpus!\n");
        return true;
    }
    return false;
}

int main()
{
    int cave[ArraySize];
    int *agentRoom;
    int agentDirection;
    char command[20];
    int direction;
    /* Seed the random number generator */
    srand(time(NULL));
    CreateWorld(cave);

    agentRoom = GetEmptyRoom(cave);
    agentDirection = rand() % 2;

    /* The game loop */
    while (true)
    {
        if (DisplayStatus(cave, agentRoom))
            break;
        DisplayWorld(cave, agentRoom, agentDirection);
        /* Get the command */
        printf("Command: ");
        scanf("%20s", command);
        if (strcmp(command, "quit") == 0)
        {
            /* Exit, we are doing */
            break;
        }
        else if (strcmp(command, "move") == 0)
        {
            /* Move command */
            /* What way do we need to go? */
            direction = DifferenceByDirection(agentDirection);
            if (*(agentRoom + direction) != End)
                agentRoom += direction;
        }
        else if (strcmp(command, "shoot") == 0)
        {
            printf("shooting!...");
            direction = DifferenceByDirection(agentDirection);
            for (int j = 1; j <= 3 && *(agentRoom + direction * j) != End; j++)
            {
                if (*(agentRoom + direction * j) == Wumpus)
                {
                    *(agentRoom + direction * j) = Empty;
                }
            }
        }
        else if (strcmp(command, "turn") == 0)
        {
            agentDirection = !agentDirection;
        }
        else
        {
            printf("I don't know what you are talking about\n");
        }
    }
}