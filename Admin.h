#pragma once
#include "Doctor.h"
class Admin : public Person 
{
private:
	
	double salary;
	

public:


	Admin(int id, string& name, string& password, double salary , BankAccount& account);
			
	
	void setSalary(double salary);

	
	double getSalary()const;


	void display() const;


	static void printAdminHeader();


};

