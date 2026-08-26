#pragma once
#include "FileManager.h"
#include "FilesHelper.h"
#include "HospitalData.h"
#include "AppointmentManager.h"
#include "PatientManager.h"
class DoctorManager
{
public:


    // Menus

    static void printDoctorMenu();

    static void printAppointmentManagementMenu();

    static void printMedicalRecordsMenu();

    static void printUpdateMedicalRecordMenu();



    // Authentication

    static Doctor* login(int id, string password);

    static Doctor* searchDoctor(int id);



    // Doctor Management

    static void listDoctors();





    // Menu Options

    static bool doctorOptions(Doctor* doctor);

    static bool doctorAppointmentOptions(Doctor* doctor);

    static bool doctorUpdateAppointmentOptions(Doctor* doctor);

    static bool doctorMedicalRecordOptions(Doctor* doctor);

    static bool doctorUpdateMedicalRecordOptions(Doctor* doctor);

    static bool doctorAccountOptions(Doctor* doctor);


};

