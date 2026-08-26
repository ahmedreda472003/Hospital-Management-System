#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Validation.h"
#include "Console.h"
using namespace std;
class MedicalRecord
{
private:

    int appointmentId;             // رقم الموعد

    int patientId;                 // رقم المريض

    int doctorId;                 // رقم الطبيب

    string diagnosis;             // تشخيص الحالة

    string prescription;          // العلاج أو الروشتة

    string notes;                 // ملاحظات إضافية

    string status = "Active";     // حالة السجل (Active / Archived)

public:


    MedicalRecord(int appointmentId, int patientId, int doctorId,
        const string& diagnosis, const string& prescription, const string& notes, const string& status);


    bool setDiagnosis(const string& diagnosis);

    bool setPrescription(const string& prescription);

    bool setNotes(const string& notes);

    bool setStatus(const string& status);


    int getAppointmentId() const;

    int getPatientId() const;

    int getDoctorId() const;

    string getDiagnosis() const;

    string getPrescription() const;

    string getNotes() const;

    string getStatus() const;


    void display() const;
  
    static void printHeader();


};

