#include "FileManager.h"




     // Initialization

	 void FileManager::fetchAllData()
	 {
		 FilesHelper::fetchPatients();
		 FilesHelper::fetchDoctors();
		 FilesHelper::fetchAdmins();
		 FilesHelper::fetchManagers();
		 FilesHelper::fetchAppointments();
		 FilesHelper::fetchMedicalRecord();
		 FilesHelper::fetchFinancialEntitlements();
		 HospitalData::addHospitalAccount(FilesHelper::getHospitalAccount());
		 FilesHelper::fetchTransactions();

	 }





	 // Add Data

	 void FileManager::addPatient(const Patient& patient) {

		 HospitalData::addPatient(patient);
		 FilesHelper::savePatient(patient);
		 

	 }

	 void FileManager::addDoctor(const Doctor& doctor) {

		 HospitalData::addDoctor(doctor);
		 FilesHelper::saveDoctor(doctor);

	 }

	 void FileManager::addAdmin(const Admin& admin) {

		 HospitalData::addAdmin(admin);
		 FilesHelper::saveAdmin(admin);

	 }

	 void FileManager::addAppointment(const Appointment& appointment) {

		 AppointmentManager::addAppointment(appointment);
		 FilesHelper::saveAppointment(appointment);

	 }

	 void FileManager::addMedicalRecord(const MedicalRecord& medicalRecord) {

		MedicalRecordManager::addMedicalRecord(medicalRecord);
		FilesHelper::saveMedicalRecord(medicalRecord);

	}

	 void FileManager::addTransaction(const Transaction& transaction) {

		 HospitalData::addTransaction(transaction);
		 FilesHelper::saveTransaction(transaction);


	 }



	 // Financial

	 void FileManager::addFinancialEntitlement(int doctorId, double amount)
	 {
		 auto& entitlements = HospitalData::getEntitlements();

		 entitlements[doctorId] += amount;

		FilesHelper::updateFinancialEntitlements();
	 }