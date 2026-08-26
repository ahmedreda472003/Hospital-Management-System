#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Validation.h"
#include "Console.h"
using namespace std;
class Appointment
{

private:
	int appointmentId;               // رقم الموعد

	int patientId;                   // رقم المريض
	 
	int doctorId;                    // رقم الطبيب

	string date;                     // تاريخ الموعد

	string time;                     // وقت الموعد

	string status = "Scheduled";     // حالة الموعد (Scheduled / Completed / Cancelled)

	string paymentMethod;

	string paymentStatus = "Pending";

public:

	

	Appointment(int appointmentId, int patientId, int doctorId,
		const string& date, const string& time, const string& status , const string& paymentMethod , const string& paymentStatus = "Pending");



	bool setDate(const string& date);



	bool setTime(const string& time);


	bool setStatus(const string& status);


	bool setPaymentMethod(string method);



	void setPaymentStatus(string paymentStatus);


	string getPaymentStatus() const ;




	int getAppointmentId() const;


	int getPatientId() const;


	int getDoctorId() const;


	string getDate() const;


	string getTime() const;


	string getStatus() const;

	string getPaymentMethod()const;



	void display() const;


	static void printHeader();

};

