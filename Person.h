#pragma once
#include <chrono>
#include <iomanip>
#include "Validation.h"
#include "Console.h"
#include "BankAccount.h"
class Person
{
protected:
	string name , password;
	int id; 
	BankAccount account;
public:
	Person(int id,const string& name,const string& password ,const BankAccount& account);


	bool setName(const string& name);


	bool setPassword(const string& password);


	string getName() const;


	string getPassword() const;


	BankAccount& getAccount();

	const BankAccount& getAccount()const ;


	virtual int getId() const;


	virtual void display() const = 0;

	
};

