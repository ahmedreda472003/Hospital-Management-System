#pragma once
#include "FileManager.h"
#include "FilesHelper.h"
#include "HospitalData.h"
#include "AppointmentManager.h"
#include "Menu.h"
class PatientManager
{
public:

    // Menus

    static void printPatientMenu();

    static void printPatientAppointmentsMenu();

    static void printPatientMedicalRecordsMenu();


    // Authentication

    static Patient* login(int id, const string& password);


    // Patient Management

    static Patient* searchPatient(int id);

    static void listPatients();


    // Appointments

    static void bookAppointment(Patient* patient);


    // Menu Options

    static bool patientOptions(Patient* patient);

    static bool patientAppointmentOptions(Patient* patient);

    static bool patientMedicalRecordOptions(Patient* patient);

    static bool patientAccountOptions(Patient* patient);



};

