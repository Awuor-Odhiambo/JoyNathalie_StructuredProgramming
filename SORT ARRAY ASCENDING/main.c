#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, i, k, temp;
    int arr[100];

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    printf("Input %d elements in the array:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (arr[i] > arr[k])
            {
                temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
            }
        }
    }

    printf("Elements of the array in sorted ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}


