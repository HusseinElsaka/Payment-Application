#include "Server.h"

extern ST_accountsDB_t serverDatabase[MAX_SERVER] = {
	{5000.0, "607833656635906773"},
	{4000.5, "005768153188661175"},
	{3000.2, "075982963293069095"},
	{2000.12, "611153338528212031"},
	{1000.334, "910398034808780349"},
	{1002.4, "053325461606192194"},
	{999.2, "742772749714646812"},
	{324.2, "209325396074423440"},
	{1231.4, "851079961065873585"},
	{1253.4, "442875351414250640"},
	{5123.5, "615903891876676888"},
	{6345.1, "59022961351481653"},
	{6345.6, "91119474574056192"},
	{1241.7, "89928622813608190"},
	{4761.3, "78687103102360615"},
	{125.7, "8316351323704972"},
	{214.6, "5006447651585560"},
	{1251.3, "3870771107430131"},
	{151.6, "0354025546355735"}
};


extern ST_transaction_t transactionDatabase[MAX_TRANSACTION] = { 0 };



int searchAccount(ST_cardData_t* cardData)
{
	for (int i = 0; i < MAX_SERVER; i++)
	{
		if (strcmp(cardData->primaryAccountNumber, serverDatabase[i].primaryAccountNumber) == 0)
		{
			return i;
		}
	}
	return -1;
}


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	
	


}
EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	if (!(getCardHolderName(cardData) || getCardExpiryDate(cardData) || getCardPAN(cardData) || isValidCardPAN(cardData)))
	{
		int temp = searchAccount(cardData);
		if (temp == -1)
		{
			return DECLINED_STOLEN_CARD;
		}
		else
		{
			return OK;
		}
	}
	return DECLINED_STOLEN_CARD;
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	getTransactionDate(termData);
	getTransactionAmount(termData);
	isCardExpired( cardData, *termData);
	
	isBelowMaxAmount(termData);
}
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{

}
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{

}