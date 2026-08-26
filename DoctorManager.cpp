#include "DoctorManager.h"


     // Menus

     void DoctorManager::printDoctorMenu()
    {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "             DOCTOR MENU";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Appointments\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] Appointment Management\n\n";

        Console::white();
        cout << "Medical Records\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [2] Medical Records\n\n";

        Console::white();
        cout << "Account\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [3] My Account\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "⇦ [0] Logout\n\n";
        Console::lightGray();
        cout << "➜ Select an option: ";

    }

     void DoctorManager::printAppointmentManagementMenu()
    {

        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "      APPOINTMENT MANAGEMENT";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Appointments\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] View My Appointments\n\n";
        cout << "▸ [2] Update Appointment \n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "↩ [0] Back\n\n";
        Console::lightGray();
        cout << "➜ Select an option: ";


    }

     void DoctorManager::printMedicalRecordsMenu()
    {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "         MEDICAL RECORDS";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Patient Records\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] View Patient Medical Records\n\n";
        cout << "▸ [2] Add Medical Record\n\n";
        cout << "▸ [3] Update Patient Medical Record\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "↩ [0] Back\n\n";
        Console::lightGray();
        cout << "➜ Select an option: ";
    }


     void DoctorManager::printUpdateMedicalRecordMenu()
    {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "      UPDATE MEDICAL RECORD";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Medical Record Information\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] Update Diagnosis\n\n";
        cout << "▸ [2] Update Prescription\n\n";
        cout << "▸ [3] Update Notes\n\n";
        cout << "▸ [4] Update Status\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "↩ [0] Back\n\n";
        Console::lightGray();
        cout << "➜ Select an option: ";
    }



     // Authentication

     Doctor* DoctorManager::login(int id, string password) {


        auto& doctors = HospitalData::getDoctors();
        for (Doctor& d : doctors) {

            if (d.getId() == id && d.getPassword() == password) {

                return &d;

            }

        }
        return nullptr;


    }

     Doctor* DoctorManager::searchDoctor(int id) {

        auto& doctors = HospitalData::getDoctors();
        for (Doctor& d : doctors) {

            if (d.getId() == id) {

                return &d;

            }

        }
        return nullptr;

     }




     // Doctor Management

     void  DoctorManager::listDoctors() {

        auto& doctors = HospitalData::getDoctors();

        Doctor::printDoctorHeader();

        for (Doctor& d : doctors) {
            d.display();
        }
    }





     // Menu Options

     bool  DoctorManager::doctorOptions(Doctor* doctor) {


        if (doctor == nullptr) {
            return false;
        }

        printDoctorMenu();

        int choice;

        Console::white();
        cin >> choice;
        cin.ignore();
        Console::cyan();


        switch (choice) {

        case 1:
            doctorAppointmentOptions(doctor);
            break;


        case 2:
            while (doctorMedicalRecordOptions(doctor));
            break;


        case 3:
            while (doctorAccountOptions(doctor));
            break;


        case 0:
            return false;


        default:
            Console::error("Invalid option. Please choose a number from the menu.\n");
            break;
        }

        return true;

    }

     bool  DoctorManager::doctorAppointmentOptions(Doctor* doctor) {

        printAppointmentManagementMenu();

        int choice;

        Console::white();
        cin >> choice;
        cin.ignore();
        Console::cyan();


        switch (choice) {

        case 1:

            if (!AppointmentManager::viewAppointmentsByDoctor(doctor->getId())) {
                Console::error("No appointments found.\n");
            }

            break;

        case 2:

            doctorUpdateAppointmentOptions(doctor);


            break;

        case 0:
            return false;

        }

        return true;


    }

     bool  DoctorManager::doctorUpdateAppointmentOptions(Doctor* doctor)
    {


        int choice;

        int appointmentId = DataEntry::enterId("Appointment");

        Appointment* a = AppointmentManager::searchAppointment(appointmentId);

        if (a == nullptr)
        {
            Console::error("Appointment not found.\n");
            return true;
        }

        if (a->getDoctorId() != doctor->getId())
        {
            Console::error("You are not allowed to update this appointment.\n");
            return true;
        }
        bool updated = false;

        while (true) {

            AppointmentManager::printUpdateAppointmentMenu();


            Console::white();
            cin >> choice;
            cin.ignore();
            Console::cyan();
            switch (choice)
            {
            case 1:
                a->setDate(DataEntry::enterDateAppointment());
                updated = true;
                break;

            case 2:
                a->setTime(DataEntry::enterTimeAppointment());
                updated = true;
                break;

            case 3:
                a->setStatus(DataEntry::enterAppointmentStatus());
                updated = true;
                break;
            case 0:
                if (updated) {
                    FilesHelper::updateAppointments();
                    Console::success("Appointment updated successfully.\n");
                }
                return false;

            default:
                Console::error("Invalid option.\n");
                return true;
            }
        }

        return true;
    }

     bool  DoctorManager::doctorMedicalRecordOptions(Doctor* doctor) {

        printMedicalRecordsMenu();

        int choice;

        Console::white();
        cin >> choice;
        cin.ignore();
        Console::cyan();


        switch (choice) {

        case 1:
        {
            int patientId = DataEntry::enterId("Patient");
            Patient* p = PatientManager::searchPatient(patientId);

            if (p == nullptr)
            {
                Console::error("Patient not found.\n");
                break;
            }
            cout << "\n═════════════════════════════════════════\n";
            Console::white();
            cout << "      PATIENT MEDICAL RECORDS";
            Console::cyan();
            cout << "\n═════════════════════════════════════════\n\n";

            if (!MedicalRecordManager::viewMedicalRecordsPatient(patientId))
            {
                Console::error("No medical records found.\n");
            }
            break;
        }

        case 2:
        {
            cout << "\n═════════════════════════════════════════\n";
            Console::white();
            cout << "       ADD MEDICAL RECORD";
            Console::cyan();
            cout << "\n═════════════════════════════════════════\n\n";

            MedicalRecordManager::createMedicalRecord(doctor);
        }

        break;


        case 3:

            doctorUpdateMedicalRecordOptions(doctor);

            break;


        case 0:
            return false;

        default:

            Console::error("Invalid Choice. \n");

        }

        return true;

    }

     bool DoctorManager::doctorUpdateMedicalRecordOptions(Doctor* doctor)
    {

        int choice;

        int appointmentId = DataEntry::enterId("Appointment");

        MedicalRecord* m = MedicalRecordManager::searchMedicalRecord(appointmentId);

        if (m == nullptr)
        {
            Console::error("Medical record not found.\n");
            return true;
        }

        if (m->getDoctorId() != doctor->getId())
        {
            Console::error("You are not allowed to update this medical record.\n");
            return true;
        }
        bool updated = false;

        while (true) {

            printUpdateMedicalRecordMenu();
            Console::white();
            cin >> choice;
            cin.ignore();
            Console::cyan();
            switch (choice)
            {
            case 1:
                m->setDiagnosis(DataEntry::enterDiagnosisMedicalRecord());
                updated = true;
                break;

            case 2:
                m->setPrescription(DataEntry::enterPrescriptionMedicalRecord());
                updated = true;
                break;

            case 3:
                m->setNotes(DataEntry::enterNotesMedicalRecord());
                updated = true;
                break;

            case 4:
                m->setStatus(DataEntry::enterStatusMedicalRecord());
                updated = true;
                break;
            case 0:
                if (updated) {
                    FilesHelper::updateMedicalRecords();
                    Console::success("Medical record updated successfully.\n");
                }
                return false;

            default:
                Console::error("Invalid option.\n");
                return true;
            }
        }

        return true;
    }

     bool  DoctorManager::doctorAccountOptions(Doctor* doctor) {

        Menu::printAccountMenu();

        int choice;

        Console::white();
        cin >> choice;
        cin.ignore();
        Console::cyan();

        switch (choice) {

        case 0: return false;

        case 1:

            Doctor::printDoctorHeader();
            doctor->display();

            break;

        case 2:
            if (DataEntry::editInfo(doctor)) {

                FilesHelper::updateDoctors();

            }
            break;

        case 3:

            Console::cyan();
            cout << "\n═════════════════════════════════════════\n";
            Console::white();
            cout << "            ACCOUNT BALANCE";
            Console::cyan();
            cout << "\n═════════════════════════════════════════\n\n";

            Console::cyan();
            cout << "Account Number   : ";
            Console::white();
            cout << doctor->getAccount().getAccountNumber();

            Console::cyan();
            cout << "Current Balance: ";
            Console::white();
            cout << doctor->getAccount().getBalance();
            Console::cyan();
            cout << " EGP\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));

            break;

        case 4:
        {
            double amount = DataEntry::enterBalance();

            doctor->getAccount().deposit(amount);

            FilesHelper::updatePatients();

            Console::success("Deposit completed successfully.\n");

            Console::cyan();
            cout << "Amount Added    : ";

            Console::white();
            cout << amount;
            Console::cyan();
            cout << " EGP\n";

            cout << "Current Balance : ";
            Console::white();
            cout << doctor->getAccount().getBalance();
            Console::cyan();
            cout << " EGP\n\n";

            break;
        }
        default:

            Console::error("Invalid Choice. \n");

        }

        return true;

    }





