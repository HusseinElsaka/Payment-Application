
#include "Server/Server.h"

/* Using this website https://www.dcode.fr/luhn-algorithm to generate Luhn Numbers */



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

	/*Terminal Data Test 
	if (getTransactionDate(PTR_TestTerminal) || ||setMaxAmount(PTR_TestTerminal) ||  getTransactionAmount(PTR_TestTerminal) || isBelowMaxAmount(PTR_TestTerminal) ||  isValidCardPAN(PTR_TestCard))
	{
		printf("Wrong in  Terminal\n");
			return 1;
	}
	*/
	
	printf("Valid Card");
	
	return 0;
}