#include <stdio.h>
#include <stdlib.h>

int main() {
    float income = 0, reduction=0, tax_income=0, tax=0;
    int status = 0, dependents = 0, children=0;

    printf("Enter your annual income: ");
    scanf("%f", &income);

    if (income<=9350) {
        printf("tax is: 0\n");
        exit(0);
    }

    printf("What is your filing status? \n1) single\n2) married filing jointly\n3) married filing separately\n");
    printf("Please enter a number: ");
    scanf("%d", &status);
    switch(status){
        case(1) : {
            dependents = 1;
            reduction = 5700;
            break;
        }
        case(2) : {
            dependents = 2;
            reduction = 11400;
            printf("How many children do you have? ");
            scanf("%d", &children);
            if (children<=0) {
                printf("error input!");
                exit(1);
            }
            dependents += children;
            break;

        }
        case(3) : {
            dependents = 1;
            reduction = 5700;
            break;
        }

        default : {
            printf("error input!\n");
            exit(1);
        }
    }

    reduction += dependents * 3650;
    tax_income = income - reduction;
    printf("debug: tax income: %f\n", tax_income);

    if (0<=tax_income && tax_income<16750) {
        tax = tax_income*0.1;
    }
    else if (16750<=tax_income && tax_income<68000) {
        tax = 1675 + (tax_income-16750) * 0.15;
    }
    else if (68000<=tax_income && tax_income< 137300) {
        tax = 9362.5 + (tax_income-68000) * 0.25;
    }
    else if (tax_income > 137300) {
        tax = 26687.5 + 0.28*(tax_income-137300);
    }
    else {
        printf("error input for tax income!%f", tax_income);
        exit(1);
    }


    printf("total tax to pay is: %.2f\n", tax);
    
}