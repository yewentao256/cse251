#include <stdio.h>
#include <math.h>

int main(){
    float capacitance=0, inductance=0, result=0;

    printf("Input Capacitance (microfarads): ");
    scanf("%f", &capacitance);

    printf("Input Inductance (millihenrys):");
    scanf("%f", &inductance);

    result = 1/sqrt(capacitance/1000 * inductance/1000/1000);
    result /= 2 * M_PI;

    printf("Resonant Frequency is %6.3f\n", result);
}