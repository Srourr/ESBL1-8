#include<stdio.h>

typedef struct ST_carData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef struct ST_terminalData_t
{
     float transAmount;
     float maxTransAmount;
     uint8_t transactionDate[11];
}ST_terminalData_t;


typedef struct ST_accountBalance_t
{
     float balance;
     uint8_t primaryAccountNumber[20];
}ST_accountBalance_t;

typedef enum EN_transStat_t
{
    DECLINED,
    APPROVED
}EN_transStat_t;