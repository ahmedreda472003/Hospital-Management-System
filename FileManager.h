#pragma once
#include "AppointmentManager.h"
#include "MedicalRecordManager.h"
#include "FilesHelper.h"
class FileManager
{
public:


    // Initialization

    static void fetchAllData();


    // Add Data

    static void addPatient(const Patient& patient);

    static void addDoctor(const Doctor& doctor);

    static void addAdmin(const Admin& admin);

    static void addAppointment(const Appointment& appointment);

    static void addMedicalRecord(const MedicalRecord& medicalRecord);

    static void addTransaction(const Transaction& transaction);


    // Financial

    static void addFinancialEntitlement(int doctorId, double amount);




};

