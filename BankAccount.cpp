#include "BankAccount.h"



    BankAccount::BankAccount(const string& accountNumber, double balance)
		: accountNumber(accountNumber)
	{
		if (balance < 0)
			throw invalid_argument("Balance cannot be negative.");

		this->balance = balance;
	}

	bool BankAccount::deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			return true;
		}
		return false;
	}

	bool BankAccount::transferTo(BankAccount& account, double amount) {

		if (amount <= balance && amount > 0) {

			account.deposit(amount);
			balance -= amount;
			return true;

		}

		return false;

	}

	void BankAccount::setAccountNumber(string accountNumber) {
		this->accountNumber = accountNumber;
	}

	void BankAccount::setBalance(double balance) {
		this->balance = balance;
	}



	double BankAccount::getBalance() const {
		return  balance;
	}


	string BankAccount::getAccountNumber() const {
		return  accountNumber;
	}



