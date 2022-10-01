#include <stdio.h>
#include <math.h>
/*
∗ CSE 251 Project 1
∗ By: Peter Ye
∗
∗ Complete the following table:
∗
∗ a b n estimate
∗ −1 1 1883 1.178979838
∗ 0 10 2028 0.489888070
∗ −1000 1000 18861 0.999796418
∗ 10 15 1515 0.016860599
∗ 0.1 0.2 138 0.096211811*/

double fn(double x)
{
    if (x == 0)
    {
        return 1;
    }
    return sin(M_PI * x) / (M_PI * x);
}
double calculate_I(int n, double a, double b)
{
    double delta = (b - a) / n;
    double result = 0;
    for (int i = 1; i <= n; i++)
    {
        result += fn(a + (i - 0.5) * delta) * delta;
    }
    return result;
}

int main()
{
    double a = 0, b = 0;
    int n = 10;
    double current_value = 0, last_value = -1024;
    printf("Enter a value for a: ");
    scanf("%lf", &a);
    printf("Enter a value for b: ");
    scanf("%lf", &b);
    printf("Integral evaluation\n");

    last_value = calculate_I(n, a, b);
    printf("%d: %.9f\n", n, last_value);
    for (n = n + 1; n < 100000; n++)
    {
        current_value = calculate_I(n, a, b);
        printf("%d: %.9f %e\n", n, current_value, current_value - last_value);
        if (fabs(current_value - last_value) < 1e-10)
        {
            break;
        }
        last_value = current_value;
    }
    printf("The integral result is %.9f", current_value);
}