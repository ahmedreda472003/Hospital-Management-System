#include "HospitalData.h"

vector<Patient> HospitalData::patients;

vector<Doctor> HospitalData::doctors;

vector<Admin> HospitalData::admins;

vector<Manager> HospitalData::managers;


unordered_map<int, double>  HospitalData::financialEntitlements;


BankAccount HospitalData::hospitalAccount("HOS", 0);

vector<Transaction> HospitalData::transactions;




     // Hospital Account

     BankAccount& HospitalData::getHospitalAccount()
     {
    	return hospitalAccount;
     }
       
	 void HospitalData::addHospitalAccount(const BankAccount& account)
	 {
		 hospitalAccount = account;
	 }




	 // Users

	 void HospitalData::addPatient(const Patient& patient) {

		 patients.push_back(patient);

	 }


	 void HospitalData::addDoctor(const Doctor& doctor) {

		 doctors.push_back(doctor);

	 }


	 void HospitalData::addAdmin(const Admin& admin) {

		 admins.push_back(admin);

	 }


	 void HospitalData::addManager(const Manager& manager) {

		 managers.push_back(manager);

	 }




	 // Financial

	 void HospitalData::addFinancialEntitlement(int doctorId, double amount)
	 {
		 financialEntitlements[doctorId] = amount;
	 }





	 // Transactions

	 void HospitalData::addTransaction(const Transaction& transaction) {

		 transactions.push_back(transaction);

	  }






	 // Getters

	 vector<Patient>& HospitalData::getPatients() {

		 return patients;

	 }

	 vector<Doctor>& HospitalData::getDoctors() {

		 return doctors;

	 }

	 vector<Admin>& HospitalData::getAdmins() {

		return admins;

	}

	 vector<Manager>& HospitalData::getManager() {

		 return managers;

	 }

	 unordered_map<int, double>& HospitalData::getEntitlements() {

		 return financialEntitlements;

	 }

	 vector<Transaction>& HospitalData::getTransactions()
	 {
		 return transactions;
	 }
