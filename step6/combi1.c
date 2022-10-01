#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 . 1. Function declaration.
 . This tells the compiler about our function. 
 . It must match the first line of the function definition below. 
 */
 
int Factorial(int n);
int Binomial(int n, int k);
/*
 . This is a function definition for a function called main that
 . takes no arguments and returns an integer. You've been writing
 . this function all along.
 */
 
int main()
{
    int n;
    int k;
    int b;
    
    printf("Input n: ");
    scanf("%d", &n);
    if(n < 1)
    {
        printf("Must be greater than zero\n");
        exit(1);
    }
    
    printf("Input k: ");
    scanf("%d", &k);
    if(k < 0 || k > n)
    {
        printf("Must be between 0 and %d\n", n);
        exit(1);
    }
    
    /*
     . 3. Function invocations.
     . Here are function invocations for Factorial. There are
     . Three of them because the binomial coefficient formula
     . has three factorials in it.
     */
     
    
    b = Binomial(n, k);
    printf("%d items taken %d ways is %d\n", n, k, b);
}

/* 
 . 2. Function definition.
 . This is the definition of the Factorial function.
 . This is where you tell what the function does.
 */
 
int Factorial(int n)
{
    int f = 1;
    int i;
    for(i=1;  i<=n;  i++)
    {
        f *= i;
    }
    return f;
}

int Binomial(int n, int k)
{
    if (n==k || k==0) {
        return 1;
    }
    return Binomial(n - 1, k - 1) + Binomial(n - 1, k);
}