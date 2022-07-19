#include "Card.h"




DateError checkDay(int day)
{
	if (day > 30 || day < 1)
	{
		return WRONG_DAY;
	}
	return OK_DATE;
}

DateError checkMonth(int month)
{
	if (month > 12 || month < 1)
	{
		return WRONG_MONTH;
	}
	return OK_DATE;
}
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
	int month = ((cardData->cardExpirationDate[0] - '0') * 10 + (cardData->cardExpirationDate[1] - '0'));
	if (strlen(cardData->cardExpirationDate) != EXPIRE_LEN)
	{
		return WRONG_EXP_DATE;
	}
	else if (checkMonth(month))
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
	int lengthPAN = strlen(cardData->primaryAccountNumber), i;
	if ((lengthPAN > CARD_MAX) || (lengthPAN < CARD_MIN))
	{
		return WRONG_PAN;
	}
	
	for (i = 0; i < lengthPAN; i++)
	{
		if (!((cardData->primaryAccountNumber[i] >= 'A' && cardData->primaryAccountNumber[i] <= 'Z') || (cardData->primaryAccountNumber[i] >= 'a' && cardData->primaryAccountNumber[i] <= 'z') || (cardData->primaryAccountNumber[i] >= '0' && cardData->primaryAccountNumber[i] <= '9')))
		{
			return WRONG_PAN;
		}
	}
	return OK_CARD;

}


