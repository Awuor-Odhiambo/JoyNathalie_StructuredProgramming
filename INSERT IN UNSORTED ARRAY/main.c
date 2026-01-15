#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100];
    int n, i, pos, value;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    printf("Input %d elements in the array:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Input value to be inserted: ");
    scanf("%d", &value);

    printf("Input the position where to be inserted: ");
    scanf("%d", &pos);

    printf("The current list of the array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    for (i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    printf("\nAfter insert the element the new list is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

