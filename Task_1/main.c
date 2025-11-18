#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_1;
    int num_2;
    printf("Enter your first number: ");
    scanf("%i",&num_1);
    printf("Enter your second number: ");
    scanf("%i",&num_2);
    printf("Addition answer: %i\n",num_1+num_2);
    printf("Subtraction answer: %i\n",num_1-num_2);
    printf("Multiplication answer: %i\n",num_1*num_2);
    printf("Division answer: %i\n",num_1/num_2);
    printf("Modulus answer: %i\n",num_1 % num_2);
    return 0;
}
