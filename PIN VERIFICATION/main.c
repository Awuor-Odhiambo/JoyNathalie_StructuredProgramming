#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool login(){
    int PIN = 1234;
    int user_PIN;
    int attempts = 0;

    while (attempts < 3){
      printf("Enter your PIN: \n");
      scanf("%d",&user_PIN);

      if (user_PIN == PIN){

        printf("Login successful\n");
        return true;

     }else{
          printf("Incorrect.Try again\n");

       attempts ++;
      }
    }

  printf("Too many attempts. Access denied.\n");
  return false;
  }

float checkBalance(float balance){
    printf("Your current balance is: %.2f\n",balance);
    return balance;
}
float deposit(float balance,float amount){
    if (amount <= 0){
    balance +=amount;
    printf("Invalid amount.Deposit must be positive\n");
    return balance;
    }
    balance += amount;
    printf("You deposited %.2f\n",amount);
    printf("new balance: %.2f\n",balance);
    return balance;

}
float withdraw(float balance, float amount){
    if (amount<= 0){
        printf("Invalid amount.Withdrawal must be positive\n");
        return balance;
    }
    if (amount>balance){
        printf("Insufficient balance\n");
    }else{
    balance -= amount;
    printf("You withdrew %.2f\n",amount);
    printf("New balance: %.2f\n",balance);
    }
    return balance;
   }



int main(){
   if (!login()){
       return 0;
   }


   float balance = 1000.0;
   float amount;
   int choice;


   while(1){
printf("\n---Menu---\n");
    printf("1. Balance enquiry\n 2.Deposit\n  3.Withdraw\n  4.Exit\n ");
    printf("Enter your choice: \n");
    scanf("%d", &choice);

    switch(choice){
    case 1:
        balance= checkBalance(balance);
        break;

    case 2:
        printf("Enter amount to deposit: \n");
        scanf(" %f",&amount);
        balance = deposit(balance,amount);
        break;

    case 3:
        printf("Enter amount to withdraw: \n");
        scanf(" %f",&amount);
        balance = withdraw(balance,amount);
        break;

    case 4:
        printf("Thank you for using our ATM\n");
        return 0;

    default:
        printf("Invalid option.\n");
     }


}

  return 0;
}
