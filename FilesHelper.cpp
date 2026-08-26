#include "FilesHelper.h"




     // IDs

     void FilesHelper::saveLast(string fileName, int id) {
         ofstream open(fileName, ios::trunc);
         if (open.is_open()) {
             open << id;
         }
         open.close();
     }


     int FilesHelper::getLast(string fileName) {
         int id = 0;
         ifstream open(fileName);
         if (open.is_open()) {
             open >> id;
         }
         open.close();

         return id;
     }



     // Bank Accounts

     BankAccount FilesHelper::getHospitalAccount()
     {
         ifstream dataBase(Files::ACCOUNT_HOSPITAL_FILE);

         string line;

         if (dataBase.is_open())
         {
             getline(dataBase, line);
         }

         dataBase.close();

         return Parser::parseToHospitalAccount(line);
     }


     void FilesHelper::saveHospitalAccount(const BankAccount& account) {

         ofstream dataBase(Files::ACCOUNT_HOSPITAL_FILE, ios::trunc);

         if (dataBase.is_open()) {

             dataBase << account.getAccountNumber() << '-'
                 << account.getBalance() << '\n';

         }

         dataBase.close();

     }



     void FilesHelper::saveLastAccount(string fileName,string account) {
         ofstream open(fileName, ios::trunc);
         if (open.is_open()) {
             open << account;
         }
         open.close();
     }


     string FilesHelper::getLastAccount(string fileName) {

         string account;

         if (fileName == Files::LAST_ACCOUNT_PATIENTS_FILE)
             account = "PAT1000";
         else if (fileName == Files::LAST_ACCOUNT_DOCTORS_FILE)
             account = "DOC1000";
         else if (fileName == Files::LAST_ACCOUNT_ADMINS_FILE)
             account = "ADM1000";
         

         ifstream open(fileName); 
         if (open.is_open()) {
             open >> account;
         }
         open.close();

         return account;
     }


     string FilesHelper::generateAccountNumber(string fileName)
     {
         string account = getLastAccount(fileName);

         string prefix = account.substr(0, 3);   // PAT / DOC / ADM / HOS
         int number = stoi(account.substr(3));    // الجزء الرقمي


         number += 4;

         account = prefix + to_string(number);

         saveLastAccount(fileName, account);

         return account;
     }







     // Save

     void FilesHelper::saveFinancialEntitlement(int doctorId, double amount)
     {
         ofstream dataBase(Files::FINANCIAL_ENTITLEMENTS_FILE, ios::app);

         if (dataBase.is_open())
         {
             dataBase << doctorId << '-'
                 << amount << '\n';
         }

         dataBase.close();
     }


     void FilesHelper::savePatient(const Patient& p) {

         ofstream dataBase(Files::PATIENTS_FILE, ios::app);

         if (dataBase.is_open()) {

             dataBase << p.getId() << '-'
                 << p.getName() << '-'
                 << p.getPassword() << '-'
                 << p.getPhone() << '-'
                 << p.getAccount().getAccountNumber() << '-'
                 << p.getAccount().getBalance() << '\n';
                 
                
         }

         dataBase.close();

     }


     void FilesHelper::saveDoctor(const Doctor& d) {

         ofstream dataBase(Files::DOCTORS_FILE, ios::app);

         if (dataBase.is_open()) {

             dataBase << d.getId() << '-'
                 << d.getName() << '-'
                 << d.getPassword() << '-'
                 << d.getSpecialization() << '-'
                 << d.getSalary() << '-'
                 << d.getAccount().getAccountNumber() << '-'
                 << d.getAccount().getBalance() << '-'
                 << d.getConsultationFee() << '\n';
             
         }

         dataBase.close();

     }


     void FilesHelper::saveAdmin(const Admin& a) {

         ofstream dataBase(Files::ADMINS_FILE, ios::app);

         if (dataBase.is_open()) {

             dataBase << a.getId() << '-'
                 << a.getName() << '-'
                 << a.getPassword() << '-'
                 << a.getSalary() << '-'
                 << a.getAccount().getAccountNumber() << '-'
                 << a.getAccount().getBalance() << '\n';

         }

         dataBase.close();

     }


     void FilesHelper::saveAppointment(const Appointment& a) {

         ofstream dataBase(Files::APPOINTMENTS_FILE, ios::app);

         if (dataBase.is_open()) {

             dataBase << a.getAppointmentId() << '-'
                 << a.getPatientId() << '-'
                 << a.getDoctorId() << '-'
                 << a.getDate() << '-'
                 << a.getTime() << '-'
                 << a.getStatus() << '-'
                 << a.getPaymentMethod() << '-'
                 << a.getPaymentStatus() << '\n';
         }

         dataBase.close();

     }


     void FilesHelper::saveMedicalRecord(const MedicalRecord& m) {

         ofstream dataBase(Files::MEDICAL_RECORDS_FILE, ios::app);

         if (dataBase.is_open()) {

             dataBase << m.getAppointmentId() << '-'
                 << m.getPatientId() << '-'
                 << m.getDoctorId() << '-'
                 << m.getDiagnosis() << '-'
                 << m.getPrescription() << '-'
                 << m.getNotes() << '-'
                 << m.getStatus() << '\n';
         }

         dataBase.close();


     }


     void FilesHelper::saveTransaction(const Transaction& t) {

         ofstream dataBase(Files::TRANSACTIONS_FILE , ios::app);

         if (dataBase.is_open()) {

             dataBase << t.getSenderAccount() << '-'
                 << t.getReceiverAccount() << '-'
                 << t.getAmount() << '-'
                 << t.getType() << '-'
                 << t.getDateTime()
                 << '\n';
         }

         dataBase.close();

     }





     // Load

     void FilesHelper::fetchPatients() {

         ifstream dataBase(Files::PATIENTS_FILE);

         if (dataBase.is_open()) {

             string line;
             while (getline(dataBase, line)) {

                 HospitalData::addPatient(Parser::parseToPatient(line));

             }

             dataBase.close();

         }


     }


     void FilesHelper::fetchDoctors() {


         ifstream dataBase(Files::DOCTORS_FILE);

         if (dataBase.is_open()) {

             string line;
             while (getline(dataBase, line)) {

                 HospitalData::addDoctor(Parser::parseToDoctor(line));

             }

             dataBase.close();

         }


     }


     void FilesHelper::fetchAdmins() {

         ifstream dataBase(Files::ADMINS_FILE);

         if (dataBase.is_open()) {

             string line;
             while (getline(dataBase, line)) {

                 HospitalData::addAdmin(Parser::parseToAdmin(line));

             }

             dataBase.close();

         }


     }


     void FilesHelper::fetchManagers() {

         ifstream dataBase(Files::MANEGER_FILE);

         if (dataBase.is_open()) {

             string line;
             while (getline(dataBase, line)) {

                 HospitalData::addManager(Parser::parseToManager(line));

             }

             dataBase.close();

         }


     }


     void FilesHelper::fetchAppointments() {


         ifstream dataBase(Files::APPOINTMENTS_FILE);

         if (dataBase.is_open()) {

             string line;
             while (getline(dataBase, line)) {

                 AppointmentManager::addAppointment(Parser::parseToAppointment(line));

             }

             dataBase.close();

         }

     }


     void FilesHelper::fetchMedicalRecord() {


         ifstream dataBase(Files::MEDICAL_RECORDS_FILE);

         if (dataBase.is_open()) {

             string line;
             while (getline(dataBase, line)) {

                 MedicalRecordManager::addMedicalRecord(Parser::parseToMedicalRecord(line));

             }

             dataBase.close();

         }

     }


     void FilesHelper::fetchFinancialEntitlements()
     {
         ifstream dataBase(Files::FINANCIAL_ENTITLEMENTS_FILE);

         if (dataBase.is_open())
         {
             string line;

             while (getline(dataBase, line))
             {
                 auto data = Parser::parseToFinancialEntitlement(line);

                 HospitalData::addFinancialEntitlement(data.first, data.second);
             }

             dataBase.close();
         }
     }


     void FilesHelper::fetchTransactions()
     {
         ifstream dataBase(Files::TRANSACTIONS_FILE);

         if (dataBase.is_open())
         {
             string line;

             while (getline(dataBase, line))
             {
                 Transaction transaction = Parser::parseToTransaction(line);
                 HospitalData::addTransaction(transaction);
             }

             dataBase.close();
         }
     }





     // Add

     void FilesHelper::addPatient(const Patient& p) {

         savePatient(p);

     }


     void FilesHelper::addDoctor(const Doctor& d) {

         saveDoctor(d);

     }


     void FilesHelper::addAdmin(const Admin& a) {

         saveAdmin(a);

     }


     void FilesHelper::addAppointment(const Appointment& a) {

         saveAppointment(a);

     }


     void FilesHelper::addMedicalRecord(const MedicalRecord& a) {

         saveMedicalRecord(a);

     }






     // Utilities

     void FilesHelper::clearFile(string fileName) {

         ofstream openF(fileName, ios::trunc);

         openF.close();

     }






     // Remove

     void FilesHelper::removeAllPatients() {

         clearFile(Files::PATIENTS_FILE);

     }


     void FilesHelper::removeAllDoctors() {

         clearFile(Files::DOCTORS_FILE);

     }


     void FilesHelper::removeAllAdmins() {

         clearFile(Files::ADMINS_FILE);

     }


     void FilesHelper::removeAllAppointments() {

         clearFile(Files::APPOINTMENTS_FILE);

     }


     void FilesHelper::removeAllMedicalRecords() {

         clearFile(Files::MEDICAL_RECORDS_FILE);

     }


     void FilesHelper::removeAllFinancialEntitlements()
     {
       
         clearFile(Files::FINANCIAL_ENTITLEMENTS_FILE);

     }


     void FilesHelper::removeAllTransactions()
     {

         clearFile(Files::TRANSACTIONS_FILE);

     }






     // Update

     void FilesHelper::updatePatients() {

         removeAllPatients();

         const vector<Patient>& patients = HospitalData::getPatients();

         for (const Patient& p : patients) {
             savePatient(p);
         }
     }


     void FilesHelper::updateDoctors() {

         removeAllDoctors();

         const vector<Doctor>& doctor = HospitalData::getDoctors();

         for (const Doctor& d : doctor) {
             saveDoctor(d);
         }
     }


     void FilesHelper::updateAdmins() {

         removeAllAdmins();

         const vector<Admin>& admin = HospitalData::getAdmins();

         for (const Admin& a : admin) {
             saveAdmin(a);
         }
     }


     void FilesHelper::updateAppointments() {

         removeAllAppointments();
         const vector<Appointment>& appointment = AppointmentManager::getAppointments();

         for (const Appointment& a : appointment) {
             saveAppointment(a);
         }
     }


     void FilesHelper::updateMedicalRecords() {

        removeAllMedicalRecords();

        const vector<MedicalRecord>& medicalRecord = MedicalRecordManager::getMedicalRecords();

        for (const MedicalRecord& m : medicalRecord) {
            saveMedicalRecord(m);
        }
     }


     void FilesHelper::updateFinancialEntitlements()
     {
         removeAllFinancialEntitlements();

         const auto& entitlements = HospitalData::getEntitlements();

         for (const auto& e : entitlements)
         {
             saveFinancialEntitlement(e.first, e.second);
         }
     }


     void FilesHelper::updateTransactions()
     {
         removeAllTransactions();

         const auto& Transaction = HospitalData::getTransactions();

         for (const auto& e : Transaction)
         {
             saveTransaction(e);
         }
     }