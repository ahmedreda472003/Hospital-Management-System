#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
using namespace std;
class Validation
{
public:

	static bool validName(const string& name);


	static bool validPassword(const string& password);


	static bool validPhone(const string& phone);


	static bool validSalary(double salary, double  minimum );

	//  Appointment 

	static bool validTime(const string& time);


	static bool validDate(const string& date);


	static bool validStatusAppointment(const string& status);


	// MedicalRecord
	static bool validStatusMedicalRecord(const string& status);


	static string inputPassword();



};

