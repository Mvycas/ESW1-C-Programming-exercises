#include "Account.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	Account customerAccounts[10];
	
	int i = 0;

	while (i < 10)
	{
		//Creating accounts. Random function is used to set accountNo, credit, and balance
		customerAccounts[i] = account_create(i + rand(), rand(), rand());

		printf("Account nr: %d, Credit limit: %0.1f, Balance: %0.1f \n", getAccountNo(customerAccounts[i]), 
			getCreditLimit(customerAccounts[i]), getBalance(customerAccounts[i]));

		i++;
	}

	destroyAccount(customerAccounts);
	return 0;
}