#include "Patient.h"




    Patient::Patient(int id, string& name, string& password, string& phone , BankAccount& account)
		: Person(id, name, password , account)
	{
		setPhone(phone);
	}



	bool Patient::setPhone(const string& phone) {

		if (Validation::validPhone(phone)) {
			this->phone = phone;
			return true;

		}
		return false;

	}



	string Patient::getPhone() const {
		return phone;
	}



	void Patient::display() const {
		Console::white();
		cout << left
			<< setw(8) << id
			<< setw(20) << name
			<< setw(15) << phone
			<< setw(20) << getAccount().getAccountNumber()
			<< '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));
		Console::cyan();
	}



	void Patient::printPatientHeader() {

		Console::white();
		cout << endl << left
			<< setw(8) << "ID"
			<< setw(20) << "Name"
			<< setw(15) << "Phone"
			<< setw(20) << "Account Number"
			<< '\n';
		Console::cyan();
		cout << string(57, '-') << '\n';

	}




