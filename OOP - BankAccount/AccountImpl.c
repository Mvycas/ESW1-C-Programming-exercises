#include "Account.h"
#include <stdlib.h>
#include <string.h>

typedef struct account_t {
	int accountNo;
	double creditLimit;
	double balance;
};

Account account_create(int accountNo, double creditLimit, double balance) {

	Account _newAccount = calloc(sizeof(Account), 1);
	
	if (NULL == _newAccount) return NULL;

	_newAccount->accountNo = accountNo;
	_newAccount->creditLimit = creditLimit;
	_newAccount->balance = balance;
	
	return _newAccount;
}
void account_destroy(Account self)
{
	if (NULL != self)
	{
		free(self);
	}
}
AccountStatus account_withdraw(Account self, double amount)
{
	if (self == NULL) return
		ACCOUNT_NOT_INSTANTIATED;
	else if (self->balance < amount) return OVER_MAX_CREDIT_LIMIT;
	else
	{
		self->balance -= amount;
		return OK;
	}
}
AccountStatus account_deposit(Account self, double amount)
{
	if (self == NULL) return
		ACCOUNT_NOT_INSTANTIATED;
	else
	{
		self->balance += amount;
		return OK;
	}
}
double getBalance(Account self) {
	return self->balance;
}
double getCreditLimit(Account self) {
	return self->creditLimit;
}
int getAccountNo(Account self) {
	return self->accountNo;
}
void destroyAccount(Account self) {
	if (self == NULL) free(self);
}
