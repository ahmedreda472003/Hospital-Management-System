#include "AppointmentManager.h"

vector<Appointment> AppointmentManager::appointments;




     // Data

     void  AppointmentManager::addAppointment(const Appointment& appointment) {
        appointments.push_back(appointment);
    }

      vector<Appointment>& AppointmentManager::getAppointments() {

        return appointments;

      }



     // Search

     Appointment* AppointmentManager::searchAppointment(int appointmentId) {

        for (Appointment& a : appointments) {
            if (a.getAppointmentId() == appointmentId) {
                return &a;
            }
        }
        return nullptr;
    }




     // Booking & Update

     bool  AppointmentManager::updateAppointment(Appointment& appointment) {

        for (Appointment& ap : appointments) {
            if (ap.getAppointmentId() == appointment.getAppointmentId()) {
                ap = appointment;
                return true;
            }
        }
        return false;
    }

     bool  AppointmentManager::cancelAppointment(int appointmentId) {

        for (Appointment& ap : appointments) {
            if (ap.getAppointmentId() == appointmentId) {
                ap.setStatus("Cancelled");
                return true;
            }
        }
        return false;

    }




     // Payment

     bool AppointmentManager::processVisaPayment(Patient* patient, Doctor* doctor)
     {
         if (patient->getAccount().getBalance() < doctor->getConsultationFee())
         {
             Console::error("Insufficient balance.\n");
             return false;
         }

         double consultationFee = doctor->getConsultationFee();
         double doctorEntitlement = consultationFee * 0.30;

         BankAccount& hospitalAccount = HospitalData::getHospitalAccount();

         if (!patient->getAccount().transferTo(hospitalAccount, consultationFee))
         {
             Console::error("Payment failed.\n");
             return false;
         }

         FileManager::addFinancialEntitlement(doctor->getId() , doctorEntitlement);

         FilesHelper::saveHospitalAccount(hospitalAccount);
         FilesHelper::updatePatients();

         return true;
     }

     bool AppointmentManager::processRefund(Patient* patient, Appointment* appointment)
     {
         Doctor* doctor = DoctorManager::searchDoctor(appointment->getDoctorId());

         if (doctor == nullptr)
             return false;

         double amount = doctor->getConsultationFee();

         BankAccount hospitalAccount = FilesHelper::getHospitalAccount();

         if (!hospitalAccount.transferTo(patient->getAccount(), amount))
             return false;

         ManagerService::deductFinancialEntitlement(doctor->getId(), amount * 0.30);
         FilesHelper::updateFinancialEntitlements();

         FilesHelper::saveHospitalAccount(hospitalAccount);
         FilesHelper::updatePatients();

         Transaction transaction( hospitalAccount.getAccountNumber(),patient->getAccount().getAccountNumber(), amount ,"Refund" );

         FileManager::addTransaction(transaction);

         return true;
     }




     // Availability

     bool  AppointmentManager::isDoctorAvailable(int doctorId, const string& date, const string& time) {

        for (const Appointment& a : appointments) {

            if (a.getDoctorId() == doctorId &&
                a.getDate() == date &&
                a.getTime() == time &&
                a.getStatus() != "Cancelled")
            {
                Console::error("This doctor already has an appointment at the selected time.\n");
                return false;
            }
        }

        return true;
    }

     bool  AppointmentManager::isPatientAvailable(int patientId, const string& date, const string& time) {

        for (const Appointment& a : appointments) {

            if (a.getPatientId() == patientId &&
                a.getDate() == date &&
                a.getTime() == time &&
                a.getStatus() != "Cancelled")
            {
                Console::error("You already have another appointment at the selected date and time.\n");
                return false;
            }
        }

        return true;
    }




     // View

     bool  AppointmentManager::viewAppointment(int appointmentId) {
        Appointment::printHeader();
        for (Appointment& ap : appointments) {
            if (ap.getAppointmentId() == appointmentId) {
                ap.display();
                return true;
            }
        }
        return false;
    }

     void  AppointmentManager::viewAppointments() {
        Appointment::printHeader();
        for (Appointment& ap : appointments) {
            ap.display();
        }

    }

     bool  AppointmentManager::viewAppointmentsByDoctor(int doctorId) {

        bool found = false;

        const auto& appointments = AppointmentManager::getAppointments();
        Appointment::printHeader();
        for (const Appointment& a : appointments) {

            if (a.getDoctorId() == doctorId) {
                a.display();
                found = true;
            }
        }

        return found;
    }

     bool  AppointmentManager::viewAppointmentsByPatient(int patientId) {

        bool found = false;

        const auto& appointments = AppointmentManager::getAppointments();
        Appointment::printHeader();
        for (const Appointment& a : appointments) {

            if (a.getPatientId() == patientId) {
                a.display();
                found = true;
            }
        }

        return found;
     }




     // Menus

     void  AppointmentManager::printUpdateAppointmentMenu()
    {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "      UPDATE APPOINTMENT";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Appointment Information\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] Update Date\n\n";
        cout << "▸ [2] Update Time\n\n";
        cout << "▸ [3] Update Status\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        Console::red();
        cout << "↩ [0] Back\n\n";
        Console::lightGray();
        cout << "➜ Enter your choice: ";
    }




