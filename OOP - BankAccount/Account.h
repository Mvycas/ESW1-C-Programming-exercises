#pragma once
#include "AccountStatus.h"
#include <stdbool.h>

typedef struct account_t* Account;

Account account_create(int accountNo, double creditLimit, double balance);
AccountStatus account_withdraw(Account self, double amount);
AccountStatus account_deposit(Account self, double amount);
double getBalance(Account self);
double getCreditLimit(Account self);
int getAccountNo(Account self);
void destroyAccount(Account self);