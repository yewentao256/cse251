#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Simple program to experiment with looping
 */

int main()
{
    while (1) {
        int f = 0;      /* Number we compute the factorial of */
        int fac = 1;    /* Initial value of factorial */
        printf("Number to compute the factorial of: ");
        scanf("%d", &f);
        if (f<0) {
            break;
        }
        printf("%d! = ", f);
        while(f > 0)
        {
            fac = fac * f;
            f--;
        }

        printf("%d\n", fac);
    }
    
}