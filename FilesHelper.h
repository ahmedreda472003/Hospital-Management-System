#pragma once
#include "Parser.h"
#include "Files.h"
#include "HospitalData.h"
#include "MedicalRecordManager.h"
#include "AppointmentManager.h"
class FilesHelper
{
public:



    // IDs
    static void saveLast(string fileName, int id);

    static int getLast(string fileName);


    // Bank Accounts

    static BankAccount getHospitalAccount();

    static void saveHospitalAccount(const BankAccount& account);


    static void saveLastAccount(string fileName, string account);

    static string getLastAccount(string fileName);

    static string generateAccountNumber(string fileName);




    // Save
    static void savePatient(const Patient& p);

    static void saveDoctor(const Doctor& d);

    static void saveAdmin(const Admin& a);

    static void saveAppointment(const Appointment& a);

    static void saveMedicalRecord(const MedicalRecord& m);

    static void saveTransaction(const Transaction& t);

    static void saveFinancialEntitlement(int doctorId, double amount);


    // Load

    static void fetchPatients();

    static void fetchDoctors();

    static void fetchAdmins();

    static void fetchManagers();

    static void fetchAppointments();

    static void fetchMedicalRecord();

    static void fetchTransactions();

    static void fetchFinancialEntitlements();


    // Add

    static void addPatient(const Patient& p);

    static void addDoctor(const Doctor& d);

    static void addAdmin(const Admin& a);

    static void addAppointment(const Appointment& a);

    static void addMedicalRecord(const MedicalRecord& m);



    // Utilities

    static void clearFile(string fileName);

    // Remove

    static void removeAllPatients();

    static void removeAllDoctors();

    static void removeAllAdmins();

    static void removeAllAppointments();

    static void removeAllMedicalRecords();

    static void removeAllFinancialEntitlements();

    static void removeAllTransactions();


    // Update

    static void updatePatients();

    static void updateDoctors();

    static void updateAdmins();

    static void updateAppointments();

    static void updateMedicalRecords();

    static void updateFinancialEntitlements();

    static void updateTransactions();




};

