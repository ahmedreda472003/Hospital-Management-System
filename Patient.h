#pragma once
#include "Person.h"
#include "Console.h"
class Patient : public Person
{
private:
	string phone;  
	
public:


	Patient(int id, string& name, string& password, string& phone , BankAccount& account);


	bool setPhone(const string& phone);


	string getPhone() const;


	void display() const;



	static void printPatientHeader();

	

};

