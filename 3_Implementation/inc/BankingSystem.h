/**
 * @file BankingSystem.h
 * @author Swaraj Das
 * @brief Complex structure definition
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 *  
 */

#include<stdio.h>
int list();
void transfer();
void deposit();
void Quit();
void withdraw();
void check_detail();
void login();
void menu();

int total_amount = 2500, Amount, Withdraw_amt, Tr, total_deposit = 0, total_withdraw = 0;
int totalTr = 0;
int Acc;
char NAME[20];
char Author[20] = "Swaraj Das";

void login() {
    char usedID[20];
    char password[20];
    printf("\n\t\t\tEnter your USER ID :");
    gets(usedID);
    printf("\n\t\t\tEnter your password :");
    gets(password);

    if(strcmp(usedID,"MyID")==0)
    {
        if(strcmp(password,"123")==0)
        {
            printf("\n\n\t\t\tLog in Successfull....!!!!!!!!");
            printf("\n\t\t\tEntering into the System......\n\n");
            menu();
        }
        else{
            printf("\nInvalid Password....");
        }
    }
    else{
        printf("\nYou have Entered INVALID Credentials.....");
        printf("\nPlease enter again.......");
        return login();
    }

}
void menu(){
    start:
    printf("\n*******Enter Your Choice from the Menu*******");
    while(1){
        switch (list()){
        case 1:
            deposit();
            total_deposit += Amount;
            break;
        case 2:
            withdraw();
            if (Withdraw_amt <= total_amount)
                total_withdraw += Withdraw_amt;
            break;
        case 3:
            transfer();
            if (Tr <= total_amount)
                totalTr += Tr;
            break;
        case 4:
            check_detail();
            break;
        case 5:
            Quit();
            exit(0);
        default:
            printf("\n You have entered Invalid choice \n Please Enter a valid choice from 1 to 5......!!!!!!!\n");
            goto start;
        } //end of switch
    } //end of while
}

int list(){
    int ch;
    printf("\n 1. Diposit amount");
    printf("\n 2. Withdraw amount");
    printf("\n 3. Transfer amount");
    printf("\n 4. Check your details");
    printf("\n 5. Exit");
    printf("\n Enter you choice: ");
    scanf("%d", &ch);
    return (ch);
}

/*Function For Deposites*/
void deposit(){
    printf("\n Enter the amount you want to deposit: ");
    scanf("%d", &Amount);
    total_amount += Amount;
    printf("\n.....Account updated.....");
}

/*Function For Withdrawl*/
void withdraw(){
    printf("\n Enter the amount you want to withdraw: ");
    scanf("%d", &Withdraw_amt);
    if (Withdraw_amt <= total_amount)
    {
        total_amount = Withdraw_amt;
        printf("\n.....Account updated.....");
    }
    else{
        printf("\n Less amount withdraw is not possible: ");
    }
}

/*Function For Fund Transfer*/
void transfer(){
    printf("\n  Enter the amount you want to transfer: ");
    scanf("%d", &Tr);
    if (Tr <= total_amount)    {
        total_amount -= Tr;
        printf("\nMoney Trasnfered Successfully..........");
        printf("\n.....Account updated.....");
    }
    else
    {
        printf("\n Less amount is not possible: ");
    }
}

/*Function For Checking your Bank Statements*/
void check_detail(){
    // printf("\n Welcome to Your Statements %s", NAME);
    // printf("\n Your Account Number is : %d", Acc);
    printf("\n***************\n");
    printf("\n Total amount= %d", total_amount);
    printf("\n Total deposite amount= %d", total_deposit);
    printf("\n Total withdraw amount= %d", total_withdraw);
    printf("\n Total transfered amount= %d", totalTr);
    printf("\n***************\n");
}

void Quit(){
    printf("\n*******\n");
    printf("\n Your name= %s", NAME);
    printf("\n Account number= %d", Acc);
    printf("\n Total amount= %d", total_amount);
    printf("\n Total deposited amount= %d", total_deposit);
    printf("\n Total withdraw amount= %d", total_withdraw);
    printf("\n Total transfered amount= %d", totalTr);
    printf("\n*****Thank you For using Have a Nice Day******\n");
}
