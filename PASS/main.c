#include <stdio.h>
#include <stdlib.h>



void incrementCallByValue(int x) {
    x = x + 1;
}


void incrementCallByReference(int *x) {
    *x = *x + 1;
}

int main() {
    int num = 10;


    incrementCallByValue(num);
    printf("After Call By Value increment: num = %d\n", num);

    // call by reference
    incrementCallByReference(&num);
    printf("After Call By Reference increment: num = %d\n", num);

    return 0;
}

