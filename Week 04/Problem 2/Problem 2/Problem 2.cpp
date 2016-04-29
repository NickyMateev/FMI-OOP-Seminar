// Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

const int NAME_LENGTH = 24;
const int ACCOUNT_LENGTH = 16;


class BankAccount
{
	char name[NAME_LENGTH];
	char accNum[ACCOUNT_LENGTH];
	double balance;
public:
	BankAccount();
	BankAccount(const char*, const char*, const double);
	double getBalance();
	void setBalance(double balanceGiven);
	void Withdraw(double amount);
	void Deposit(double amount);

	void setName(char* name);
	const char* getName() const;
};

BankAccount::BankAccount() { }

BankAccount::BankAccount(const char* n, const char* an, const double b)
{
	strcpy_s(name, n);
	strcpy_s(accNum, an);
	balance = b;
}

void BankAccount::setName(char* arr)
{
	strcpy_s(name, arr);
}

const char* BankAccount::getName() const
{
	return name;
}

double BankAccount::getBalance()
{
	return balance;
}

void BankAccount::setBalance(double newBalance)
{
	balance = newBalance;
}

void BankAccount::Withdraw(double amount)
{
	if (amount > balance)
		cout << "Not enough money!" << endl;
	else
	{
		balance -= amount;
		cout << "Successful withdraw! Your new balance is: " << balance << endl;
	}
}

void BankAccount::Deposit(double amount)
{
	balance += amount;
	cout << "Successful deposit operation! Your new balance is: " << balance << endl;
}

BankAccount* InitBankAccount()
{
	char name[NAME_LENGTH], accountNumber[ACCOUNT_LENGTH];
	double balance;

	cout << "Bank Account information:" << endl;
	cout << "Name: ";
	cin >> name;
	cout << "Account number: ";
	cin >> accountNumber;
	cout << "Balance: ";
	cin >> balance;
	
	BankAccount bankAccount(name, accountNumber, balance);
	return &bankAccount;
}

void BankAccountFunction(BankAccount& bankAccount)
{
	bankAccount = *(InitBankAccount());
	cout << "----------" << endl;
	cout << "Entered balance: " << bankAccount.getBalance() << endl;
	cout << "----------" << endl;

	double amount;
	cout << "Enter amount to withdraw: ";
	cin >> amount;
	bankAccount.Withdraw(amount);
	cout << "----------" << endl;
	cout << "Enter amount to deposit: ";
	cin >> amount;
	bankAccount.Deposit(amount);
}

int main()
{
	BankAccount ba;
	BankAccountFunction(ba);

    return 0;
}