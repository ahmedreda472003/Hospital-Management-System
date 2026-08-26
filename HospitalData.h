#pragma once
#include <vector>
#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Admin.h"
#include "Manager.h"
#include <unordered_map>
#include "Transaction.h"
using namespace std;
class HospitalData
{
private:

	static vector<Patient>  patients;

	static vector<Doctor>  doctors;

	static vector<Admin>  admins;

	static vector<Manager>  managers;

	static BankAccount hospitalAccount;

	static unordered_map<int, double>  financialEntitlements;

	static vector<Transaction>  transactions;



public:


	// Hospital Account

	static BankAccount& getHospitalAccount();

	static void addHospitalAccount(const BankAccount& account);





	// Users

	static void addPatient(const Patient& patient);

	static void addDoctor(const Doctor& doctor);

	static void addAdmin(const Admin& admin);

	static void addManager(const Manager& manager);



	// Financial

	static void addFinancialEntitlement(int doctorId, double amount);




	// Transactions

	static void addTransaction(const Transaction& transaction);




	// Getters

	static vector<Patient>& getPatients();

	static vector<Doctor>& getDoctors();

	static vector<Admin>& getAdmins();

	static vector<Manager>& getManager();

	static unordered_map<int, double>& getEntitlements();

	static vector<Transaction>& getTransactions();


};

