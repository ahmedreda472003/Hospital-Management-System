#pragma once
#include <vector>
#include "MedicalRecord.h"
#include "AppointmentManager.h"
using namespace std;
class MedicalRecordManager
{

private:

    static vector<MedicalRecord> records;

public:


    // Data

    static void addMedicalRecord(const MedicalRecord& record);

    static vector<MedicalRecord>& getMedicalRecords();


    // Search

    static MedicalRecord* searchMedicalRecord(int appointmentId);


    // Medical Record Management

    static void createMedicalRecord(Doctor* doctor);

    static bool deleteRecord(int appointmentId);


    // View

    static void viewRecord(int appointmentId);

    static void viewRecords();

    static bool listMedicalRecordsByDoctor(int doctorId);

    static bool listMedicalRecordsByPatient(int patientId);

    static bool viewMedicalRecordsPatient(int patientId);

    


};

