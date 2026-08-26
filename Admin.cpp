#include "Admin.h"



    Admin::Admin(int id, string& name, string& password, double salary , BankAccount& account)
		: Person(id, name, password, account), salary(salary) {
	}



	void Admin::setSalary(double salary) {

		if (Validation::validSalary(salary , 7000)) {
			this->salary = salary;
		}

	}




	double Admin::getSalary()const {
		return salary;
	}




	void Admin::display() const {
		Console::white();
		cout << left
			<< setw(8) << id
			<< setw(17) << name
			<< '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));
		Console::cyan();
	}



	void Admin::printAdminHeader() {
		Console::white();
		cout << endl << left
			<< setw(8) << "ID"
			<< setw(17) << "Name"
			<< '\n';

		Console::cyan();
		cout << string(22, '-') << '\n';

	}




