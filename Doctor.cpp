#include "Doctor.h"





    Doctor::Doctor(int id, const string& name, const string& password, const string& specialization, double salary, const BankAccount& account, double& consultationFee)
		: Person(id, name, password , account), specialization(specialization) , consultationFee(consultationFee)
	{
		setSalary(salary);
	}



	void Doctor::setSalary(double salary) {

		if (Validation::validSalary(salary,7000)) {
			this->salary = salary;
		}

	}


	void  Doctor::setSpecialization(const double& consultationFee) {

		this->consultationFee = consultationFee;

	}


	void Doctor::setSpecialization(const string& specialization) {

		this->specialization = specialization;

	}


	double Doctor::getSalary()const {
		return salary;
	}



	string Doctor::getSpecialization()const {
		return specialization;
	}


	double Doctor::getConsultationFee()const {

		return consultationFee;

	}


	void Doctor::display() const
	{
		Console::white();
		cout << left
			<< setw(8) << id
			<< setw(18) << name
			<< setw(20) << specialization
			<< setw(15) << consultationFee
			<< '\n';

		std::this_thread::sleep_for(std::chrono::seconds(1));
		Console::cyan();
	}



	void Doctor::printDoctorHeader() {
		Console::white();
		cout << left
			<< setw(8) << "ID"
			<< setw(18) << "Name"
			<< setw(20) << "Specialization"
			<< setw(15) <<  "Fee (EGP)"
			<< '\n';
		Console::cyan();
		cout << string(60, '-') << '\n';
	}




