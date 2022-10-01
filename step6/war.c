#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Name : Peter Ye
 * Program to draw playing cards
 */

/* Function declaration */
void PrintCard(int card, int suit);

void PrintResult(int card1, int card2, int suit1, int suit2); 


int main()
{
    int suit1, suit2;
    int card1, card2;
    
    /* 
     . This seeds the random number 
     . generator with the current time 
     */
    srand(time(NULL));
    
    /* Create a random card and suit */
    /* This will compute a random number from 0 to 3 */

    suit1 = rand() % 4;
    /* This will compute a random number from 1 to 13 */
    card1 = rand() % 13 + 1;
    suit2 = rand() % 4;
    card2 = rand() % 13 + 1;

    while (suit1==suit2 && card1==card2) {
        printf("There is a tie\n");
        suit1 = rand() % 4;
        /* This will compute a random number from 1 to 13 */
        card1 = rand() % 13 + 1;
        suit2 = rand() % 4;
        card2 = rand() % 13 + 1;
    }

    printf("player 1: ");
    PrintCard(card1, suit1);

    printf("player 2: ");
    PrintCard(card2, suit2);

    PrintResult(card1, card2, suit1, suit2);
           
}

void PrintCard(int card, int suit)
{
    switch(card)
    {
    case 1:
        printf("Ace");
        break;
        
    case 11:
        printf("Jack");
        break;
        
    case 12:
        printf("Queen");
        break;
        
    case 13:
        printf("King");
        break;
        
    default:
        printf("%d", card);
        break;
    }
    
    printf(" of ");
    
    switch(suit)
    {
    case 0:
        printf("Hearts");
        break;
        
    case 1:
        printf("Diamonds");
        break;
        
    case 2:
        printf("Spades");
        break;
        
    case 3:
        printf("Clubs");
        break;
    }

    printf("\n");
}
void PrintResult(int card1, int card2, int suit1, int suit2){
    if (card1==1){
        card1 += 13;
    }
    if (card2==1){
        card2 += 13;
    }
    if (card1 > card2){
        printf("Player 1 wins");
    }
    else if (card1 <card2) {
        printf("Player 2 wins");
    }
    else {
        if (suit1 < suit2) {
            printf("Player 1 wins");
        }
        else if (suit1 > suit2) {
            printf("Player 2 wins");
        }
        else {
            printf("There is a tie");
        }
    }
    
}