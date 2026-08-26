#pragma once
#include <iostream>
using namespace std;
class BankAccount
{

private:
	string accountNumber;
	double balance;

public:

	
		
	BankAccount(const string& accountNumber, double balance);

	bool deposit(double amount);

	bool transferTo(BankAccount& account, double amount);


	void setAccountNumber(string accountNumber);

	void setBalance(double balance);

	double getBalance() const;


	string getAccountNumber() const;

};

