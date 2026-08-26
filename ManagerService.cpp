#include "ManagerService.h"




      // Menus

     void ManagerService::printManagerMenu() {

         cout << "═════════════════════════════════════════\n";
         Console::white();
         cout << "            MANAGER PANEL\n";
         Console::cyan();
         cout << "═════════════════════════════════════════\n\n";
         Console::white();
         cout << "Management\n";
         Console::cyan();
         cout << "─────────────────────────\n\n";
         cout << "▸ [1] Admin Management\n\n";
         cout << "▸ [2] Hospital Account\n\n";
         cout << "▸ [3] Payroll\n\n";
         cout << "▸ [4] Reports\n\n";

         Console::white();
         cout << "Return\n";
         Console::cyan();
         cout << "─────────────────────────\n\n";
         Console::red();
         cout << "⇦ [0] Logout\n\n";
         Console::lightGray();
         cout << "➜ Select an option: ";

     }

     void  ManagerService::printAdminManagementMenu() {

         cout << "\n═════════════════════════════════════════\n";
         Console::white();
         cout << "         ADMIN MANAGEMENT";
         Console::cyan();
         cout << "\n═════════════════════════════════════════\n\n";

         Console::white();
         cout << "Management\n";
         Console::cyan();
         cout << "─────────────────────────\n";

         Console::cyan();
         cout << "▸ [1] View All Admins\n\n";
         cout << "▸ [2] Add Admin\n\n";
         cout << "▸ [3] Update Admin\n\n";
         cout << "▸ [4] Remove Admin\n\n";

         Console::white();
         cout << "Return\n";
         Console::cyan();
         cout << "─────────────────────────\n";

         Console::red();
         cout << "↩ [0] Back\n\n";

         Console::lightGray();
         cout << "➜ Enter your choice: ";


     }
     
     void ManagerService::printHospitalAccountMenu() {

         cout << "═════════════════════════════════════════\n";
         Console::white();
         cout << "         HOSPITAL ACCOUNT\n";
         Console::cyan();
         cout << "═════════════════════════════════════════\n\n";

         Console::white();
         cout << "Account\n";
         Console::cyan();
         cout << "─────────────────────────\n\n";
         cout << "▸ [1] View Hospital Balance\n\n";
         Console::white();
         cout << "Return\n";
         Console::cyan();
         cout << "─────────────────────────\n\n";
         Console::red();
         cout << "↩ [0] Back\n\n";
         Console::lightGray();
         cout << "➜ Select an option: ";



     }

     void ManagerService::printPayrollMenu() {

         cout << "═════════════════════════════════════════\n";
         Console::white();
         cout << "               PAYROLL\n";
         Console::cyan();
         cout << "═════════════════════════════════════════\n\n";

         Console::white();
         cout << "Salary Management\n";
         Console::cyan();
         cout << "─────────────────────────\n\n";
         cout << "▸ [1] Pay Doctors' Salaries\n\n";
         cout << "▸ [2] Pay Admins' Salaries\n\n";
         cout << "▸ [3] Update Doctor Salary\n\n";
         cout << "▸ [4] Update Admin Salary\n\n";

         Console::white();
         cout << "Payments\n";
         Console::cyan();
         cout << "─────────────────────────\n\n";
         cout << "▸ [5] Transfer Doctors' Consultation Share\n\n";

         Console::white();
         cout << "Return\n";
         Console::cyan();
         cout << "─────────────────────────\n\n";
         Console::red();
         cout << "↩ [0] Back\n\n";

         Console::lightGray();
         cout << "➜ Select an option: ";


     }

     void ManagerService::printReportsMenu() {

         cout << "═════════════════════════════════════════\n";
         Console::white();
         cout << "             REPORTS\n";
         Console::cyan();
         cout << "═════════════════════════════════════════\n\n";
         Console::white();
         cout << "Financial Reports\n";
         Console::cyan();
         cout << "─────────────────────────\n\n";
         cout << "▸ [1] View Transaction History\n\n";
         cout << "▸ [2] Financial Summary\n\n";

         Console::white();
         cout << "Return\n";
         Console::cyan();
         cout << "─────────────────────────\n\n";
         Console::red();
         cout << "↩ [0] Back\n\n";

         Console::lightGray();
         cout << "➜ Select an option: ";



     }    

     void ManagerService::printUpdateAdminMenu()
     {
         cout << "\n═════════════════════════════════════════\n";
         Console::white();
         cout << "          UPDATE ADMIN";
         Console::cyan();
         cout << "\n═════════════════════════════════════════\n\n";

         Console::white();
         cout << "Admin Information\n";
         Console::cyan();
         cout << "─────────────────────────\n";

         cout << "▸ [1] Update Name\n\n";
         cout << "▸ [2] Update Password\n\n";

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

     Manager* ManagerService::login(int id, string password) {

         auto& manager = HospitalData::getManager();

         for (Manager& a : manager) {

             if (a.getId() == id && a.getPassword() == password) {

                 return &a;

             }

         }

         return nullptr;

     }







     // Admin Management

     void ManagerService::addAdmin()
     {

         string name = DataEntry::enterName();
         string password = DataEntry::enterPassword();
         double salary = DataEntry::enterSalary();
         int adminId = FilesHelper::getLast(Files::LAST_ID_ADMINS_FILE) + 1;

         FilesHelper::saveLast(Files::LAST_ID_PATIENTS_FILE, adminId);


         string patientAccount = FilesHelper::generateAccountNumber(Files::LAST_ACCOUNT_ADMINS_FILE);
         double balanceAcc = 0;
         BankAccount account(patientAccount, balanceAcc);


         Admin admin(adminId, name, password, salary, account);

         FileManager::addAdmin(admin);

         Console::success("Admin added successfully.\n");

     }


     bool ManagerService::deleteAdmin(int id)
     {
         auto& admins = HospitalData::getAdmins();

         for (auto it = admins.begin(); it != admins.end(); ++it)
         {
             if (it->getId() == id)
             {
                 admins.erase(it);
                 return true;
             }
         }

         return false;
     }


     void ManagerService::removeAdmin() {

         int adminId = DataEntry::enterId("Patient");

         if (deleteAdmin(adminId))
         {
             FilesHelper::updateAdmins();
             Console::success("Admin deleted successfully.\n");
         }
         else
         {
             Console::error("Admin not found.\n");
         }


     }





     // Payroll

     void ManagerService::payDoctor() {

         int doctorId = DataEntry::enterId("Doctor");

         Doctor* doctor = DoctorManager::searchDoctor(doctorId);

         if (doctor == nullptr) {
             Console::error("Doctor not found \n");
             return;
         }



         if (HospitalData::getHospitalAccount().transferTo(doctor->getAccount(), doctor->getSalary())) {

             Console::success("The funds have been successfully transferred.\n");

             Transaction transaction(HospitalData::getHospitalAccount().getAccountNumber(),
                 doctor->getAccount().getAccountNumber(), doctor->getSalary(), "Doctor Salary");

             FileManager::addTransaction(transaction);

             FilesHelper::updateDoctors();
             FilesHelper::saveHospitalAccount(HospitalData::getHospitalAccount());

         }
         else {

             Console::error("The amount is insufficient.");

         }

     }

     void ManagerService::payAdmin() {

         int adminId = DataEntry::enterId("Admin");

         Admin* admin = AdminManager::searchAdmin(adminId);

         if (admin == nullptr) {
             Console::error("Admin not found \n");
             return;
         }



         if (HospitalData::getHospitalAccount().transferTo(admin->getAccount(), admin->getSalary())) {

             Console::success("The funds have been successfully transferred.\n");


             Transaction transaction(HospitalData::getHospitalAccount().getAccountNumber(),
                 admin->getAccount().getAccountNumber(), admin->getSalary(), "Admin Salary");

             FileManager::addTransaction(transaction);

             FilesHelper::updateAdmins();
             FilesHelper::saveHospitalAccount(HospitalData::getHospitalAccount());

         }
         else {

             Console::error("The amount is insufficient.");

         }

     }

     void ManagerService::updateDoctorSalary() {

         int doctorId = DataEntry::enterId("Doctor");

         Doctor* doctor = DoctorManager::searchDoctor(doctorId);

         if (doctor == nullptr) {
             Console::error("Doctor not found \n");
             return;
         }

         double amount = DataEntry::enterSalary();


         doctor->setSalary(amount);

         FilesHelper::updateDoctors();


     }

     void ManagerService::updateAdminSalary() {

         int AdminId = DataEntry::enterId("Admin");

         Admin* admin = AdminManager::searchAdmin(AdminId);

         if (admin == nullptr) {
             Console::error("Admin not found \n");
             return;
         }

         double amount = DataEntry::enterSalary();


         admin->setSalary(amount);

         FilesHelper::updateAdmins();

     }





     // Financial Entitlements

     bool ManagerService::hasFinancialEntitlement(int doctorId) {

         auto& entitlements = HospitalData::getEntitlements();

         return entitlements.find(doctorId) != entitlements.end();
     }

     double ManagerService::getFinancialEntitlement(int doctorId) {

         auto& entitlements = HospitalData::getEntitlements();

         return entitlements[doctorId];

     }

     bool ManagerService::deductFinancialEntitlement(int doctorId, double amount) {

         auto& entitlements = HospitalData::getEntitlements();

         auto it = entitlements.find(doctorId);

         if (it == entitlements.end()) {
             return false;
         }

         if (it->second < amount) {
             return false;
         }


         it->second -= amount;

         if (it->second == 0) {
             entitlements.erase(it);
         }

         return true;
     }


     void ManagerService::listDoctorsEntitlements()
     {
        

         vector<pair<int, double>> list(
             HospitalData::getEntitlements().begin(),
             HospitalData::getEntitlements().end()
         );


         sort(list.begin(), list.end(),
             [](const auto& a, const auto& b)
             {
                 return a.second > b.second;
             });

         Console::white();
         cout << left << endl
             << setw(12) << "Doctor ID"
             << setw(15) << "Entitlement" << endl;
         Console::cyan();
         cout << string(27, '-') << endl;

         for (const auto& item : list)
         {
             Console::white();
             cout << left
                 << setw(12) << item.first
                 << setw(15) << item.second
                 << endl;
             Console::cyan();
         }
       
     }

     void ManagerService::payDoctorEntitlements()
     {
         int doctorId = DataEntry::enterId("Doctor");

         Doctor* doctor = DoctorManager::searchDoctor(doctorId);

         if (doctor == nullptr)
         {
             Console::error("Doctor not found.\n");
             return;
         }

         if (!hasFinancialEntitlement(doctorId))
         {
             Console::error("This doctor has no financial entitlements.\n");
             return;
         }

         double entitlement = getFinancialEntitlement(doctorId);


         double amount = DataEntry::enterEntitlementAmount();

         if (amount > entitlement)
         {
             Console::error("Insufficient financial entitlements.\n");
             return;
         }

         if (HospitalData::getHospitalAccount().getBalance() < amount)
         {
             Console::error("The hospital account balance is insufficient.\n");
             return;
         }

         deductFinancialEntitlement(doctorId, amount);

         HospitalData::getHospitalAccount().transferTo(doctor->getAccount(), amount);


         Transaction transaction(HospitalData::getHospitalAccount().getAccountNumber(),
             doctor->getAccount().getAccountNumber(), amount, "Doctor Entitlement");

         FileManager::addTransaction(transaction);


         FilesHelper::updateDoctors();
         FilesHelper::saveHospitalAccount(HospitalData::getHospitalAccount());
         FilesHelper::updateFinancialEntitlements();

         Console::success("The funds have been successfully transferred.\n");
     }






     // Menu Options

     bool  ManagerService::managerOptions(Manager* manager) {

         if (manager == nullptr) {
             return false;
         }

         printManagerMenu();

         int choice;

         Console::white();
         cin >> choice;
         cin.ignore();
         Console::cyan();


         switch (choice) {

         case 1:
             while (adminManagementOptions());
             break;


         case 2:
             while (hospitalManagementOptions());
             break;


         case 3:
             while (payrollManagementOptions());
             break;


         case 4:
             while (reportManagementOptions());
             break;

         case 0:
             return false;


         default:
             Console::error("Invalid option. Please choose a number from the menu.\n");
             break;
         }

         return true;

     }

     bool ManagerService::adminManagementOptions() {

         printAdminManagementMenu();

         int choice;

         Console::white();
         cin >> choice;
         cin.ignore();
         Console::cyan();


         switch (choice) {

         case 1:
             AdminManager::listAdmins();
             break;

         case 2:
             addAdmin();
             break;

         case 3:
             updateAdminOptions();
             break;

         case 4:
             removeAdmin();
             break;

         case 0:
             return false;

         default:
             Console::error("Invalid option. Please choose a number from the menu.\n");
             break;
         }

         return true;



     }

     bool ManagerService::hospitalManagementOptions() {

         printHospitalAccountMenu();

         int choice;

         Console::white();
         cin >> choice;
         cin.ignore();
         Console::cyan();


         switch (choice) {

         case 1:
             Console::cyan();
             cout << "\n═════════════════════════════════════════\n";
             Console::white();
             cout << "            HOSPITAL BALANCE";
             Console::cyan();
             cout << "\n═════════════════════════════════════════\n\n";


             Console::cyan();
             cout << "Current Balance: ";
             Console::white();
             cout << HospitalData::getHospitalAccount().getBalance();
             Console::cyan();
             cout << " EGP\n\n";
             std::this_thread::sleep_for(std::chrono::seconds(1));

             break;

         case 0:
             return false;


         default:
             Console::error("Invalid option. Please choose a number from the menu.\n");
             break;
         }

         return true;



     }

     bool ManagerService::payrollManagementOptions() {

         printPayrollMenu();

         int choice;

         Console::white();
         cin >> choice;
         cin.ignore();
         Console::cyan();


         switch (choice) {

         case 1:

             if (HospitalData::getDoctors().empty())
             {
                 Console::error("There are no doctors.\n");
                 break;
             }

             DoctorManager::listDoctors();
             payDoctor();

             break;


         case 2:

             if (HospitalData::getAdmins().empty())
             {
                 Console::error("There are no admins.\n");
                 break;
             }

             AdminManager::listAdmins();

             payAdmin();

             break;

         case 3:

             if (HospitalData::getDoctors().empty())
             {
                 Console::error("There are no doctors.\n");
                 break;
             }

             DoctorManager::listDoctors();
             updateDoctorSalary();
             break;

         case 4:

             if (HospitalData::getAdmins().empty())
             {
                 Console::error("There are no admins.\n");
                 break;
             }

             AdminManager::listAdmins();
             updateAdminSalary();

             break;

         case 5:

             listDoctorsEntitlements();

             payDoctorEntitlements();

            
             break;

         case 0:
             return false;


         default:
             Console::error("Invalid option. Please choose a number from the menu.\n");
             break;
         }

         return true;



     }

     bool ManagerService::reportManagementOptions() {

         printReportsMenu();

         int choice;

         Console::white();
         cin >> choice;
         cin.ignore();
         Console::cyan();


         switch (choice) {

         case 1:
             TransactionManager::listTransactions();
             break;

         case 2:
             TransactionManager::financialSummary() ;
          break;

         case 0:
             return false;


         default:
             Console::error("Invalid option. Please choose a number from the menu.\n");
             break;
         }

         return true;



     }

     bool  ManagerService::updateAdminOptions()
    {
        int adminId = DataEntry::enterId("Admin");

        Admin* admin = AdminManager::searchAdmin(adminId);

        if (admin == nullptr)
        {
            Console::error("Admin not found.\n");
            return false;
        }

        bool updated = false;

        while (true)
        {
            printUpdateAdminMenu();

            int choice;

            Console::white();
            cin >> choice;
            cin.ignore();
            Console::cyan();
            switch (choice)
            {
            case 1:
                admin->setName(DataEntry::enterName());
                updated = true;
                break;

            case 2:
                admin->setPassword(DataEntry::enterPassword());
                updated = true;
                break;

            case 0:
                if (updated)
                {
                    FilesHelper::updateAdmins();
                }
                return false;

            default:
                Console::error("Invalid option. Please choose a number from the menu.\n");
                break;
            }
        }
    }


