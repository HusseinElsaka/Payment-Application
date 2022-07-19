#include "Terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("Enter Transaction Date : ");
	gets(termData->transactionDate);
<<<<<<< Updated upstream
	int month = ((int)termData->transactionDate[3] - '0') * 10 + ((int)termData->transactionDate[4] - '0');
	int day = ((int)termData->transactionDate[0] - '0') * 10 + ((int)termData->transactionDate[1] - '0');
=======
>>>>>>> Stashed changes
	if (strlen(termData->transactionDate) != TRANSACTION_LEN)
	{
		return WRONG_DATE;
	}
<<<<<<< Updated upstream
	else if (checkDay(day) || checkMonth(month))
=======
	else if (checkDay(day) != '/' && termData->transactionDate[5] != '/')
>>>>>>> Stashed changes
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
	scanf_s("%f", &termData->transAmount);
	if (termData->transAmount <= 0)
	{
		return INVALID_AMOUNT;
	}
	return OK_TERMINAL;
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{
	int lengthPAN = strlen(cardData->primaryAccountNumber), i;
	/* Check if there are all digits to apply luhn 
	Luhn algorithms apply to digit
	-- we assume if it had a letter it valid
	-- if all digits we apply it check if it valid or not
	*/ 
	
	for (i = 0; i < lengthPAN; i++)
	{
		if (cardData->primaryAccountNumber[i] <= '0' || cardData->primaryAccountNumber[i] >= '9')
		{
			return OK_TERMINAL;
		}
	}
	/*Luhn Algorithm */
	long digitPosition = 1, sum = 0, x = lengthPAN;
	while (x > 0)
	{
		//check even numbers and double it if odd let it
		if (digitPosition % 2 == 0)
		{
			// CHECK IF THE DOUBLE EVEN GREATER THAN 10 
			int y = (2 * (x % 10));
			if (y > 9)
			{
				sum += ((y % 10) + 1);
			}
			else
			{
				sum += (2 * (x % 10));
			}
			x /= 10;
		}
		else
		{
			sum += (x % 10);
			x /= 10;
		}
		digitPosition++;
	}
	if (sum % 10 == 0)
	{
		return OK_TERMINAL;
	}
	return INVALID_CARD;
}




EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		return EXCEED_MAX_AMOUNT;
	}
	return OK_TERMINAL;
}


EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	printf("Enter MAX amount : \n");
	scanf_s("%f", &termData->maxTransAmount);
	if (termData->maxTransAmount <= 0)
	{
		return INVALID_MAX_AMOUNT;
	}
	return OK_TERMINAL;
}