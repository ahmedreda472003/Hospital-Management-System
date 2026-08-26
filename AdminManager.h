#pragma once
#include "PatientManager.h"
#include "DoctorManager.h"
#include "BankAccount.h"
#include "PaymentManager.h"
class AdminManager
{
private:

	static void removeDoctor();
	static void removePatient();
public:


	// Menus

	static void printAdminMenu();

	static void printPatientManagementMenu();

	static void printUpdatePatientMenu();

	static void printDoctorManagementMenu();

	static void printUpdateDoctorMenu();

	static void printAdminAppointmentManagementMenu();



	static void printPaymentManagementMenu();


	// Authentication

	static Admin* login(int id, string password);

	static Admin* searchAdmin(int id);



	// Admin Management

	static void listAdmins();



	// Patient Management

	static void addPatient(Admin* admin);

	static bool deletePatient(int id);



	// Doctor Management

	static void addDoctor(Admin* admin);

	static bool  deleteDoctor(int id);

	



	// Menu Options

	static bool adminOptions(Admin* admin);

	static bool patientManagementOptions(Admin* admin);

	static bool doctorManagementOptions(Admin* admin);

	static bool appointmentManagementOptions(Admin* admin);

	static bool updatePatientOptions();

	static bool updateDoctorOptions();

	static bool updateAppointmentOptions();

	static bool AdminAccountOptions(Admin* admin);



	static bool  PaymentManagementOptions(Admin* admin);


};

