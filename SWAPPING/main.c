#include <stdio.h>
#include <stdlib.h>

void swapNumbers(int *x, int *y) {
    int num;

    num = *x;
    *x = *y;
    *y = num;
}

int main() {
    int a = 5;
    int b = 10;

    printf("Before swapping:\n");
    printf("a = %d, b = %d\n", a, b);


    swapNumbers(&a, &b);


    printf("After swapping:\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}

