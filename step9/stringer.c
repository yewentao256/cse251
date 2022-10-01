#include <stdio.h>
#include <string.h>

/* 
 * Name : Peter Ye
 * Program to experiment with strings
 */
  
int StringLength(char str[]);
void PrintLength(char str[]);
void Reverse(char str[] );
int NumberOfSpaces(char str[]);
int NumberOfAppearances(char str[], char ch);

int main ()
{
    char mySentence[80];
    int len;
    char c = 'a';
    
    printf("Enter a sentence: ");
    fgets(mySentence, 80, stdin);
    len = strlen(mySentence);
    mySentence[len - 1] = '\0';
    printf("The entered sentence is: %s\n", mySentence);
   
    PrintLength(mySentence);
    Reverse(mySentence);
    printf("%s\n", mySentence);

    printf("the number of spaces is: %d\n", NumberOfSpaces(mySentence));
    printf("the number of character %c is: %d", c, NumberOfAppearances(mySentence, c));
}

void PrintLength(char str[])
{
    printf("The string %s is %d characters long\n", str, strlen(str));
}


int StringLength(char str[])
{
    int numChars = 0;
    
    while(str[numChars] != '\0')
    {
        numChars++;
    }
    
    return numChars;
}

void Reverse(char str[] )
{
    int front = 0;       
    int back = strlen(str) - 1;  
    char t;             /* A temporary place to put a character */
    
    while (front < back)
    {
        t = str[front];
        str[front] = str[back];
        str[back] = t;
        front++;
        back--;
    }
}

int NumberOfSpaces(char str[])
{
    int i;
    int numSpaces = 0;
    
    for(i=0;  str[i] != '\0';  i++)
    {
        if(str[i] == ' ')
            numSpaces++;
    }
    
    return numSpaces;
}

int NumberOfAppearances(char str[], char ch)
{
    int i;
    int numChracters = 0;
    
    for(i=0;  str[i] != '\0';  i++)
    {
        if(str[i] == ch)
            numChracters++;
    }
    
    return numChracters;
}