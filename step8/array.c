#include <stdio.h>

/*
 * Name : Peter Ye
 * Program to experiment with arrays
 */
#define NumMovies 10
#define MaxGrosses 5

int main()
{   
    int highestGrossIndex = 0;
    double highestGross = 0;
    double bigButSmallThanExpectedGross = 0;
    double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                               3156594, 1629735, 2659234, 2028036, 510768};
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech",
                              "Just Go With It", "Gnomeo and Juliet", "Drive Angry",
                              "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son",
                              "True Grit"};
    double sum;
    double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};
    sum = 0; /* Initialize to zero */
    for (int i = 0; i < NumMovies; i++)
    {
        printf("Movie %2d %33s: %.0f\n", i+1, names[i], gross[i]);
        sum += gross[i];
    }
    printf("Total gross for these films was $%.0f\n", sum);

    for(int j=0; j<MaxGrosses;j++){
        highestGross = maxGross[j];
        highestGrossIndex=-1;
        bigButSmallThanExpectedGross = 0;
        for(int i=0;  i<NumMovies;  i++)
            {
                if(gross[i] < highestGross)
                {
                    if (gross[i]>bigButSmallThanExpectedGross){
                        highestGrossIndex = i;
                        bigButSmallThanExpectedGross = gross[highestGrossIndex];
                    }
                    
                }
            }
        if (highestGrossIndex!=-1) {
            printf("The highest gross less than %.0f is %.0f at %s\n", highestGross, bigButSmallThanExpectedGross, names[highestGrossIndex]);
        }
        else {
            printf("No film made less than 500000\n");
        }
    }
    
}