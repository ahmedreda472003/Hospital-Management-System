#pragma once
#include "Person.h"
class Manager : public Person
{

public:

	Manager(int id, string& name, string& password, BankAccount& account);
		





	void display() const;


	static void printManagerHeader();


};

