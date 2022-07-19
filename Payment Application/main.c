#include "Card/Card.h"
#include "Terminal/Terminal.h"

int main()
{
	ST_cardData_t TestCard;
	ST_cardData_t *PTR_TestCard = &TestCard;
	ST_terminalData_t TestTerminal;
	ST_terminalData_t *PTR_TestTerminal = &TestTerminal;
	/* CARD Data Test 
	if ((getCardHolderName(PTR_TestCard)) || (getCardExpiryDate(PTR_TestCard)) || (getCardPAN(PTR_TestCard)))
	{	
		printf("WRONG Card Data \n");
		return 1;
	}
	printf("Vaild Card Data \n");
	return 0;*/
	/*Terminal Data Test */
	if (getTransactionDate(PTR_TestTerminal))
	{
		printf("Invalid Transaction Date\n");
		return 1;
	}
	printf("Valid Transaction Date \n");
	
	

	return 0;
}