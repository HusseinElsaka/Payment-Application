#include "Card/Card.h"


int main()
{
	ST_cardData_t Test;
	ST_cardData_t* PTR_Test = &Test;
	
	if ((getCardHolderName(PTR_Test)) || (isCardExpired(PTR_Test)) || (getCardPAN(PTR_Test)))
	{	
		printf("WRONG Card Data \n");
		return 1;
	}
	printf("Vaild Card Data \n");
	return 0;

}