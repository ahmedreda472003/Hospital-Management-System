#pragma once
#include <vector>
#include "Appointment.h"
#include "DataEntry.h"
#include "Files.h" 
#include "Patient.h"
#include "Doctor.h"
#include "FilesHelper.h"
#include "FileManager.h"
#include "ManagerService.h"
class AppointmentManager
{
private:

    static vector<Appointment> appointments;

public:

   

    // Data

    static void addAppointment(const Appointment& appointment);

    static vector<Appointment>& getAppointments();


    // Search

    static Appointment* searchAppointment(int appointmentId);


    // Booking & Update

    static bool updateAppointment(Appointment& appointment);

    static bool cancelAppointment(int appointmentId);


    // Payment

    static bool processVisaPayment(Patient* patient, Doctor* doctor);

    static bool processRefund(Patient* patient, Appointment* appointment);


    // Availability

    static bool isDoctorAvailable(int doctorId, const string& date, const string& time);

    static bool isPatientAvailable(int patientId, const string& date, const string& time);


    // View
    static bool viewAppointment(int appointmentId);

    static void viewAppointments();

    static bool viewAppointmentsByDoctor(int doctorId);

    static bool viewAppointmentsByPatient(int patientId);


    // Menus

    static void printUpdateAppointmentMenu();


};

