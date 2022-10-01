#include <stdio.h>

/* 
 * Name : Peter Ye
 * Program to experiment with character arrays
 */

#define MaxWord 20
 
int main ()
{
    char c;
    char str[MaxWord+1];
    int len = 0;
    double sum=0, num=0;
    char longest_word[MaxWord+1];
    int longest = 0; 
  
    puts ("Enter text. Include a dot ('.') to end a sentence to exit:");
    do 
    {
        c=getchar();
        if(c != ' ' && c != '.')
        {
            /* Only save it if we have space */
            if(len < MaxWord)
            {
                str[len] = c;
                len++;
            }
        }
        else
        {
            if (len == 0){
                continue;
            }
            /* The word is done */
            sum += len;
            num += 1;

            str[len] = 0;
            if (len > longest) {
                for (int j =0; j <= len; j++){
                    longest_word[j] = str[j];
                }
                longest = len;
            }
            printf("%s\n", str);
            len = 0;
        }
    } while (c != '.');

    printf("the average word length is: %.2f\n", sum/num);
    printf("the longest word is: %s\n", longest_word);
}