#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 5;
    int *pCount;

    pCount = &count;

    *pCount = 20;

    printf("Updated value of count: %d\n", count);

    return 0;
}

