#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 6

int buffer[BUFFER_SIZE];
int head = 0;

void insert(int value)
{
    buffer[head] = value;
    head = (head + 1) % BUFFER_SIZE;
}

void printBuffer()
{
    printf("Stored input: ");
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        int index = (head + i) % BUFFER_SIZE;
        printf("%d ", buffer[index]);
    }
    printf("\n");
}

int main()
{
    int value;
    char choice;

    printf("Enter the first %d integers:\n", BUFFER_SIZE);


    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        scanf("%d", &value);
        insert(value);
    }


    do
    {
        printf("Add another integer? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
        }

    } while (choice == 'y' || choice == 'Y');

    printBuffer();

    return 0;
}




