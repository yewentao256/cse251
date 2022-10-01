#include <stdio.h>
#include <math.h>

/*
 * Name : Peter Ye
 * 
 * This is my second CSE 251 C program!!!
 */

int main(){
    double radius = 7.88;
    double height = 12.231;
    printf("The cylinder has a radius of %+5.2f and a height of %8.1f\n", radius, height);
    // The cylinder has a radius of +7.88 and a height of     12.2
    // The output has a lot of space before the height. Why is that? total lenth of 8

    int wins = 11;
    int loss = 2;
    printf("MSU had an %d-%d season in 2010!\n", wins, loss);

    double volume, diameter, hypot;
    int games;
    volume = radius * radius * M_PI * height;

    double near = 10;
    double far = 22.5;
    hypot = sqrt(near * near + far * far);
    // gcc -o step2 step2.c -lm, use "-lm to show that add library libm, the math library"

    double bottleVolume = 1700;  /* Milliliters */
    double cupVolume = 350;      /* Milliliters */
    int numCups;

    numCups = bottleVolume / cupVolume;
    numCups = (int)(bottleVolume / cupVolume);  // much better
    printf("Number of cups: %d\n", numCups);
}