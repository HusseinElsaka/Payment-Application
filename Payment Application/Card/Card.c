#include "Card.h"




EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("Enter the CardHolder's name : \n");
	gets(cardData->cardHolderName);
	if ((strlen(cardData->cardHolderName) > NAME_MAX) || (strlen(cardData->cardHolderName) < NAME_MIN))
	{
		return WRONG_NAME;
	}
	return OK_CARD;
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	// Input is in format MM/YY
	printf("Enter the Card Expiry date : \n");
	gets(cardData->cardExpirationDate);
	if (strlen(cardData->cardExpirationDate) != EXPIRE_LEN)
	{
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[0] != '0' && cardData->cardExpirationDate[0] != '1')
	{
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[2] != '/')
	{
		return WRONG_EXP_DATE;
	}
	return OK_CARD;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("Enter Primary Account Number : \n");
	gets(cardData->primaryAccountNumber);
	if ((strlen(cardData->primaryAccountNumber) > CARD_MAX) || (strlen(cardData->primaryAccountNumber) < CARD_MIN))
	{
		return WRONG_PAN;
	}
	return OK_CARD;

}