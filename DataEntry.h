#pragma once
#include"Person.h"
#include"Console.h"
#include "Validation.h"
class DataEntry
{
public:
	 

	// User

	static string enterName();


	static string enterPassword();


	static double enterSalary();


	static string enterPhone();


	static string enterSpecialization();


	static double enterBalance();


	static double enterConsultationFee();
     

	static double enterEntitlementAmount();


	// Appointment

	static string enterDateAppointment();


	static string enterTimeAppointment();



	static string enterAppointmentStatus();



	// MedicalRecord

	static string enterDiagnosisMedicalRecord();


	static string enterPrescriptionMedicalRecord();


	static string enterNotesMedicalRecord();


	static string enterStatusMedicalRecord();



	// change

	static bool changePassword(Person* person);



	static bool changeName(Person* person);



	static bool editInfo(Person* person);



	// id

	static int enterId(const string& title);

};

