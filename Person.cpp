#include "Person.h"




    Person::Person(int id, const string& name, const string& password, const BankAccount& account) : id(id) , account(account){
		setName(name);
		setPassword(password);
	}



	bool Person::setName(const string& name) {

		if (Validation::validName(name)) {
			this->name = name;
			return true;
		}
		return false;

	}



	bool Person::setPassword(const string& password) {

		if (Validation::validPassword(password)) {
			this->password = password;
			return true;

		}
		return false;

	}



	string Person::getName() const {
		return name;
	}



	string Person::getPassword() const {
		return password;
	}


	BankAccount& Person::getAccount() {
		return account;
	}


	const BankAccount& Person::getAccount() const  {
		return account;
	}

	 int Person::getId() const {
		return id;
	 }

	 


