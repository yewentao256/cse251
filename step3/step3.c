#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    bool valid = true;  /* Until we know otherwise */
    float capacitance=0, inductance=0, result=0;

    printf("Input Capacitance (microfarads): ");
    scanf("%f", &capacitance);

    if (capacitance <=0) {
        printf("You moron, you entered a negative capacitance or zero, set the value to 1 \n");
        capacitance = 1;
    }

    printf("Input Inductance (millihenrys):");
    scanf("%f", &inductance);

    /* Test to see if the user entered an invalid value */    
    if(inductance < 0){
        printf("You moron, you entered a negative inductance!\n");
        valid = false;
    }
        
    else if (inductance == 0) {
        printf("You are really dumb, you entered zero.\n");
        valid = false;
    }
        
    else
        printf("Okay, I guess that's reasonable\n");

    if (valid) {
        result = 1/sqrt(capacitance/1000 * inductance/1000/1000);
        result /= 2 * M_PI;

        printf("Resonant Frequency is %6.3f\n", result);

        if (20 <= result <= 20000){
            printf("This frequency is one I can hear!\n");
        }
    }

}