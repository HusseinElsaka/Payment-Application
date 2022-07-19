#pragma once

#ifndef CARD_H
#define CARD_H

#include <string.h>
#include <stdio.h>

/* Define for Max and Min Values */
#define NAME_MIN 20
#define NAME_MAX 24
#define CARD_MAX 19
#define CARD_MIN 16
#define EXPIRE_LEN 5

typedef unsigned char uint8_t;


typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
	OK_CARD, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

/* ask for the cardholder's name and store it into card data and Validate it */
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
/* ask for the card expiry date and store it in card data and validate it */
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
/* ask for the card's Primary Account Number and store it in card data and validate it */
EN_cardError_t getCardPAN(ST_cardData_t* cardData);


#endif
