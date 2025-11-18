#include <stdio.h>
#include <stdlib.h>

int main()
{
    float radius;
    float pi= 3.142;
    printf("Enter value of radius: ");
    scanf("%f",&radius);
    float area= 4*pi*radius*radius;
    printf("Surface area of sphere: %f",area);
    return 0;
}
