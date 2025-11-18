#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char user_name[20];
    printf("Enter your name: ");
    scanf("%s",user_name);
    printf("Your name is %s\n",user_name);
    int length = strlen(user_name);
    printf("The length of your name: %i\n",length);
    return 0;
}
