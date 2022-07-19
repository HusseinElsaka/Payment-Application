#include "Terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("Enter Transaction Date : ");
	gets(termData->transactionDate);
	if (strlen(termData->transactionDate) != 10)
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[2] != '/' && termData->transactionDate[5] != '/')
	{
		return WRONG_DATE;
	}
	return OK_TERMINAL;
}


EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	int MonthExp = (cardData.cardExpirationDate[0] - '0') * 10 + (cardData.cardExpirationDate[1] - '0');
	int MonthNow = (termData.transactionDate[3] - '0') * 10 + (termData.transactionDate[4] - '0');
	int YearExp = (cardData.cardExpirationDate[3] - '0') * 10 + (cardData.cardExpirationDate[4] - '0');
	int YearNow = (termData.transactionDate[8] - '0') * 10 + (termData.transactionDate[9] - '0');
	if (YearExp < YearNow)
	{
		return EXPIRED_CARD;
	}
	else
	{
		if (YearExp == YearNow)
		{
			if (MonthExp < MonthNow)
			{
				return EXPIRED_CARD;
			}
			else
			{
				return OK_TERMINAL;
			}
		}
		else
		{
			return OK_TERMINAL;
		}
	}
}




EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("Enter transaction amount : \n");
	scanf_s("%f", termData->transAmount);
	if (termData->transAmount <= 0)
	{
		return INVALID_AMOUNT;
	}
	return OK_TERMINAL;
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{

}




EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{

}


EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{

}