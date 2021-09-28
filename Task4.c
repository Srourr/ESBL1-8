#include <stdio.h> 
#include "Types.h"
#include "Task4.h"
#define True 1
#define False 0

/*isn't Used*/
typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t transData;
    EN_transStat_t transStat;

}ST_transaction;

uint8_t Data_Check(),Transaction_Is = APPROVED;

/*server pre-defined data */
ST_accountBalance_t server [5] = {{100.0,"123456789"},{6000.0,"234567891"},{3250.25,"567891234"},{1500.12,"456789123"},{500.0,"258649173"}};	


int main()
{
/*YesOrNo variable is used in making decison of another procces or not and Trans_State is used to 
know if the transaction was approved or declined*/

uint8_t YesOrNo,Trans_State;

Trans_State = Data_Check();

if (Trans_State == APPROVED)
{
	printf("\nThe Transaction is APPROVED.");
}
else 
	{
	printf("\nThe Transaction is DECLINED.");
	}

printf("\nDo you want to continue (Y/N) ?\n");
scanf("%s",&YesOrNo);

if (YesOrNo == 'Y') 
{
	Transaction_Is = APPROVED;
	return main();
/* Returning to the main function and begining the process again */
}
else if(YesOrNo == 'N') return 0;
}

/* 
In Data_Check Function the card data is being checked like card holder name, primary account number and card expiration date if 
the primary account number is wrong the transaction is DECLINED if the Card Data is correct then the terminal data is checked like transaction
date and transaction amount  
*/

uint8_t Data_Check()
{
	
ST_cardData_t User;
ST_terminalData_t Terminal;

	/*
	First the Card Data Checking :
	*/
	
uint8_t Index,Correct,Account_Number_Check,Transaction_Date[8];
float Transaction_Amount;

/*Reading the Card Data from user like Name, Account Number, Expiry Date and Transaction Date*/

printf("\nPlease Enter The Card Holder Name :\n");
scanf("%s",&User.cardHolderName);
scanf("%s",&User.cardHolderName);
printf("Please Enter Primary Account Number :\n");
scanf("%s",&User.primaryAccountNumber);
printf("Please Enter Card Expiry Date :\n");
scanf("%s",&User.cardExpirationDate);
printf("Please Enter Transaction Date :\n");
scanf("%s",&Terminal.transactionDate);

/*Checking the Primary Account Number by comparing the input number by each account number in server data, each element in array is checked 
seperatly cause it's a string not a number */
for (Account_Number_Check = 0 ; Account_Number_Check < 5 ; Account_Number_Check++)
{
 Correct = 0;
 for (Index = 0 ; Index < 9 ; Index ++)
	{
 if ( (User.primaryAccountNumber[Index]) == (server[Account_Number_Check].primaryAccountNumber[Index]) )
		{
	Correct ++;
		}
 else 
		{
	 continue;
		}
	}
 if (Correct == 9 ) 
			{
	 Transaction_Is =  APPROVED;
	 break;
			}
 else Transaction_Is =  DECLINED;
}

/*  NOW Checking the terminal Data :*/
/*Comparing the numbers in expiration date and transaction date strings by comparing specific elements which represents the months and years*/
/*Checking the transaction date starting from the /YY/ "years" to /MM/ Months from the highest value in years to least value in months in case of that the years are equal*/

	if((User.cardExpirationDate[3] < Terminal.transactionDate[6])) Transaction_Is =  DECLINED;
	else if ((User.cardExpirationDate[3] == Terminal.transactionDate[6]) && (User.cardExpirationDate[4] < Terminal.transactionDate[7])) Transaction_Is =  DECLINED;
	else if ((User.cardExpirationDate[3] == Terminal.transactionDate[6]) && (User.cardExpirationDate[4] == Terminal.transactionDate[7]) && (User.cardExpirationDate[0] < Terminal.transactionDate[3])) Transaction_Is =  DECLINED;
	else if ((User.cardExpirationDate[3] == Terminal.transactionDate[6]) && (User.cardExpirationDate[4] == Terminal.transactionDate[7]) && (User.cardExpirationDate[0] == Terminal.transactionDate[4]) &&(User.cardExpirationDate[1] < Terminal.transactionDate[4])) Transaction_Is =  DECLINED;
	else 
	{
		
	}
	/*The maximum transaction amount of terminal*/
	Terminal.maxTransAmount = 5000.0;
	printf("\nPlease Enter Terminal Data :\nPlease Enter the transaction Amount:\n");
	scanf("%f",&Terminal.transAmount);
	/*Checking first if the earilier checks were approved or declined if it was declined there's no need to check the amount of transaction
	cause the process is already invalid*/
	if (Transaction_Is == DECLINED)
	{
	return Transaction_Is;	
	}
	/*If the earlier checks were approved the amount will be the last check which decides if the transaction approved or not*/
	else
	{
	if ( (Terminal.transAmount > server[Account_Number_Check].balance) || (Transaction_Amount > Terminal.maxTransAmount) )
		{
		Transaction_Is = False;
		}
		else 
		{
		Transaction_Is = True;
		}
	}
	return Transaction_Is;

}
