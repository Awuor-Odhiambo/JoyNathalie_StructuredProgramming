#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 10;
    int num2 = 20;

    int *ptr1;
    int *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    int sum = *ptr1 + *ptr2;

    printf("Sum = %d\n", sum);

    return 0;
}

