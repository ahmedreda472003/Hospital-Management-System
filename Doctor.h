#pragma once
#include "Person.h"
class Doctor : public Person
{
protected:

	string specialization;
	double salary;
	double consultationFee;

public:

	Doctor(int id,const string& name,const string& password,const string& specialization, double salary ,const BankAccount& account , double& consultationFee);
		

	void setSalary(double salary);


	void setSpecialization(const string& specialization);


	void setSpecialization(const double& consultationFee);


	double getSalary()const;



	string getSpecialization()const;


	double getConsultationFee()const;

	void display() const;


	static void printDoctorHeader();



};

