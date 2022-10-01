#include <stdio.h>
#include <math.h>

int main()
{
    double angle, sinVal;
    int numSteps = 40, space=0;
    double maxAngle = M_PI * 2;
    int i;

    for(i = 0;  i<=numSteps;  i++)
    {
        angle = (double)i / (double)numSteps * maxAngle;
        sinVal = sin(angle);
        space = sinVal * 30 + 30;
        printf("%3d: %5.2f ", i, angle);
        for (size_t i = 0; i <= 60; i++)
        {
            if (i==space){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
        
        
    }
}