#pragma once
#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Admin.h"
#include "MedicalRecord.h"
#include "Appointment.h"
#include <fstream>
#include <iostream>
#include "Manager.h"
#include "Transaction.h"
using namespace std;
class Parser{
public:


    // Utility

    static vector<string> split(string line, char delimiter);


    // Accounts

    static BankAccount parseToHospitalAccount(string line);


    // Users

    static Patient parseToPatient(string line);

    static Doctor parseToDoctor(string line);

    static Admin parseToAdmin(string line);

    static Manager parseToManager(string line);



    // Appointments

    static Appointment parseToAppointment(string line);




    // Medical Records

    static MedicalRecord parseToMedicalRecord(string line);



    // Transactions

    static Transaction parseToTransaction(string line);



    // Financial

    static pair<int, double> parseToFinancialEntitlement(string line);

};

