#include "AdminManager.h"

   // menus

     void AdminManager::printAdminMenu()
    {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "             ADMIN MENU";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Management\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] Patient Management\n\n";
        cout << "▸ [2] Doctor Management\n\n";
        cout << "▸ [3] Appointment Management\n\n";
        cout << "▸ [4] Payment Management\n\n";

        Console::white();
        cout << "Account\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [5] My Account\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "⇦ [0] Logout\n\n";
        Console::lightGray();
        cout << "➜ Enter your choice: ";
    }

     void AdminManager::printPatientManagementMenu()
    {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "        PATIENT MANAGEMENT";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Patients\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] View All Patients\n\n";
        cout << "▸ [2] Add Patient\n\n";
        cout << "▸ [3] Update Patient\n\n";
        cout << "▸ [4] Remove Patient\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "↩ [0] Back\n\n";
        Console::lightGray();
        cout << "➜ Enter your choice: ";
    }

     void AdminManager::printUpdatePatientMenu()
     {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "          UPDATE PATIENT";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Patient Information\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] Update Name\n\n";
        cout << "▸ [2] Update Password\n\n";
        cout << "▸ [3] Update Phone\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "↩ [0] Back\n\n";
        Console::lightGray();
        cout << "➜ Enter your choice: ";
     }

     void  AdminManager::printDoctorManagementMenu()
    {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "         DOCTOR MANAGEMENT";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Doctors\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] View All Doctors\n\n";
        cout << "▸ [2] Add Doctor\n\n";
        cout << "▸ [3] Update Doctor\n\n";
        cout << "▸ [4] Remove Doctor\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "↩ [0] Back\n\n";
        Console::lightGray();
        cout << "➜ Enter your choice: ";
    }

     void  AdminManager::printUpdateDoctorMenu()
     {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "          UPDATE DOCTOR";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Doctor Information\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] Update Name\n\n";
        cout << "▸ [2] Update Password\n\n";
        cout << "▸ [3] Update Specialization\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "↩ [0] Back\n\n";
        Console::lightGray();
        cout << "➜ Enter your choice: ";
     }
    
     void  AdminManager::printAdminAppointmentManagementMenu()
     {
        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "     APPOINTMENT MANAGEMENT";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Appointments\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [1] View All Appointments\n\n";
        cout << "▸ [2] Update Appointment\n\n";
        cout << "▸ [3] Cancel Appointment\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "↩ [0] Back\n\n";
        Console::lightGray();
        cout << "➜ Enter your choice: ";
     }



     void AdminManager::printPaymentManagementMenu()
     {
         cout << "\n═════════════════════════════════════════\n";
         Console::white();
         cout << "        PAYMENT MANAGEMENT";
         Console::cyan();
         cout << "\n═════════════════════════════════════════\n\n";

         Console::white();
         cout << "Payment\n";
         Console::cyan();
         cout << "─────────────────────────\n";

         cout << "▸ [1] View Pending Payments\n\n";
         cout << "▸ [2] Confirm Cash  Payment\n\n";

         Console::white();
         cout << "Return\n";
         Console::cyan();
         cout << "─────────────────────────\n";
         Console::red();
         cout << "↩ [0] Back\n\n";
         Console::lightGray();
         cout << "➜ Enter your choice: ";
     }



     // Authentication

     Admin* AdminManager::login(int id, string password) {

        auto& admins = HospitalData::getAdmins();
        for (Admin& a : admins) {

            if (a.getId() == id && a.getPassword() == password) {

                return &a;

            }

        }
        return nullptr;


    }

     Admin* AdminManager::searchAdmin(int id) {

        auto& admins = HospitalData::getAdmins();
        for (Admin& a : admins) {

            if (a.getId() == id) {

                return &a;

            }

        }
        return nullptr;

    }
    



     // Admin Management

     void  AdminManager::listAdmins() {

        auto& admins = HospitalData::getAdmins();


        Admin::printAdminHeader();


        for (Admin& d : admins) {

            d.display();

        }

    }




     // Patient Management

      void AdminManager::addPatient(Admin* admin)
     {

        string name = DataEntry::enterName();
        string password = DataEntry::enterPassword();
        string phone = DataEntry::enterPhone();
        int patientId = FilesHelper::getLast(Files::LAST_ID_PATIENTS_FILE) + 1;

        FilesHelper::saveLast(Files::LAST_ID_PATIENTS_FILE, patientId);


        string patientAccount = FilesHelper::generateAccountNumber(Files::LAST_ACCOUNT_PATIENTS_FILE);
        double balanceAcc = 0;
        BankAccount account(patientAccount, balanceAcc);


        Patient patient(patientId, name, password, phone , account);

        FileManager::addPatient(patient);

        Console::success("Patient added successfully.\n");
     }

      bool  AdminManager::deletePatient(int id)
      {
          auto& patients = HospitalData::getPatients();

          for (auto it = patients.begin(); it != patients.end(); ++it)
          {
              if (it->getId() == id)
              {
                  patients.erase(it);
                  return true;
              }
          }

          return false;
      }

      void  AdminManager::removePatient() {

        int patientId = DataEntry::enterId("Patient");

        if (AdminManager::deletePatient(patientId))
        {
            FilesHelper::updatePatients();
            Console::success("Patient deleted successfully.\n");
        }
        else
        {
            Console::error("Patient not found.\n");
        }


      }



      // Doctor Management

     void AdminManager::addDoctor(Admin* admin)
     {

        string name = DataEntry::enterName();
        string password = DataEntry::enterPassword();
        string specialization = DataEntry::enterSpecialization();
        double Salary = DataEntry::enterSalary();
        int doctorId = FilesHelper::getLast(Files::LAST_ID_DOCTORS_FILE) + 1;

        FilesHelper::saveLast(Files::LAST_ID_DOCTORS_FILE, doctorId);

        string doctorAccount = FilesHelper::generateAccountNumber(Files::LAST_ACCOUNT_DOCTORS_FILE);
        BankAccount account(doctorAccount, 0);

        double consultationFee = DataEntry::enterConsultationFee();

        Doctor doctor(doctorId, name, password, specialization, Salary , account , consultationFee);

        FileManager::addDoctor(doctor);

        Console::success("Doctor added successfully.\n");
     }

     bool  AdminManager::deleteDoctor(int id)
     {
         auto& doctors = HospitalData::getDoctors();

         for (auto it = doctors.begin(); it != doctors.end(); ++it)
         {
             if (it->getId() == id)
             {
                 doctors.erase(it);
                 return true;
             }
         }

         return false;
     }

     void  AdminManager::removeDoctor() {

        int doctorId = DataEntry::enterId("Doctor");

        if (deleteDoctor(doctorId))
        {
            FilesHelper::updateDoctors();
            Console::success("Doctor deleted successfully.\n");
        }
        else
        {
            Console::error("Doctor not found.\n");
        }


     }







     // Menu Options

     bool  AdminManager::adminOptions(Admin* admin) {

        if (admin == nullptr) {
            return false;
        }

        printAdminMenu();

        int choice;

        Console::white();
        cin >> choice;
        cin.ignore();
        Console::cyan();


        switch (choice) {

        case 1:
            patientManagementOptions(admin);
            break;


        case 2:
            doctorManagementOptions(admin);
            break;


        case 3:
            appointmentManagementOptions(admin);
            break;

        case 4:
            while (PaymentManagementOptions(admin));
            break;

        case 5:
            while (AdminAccountOptions(admin));
            break;

        case 0:
            return false;


        default:
            Console::error("Invalid option. Please choose a number from the menu.\n");
            break;
        }

        return true;



     }


     bool  AdminManager::patientManagementOptions(Admin* admin)
    {


        printPatientManagementMenu();

        int choice;

        Console::white();
        cin >> choice;
        cin.ignore();
        Console::cyan();

        switch (choice)
        {
        case 1:
            PatientManager::listPatients();
            break;

        case 2:
            addPatient(admin);
            break;

        case 3:
            updatePatientOptions();
            break;

        case 4:
             removePatient();
            break;

        case 0:
            return false;

        default:
            Console::error("Invalid option. Please choose a number from the menu.\n");
            break;
        }

        return true;
    }


     bool  AdminManager::doctorManagementOptions(Admin* admin)
     {


        printDoctorManagementMenu();

        int choice;

        Console::white();
        cin >> choice;
        cin.ignore();
        Console::cyan();

        switch (choice)
        {
        case 1:
            DoctorManager::listDoctors();
            break;

        case 2:
            addDoctor(admin);
            break;

        case 3:
            updateDoctorOptions();
            break;

        case 4:
            removeDoctor();
            break;

        case 0:
            return false;

        default:
            Console::error("Invalid option. Please choose a number from the menu.\n");
            break;
        }

        return true;
     }


     bool AdminManager::appointmentManagementOptions(Admin* admin)
    {


        printAdminAppointmentManagementMenu();

        int choice;

        Console::white();
        cin >> choice;
        cin.ignore();
        Console::cyan();

        switch (choice)
        {
        case 1:
            AppointmentManager::viewAppointments();
            break;

        case 2:

            updateAppointmentOptions();


            break;

        case 3:
        {
            int appointmentId = DataEntry::enterId("Appointment");

            Appointment* ap = AppointmentManager::searchAppointment(appointmentId);

            if (ap != nullptr){

                Patient* patient = PatientManager::searchPatient(ap->getPatientId());

                if (AppointmentManager::processRefund(patient, ap))
                {
                    AppointmentManager::cancelAppointment(appointmentId);
                    FilesHelper::updateAppointments();
                    Console::success("Appointment cancelled successfully.\n");
                }
                else
                {
                    Console::error("Refund failed.\n");
                }

            }
            else
            {
                Console::error("Appointment not found or you are not allowed to cancel it.\n");
            }

            break;
        }
        case 0:
            return false;

        default:
            Console::error("Invalid option. Please choose a number from the menu.\n");
            break;
        }

        return true;
    }


     bool  AdminManager::updatePatientOptions()
    {
        int patientId = DataEntry::enterId("Patient");

        Patient* patient = PatientManager::searchPatient(patientId);

        if (patient == nullptr)
        {
            Console::error("Patient not found.\n");
            return false;
        }

        bool updated = false;

        while (true)
        {
            printUpdatePatientMenu();

            int choice;

            Console::white();
            cin >> choice;
            cin.ignore();
            Console::cyan();

            switch (choice)
            {
            case 1:
                patient->setName(DataEntry::enterName());
                updated = true;
                break;

            case 2:
                patient->setPassword(DataEntry::enterPassword());
                updated = true;
                break;

            case 3:
                patient->setPhone(DataEntry::enterPhone());
                updated = true;
                break;

            case 0:
                if (updated)
                {
                    FilesHelper::updatePatients();
                }
                return false;

            default:
                Console::error("Invalid option. Please choose a number from the menu.\n");
                break;
            }
        }
    }


     bool  AdminManager::updateDoctorOptions()
    {
        int doctorId = DataEntry::enterId("Doctor");

        Doctor* doctor = DoctorManager::searchDoctor(doctorId);

        if (doctor == nullptr)
        {
            Console::error("Doctor not found.\n");
            return false;
        }

        bool updated = false;

        while (true)
        {
            printUpdateDoctorMenu();

            int choice;

            Console::white();
            cin >> choice;
            cin.ignore();
            Console::cyan();
            switch (choice)
            {
            case 1:
                doctor->setName(DataEntry::enterName());
                updated = true;
                break;

            case 2:
                doctor->setPassword(DataEntry::enterPassword());
                updated = true;
                break;

            case 3:
                doctor->setSpecialization(DataEntry::enterSpecialization());
                updated = true;
                break;
           
            case 0:
                if (updated)
                {
                    FilesHelper::updateDoctors();
                }
                return false;

            default:
                Console::error("Invalid option. Please choose a number from the menu.\n");
                break;
            }
        }
    }


     bool  AdminManager::updateAppointmentOptions()
    {
        int appointmentId = DataEntry::enterId("Appointment");

        Appointment* a = AppointmentManager::searchAppointment(appointmentId);

        if (a == nullptr)
        {
            Console::error("Appointment not found.\n");
            return false;
        }

        bool updated = false;

        while (true)
        {
            AppointmentManager::printUpdateAppointmentMenu();

            int choice;

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
                if (updated)
                {
                    FilesHelper::updateAppointments();
                }
                return false;

            default:
                Console::error("Invalid option.\n");
                break;
            }
        }
    }


     bool AdminManager::AdminAccountOptions(Admin* admin) {

        Menu::printAccountMenu();
        int choice;

        Console::white();
        cin >> choice;
        cin.ignore();
        Console::cyan();

        switch (choice) {

        case 0: return false;

        case 1:

            Admin::printAdminHeader();
            admin->display();

            break;

        case 2:
            if (DataEntry::editInfo(admin)) {

                FilesHelper::updateAdmins();

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
            cout << admin->getAccount().getAccountNumber();


            Console::cyan();
            cout << "Current Balance: ";
            Console::white();
            cout << admin->getAccount().getBalance();
            Console::cyan();
            cout << " EGP\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));

            break;

        case 4:
        {
            double amount = DataEntry::enterBalance();

            admin->getAccount().deposit(amount);

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
            cout << admin->getAccount().getBalance();
            Console::cyan();
            cout << " EGP\n\n";

            break;
        }
        default:

            Console::error("Invalid Choice. \n");

        }

        return true;


    }






     bool  AdminManager::PaymentManagementOptions(Admin* admin)
     {

         printPaymentManagementMenu();
        

         int choice;

         Console::white();
         cin >> choice;
         cin.ignore();
         Console::cyan();

         switch (choice)
         {
         case 1:
            
             PaymentManager::viewPendingPayments();
            
             break;

         case 2:
            
             PaymentManager::confirmCashPayment();

             break;

         case 0:
             return false;

         default:
             Console::error("Invalid option. Please choose a number from the menu.\n");
             break;
         }

         return true;
     }



