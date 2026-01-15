#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, d, count;
    int arr[100];

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    printf("Input %d elements in the array:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("The unique elements found in the array are: ");

    for (i = 0; i < n; i++)
    {
        count = 0;
        for (d = 0; d < n; d++)
        {
            if (arr[i] == arr[d])
            {
                count++;
            }
        }

        if (count == 1)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}



