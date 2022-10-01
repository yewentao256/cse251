#include <stdio.h>

/* 
 * Name : Peter Ye
 * Program to experiment with hexadecimal
 * and pointers
 */
 
int main()
{
    int a = 0;
    int b = 5;
    int c = 0x2251;

    printf("%d: %x\n", a, a);
    printf("%d: %x\n", b, b);
    printf("%d: %x\n", c, c);

    printf("%lx\n", (long int)&a);

    int *pA = &a;
    int *pB = &b;
    int *p;
    printf("a=%d, pA=%x, *pA=%d\n", a, (int)pA, *pA);

    a = 47;
    printf("a=%d, pA=%x, *pA=%d\n", a, (int)pA, *pA);
    *pA = 99;
    printf("a=%d, pA=%x, *pA=%d\n", a, (int)pA, *pA);

    printf("Next experiment:\n");
    p = pA;
    *p = 22;
    p = pB;
    *p = 18;
    p = &b;
    *p = 108;
    p = pA;
    *p = 2;
    printf("a=%d, pA=%x, *pA=%d\n", a, (int)pA, *pA);
    printf("b=%d, pB=%x, *pB=%d\n", b, (int)pB, *pB);
    printf("p=%x, *p=%d\n", (int)p, *p);
}