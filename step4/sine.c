#include <stdio.h>
#include <math.h>

int main()
{
    double angle, sinVal;
    int numSteps = 0, space=0, last_space=0;
    double maxAngle = M_PI * 2;

    while (numSteps < 2) {
        printf("Input the number of steps: ");
        scanf("%d", &numSteps);
    }

    for(int i = 0;  i<=numSteps;  i++)
    {
        angle = (double)i / (double)numSteps * maxAngle;
        sinVal = sin(angle);
        last_space = space;
        space = sinVal * 30 + 30;
        printf("%3d: %5.2f %f", i, angle, sinVal);
        for (size_t j = 0; j <= 60; j++)
        {
            if (j==space&&(j==0||j==60)){
                printf("*");
            }
            else if (j==space && ((space-last_space)>0)){
                printf("\\");
            }
            else if (j==space && ((space-last_space)<0)){
                printf("/");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
        
        
    }
}