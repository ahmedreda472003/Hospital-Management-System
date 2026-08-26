#include "PatientManager.h"
#include "DoctorManager.h"




      // Menus

	  void  PatientManager::printPatientMenu()
	 {
		 cout << "\n═════════════════════════════════════════\n";
		 Console::white();
		 cout << "            PATIENT MENU";
		 Console::cyan();
		 cout << "\n═════════════════════════════════════════\n\n";


		 Console::white();
		 cout << "Appointments\n";
		 Console::cyan();
		 cout << "─────────────────────────\n";

		 cout << "▸ [1] Appointments\n\n";


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

	  void PatientManager::printPatientAppointmentsMenu()
	 {
		 cout << "\n═════════════════════════════════════════\n";
		 Console::white();
		 cout << "        APPOINTMENTS MENU";
		 Console::cyan();
		 cout << "\n═════════════════════════════════════════\n\n";


		 Console::white();
		 cout << "Appointments\n";
		 Console::cyan();
		 cout << "─────────────────────────\n";

		 cout << "▸ [1] Book Appointment\n\n";
		 cout << "▸ [2] View My Appointments\n\n";
		 cout << "▸ [3] Cancel Appointment\n\n";


		 Console::white();
		 cout << "Return\n";
		 Console::cyan();
		 cout << "─────────────────────────\n";
		 Console::red();
		 cout << "↩ [0] Back\n\n";

		 Console::lightGray();
		 cout << "➜ Select an option: ";
	 }

	  void  PatientManager::printPatientMedicalRecordsMenu()
	 {
		 cout << "\n═════════════════════════════════════════\n";
		 Console::white();
		 cout << "       MEDICAL RECORDS MENU";
		 Console::cyan();
		 cout << "\n═════════════════════════════════════════\n\n";


		 Console::white();
		 cout << "Records\n";
		 Console::cyan();
		 cout << "─────────────────────────\n";

		 cout << "▸ [1] View My Medical Records\n\n";


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

	  Patient* PatientManager::login(int id, const string& password) {

		 auto& patients = HospitalData::getPatients();

		 for (Patient& p : patients) {
			 if (p.getId() == id && p.getPassword() == password) {

				 return &p;

			 }
		 }

		 return nullptr;

	 }



     // Patient Management

	  void  PatientManager::listPatients() {

		 auto& patients = HospitalData::getPatients();

		 Patient::printPatientHeader();


		 for (Patient& p : patients) {

			 p.display();

		 }

	 }

	  Patient* PatientManager::searchPatient(int id) {

		 auto& patients = HospitalData::getPatients();
		 for (Patient& p : patients) {

			 if (p.getId() == id) {

				 return &p;

			 }

		 }
		 return nullptr;
	 }



      // Appointments

       void PatientManager::bookAppointment(Patient* patient)
       {
	        DoctorManager::listDoctors();

	         int doctorId = DataEntry::enterId("Doctor");

	         Doctor* doctor = DoctorManager::searchDoctor(doctorId);

	         if (doctor == nullptr)
	         {
	         	Console::error("Doctor not found.\n");
	         	return;
	         }


	        string date = DataEntry::enterDateAppointment();

	        string time = DataEntry::enterTimeAppointment();

	        if (!AppointmentManager::isDoctorAvailable(doctorId, date, time)) {
				Console::error("This doctor already has an appointment at this time.");
	        	return;
	        }

	        if (!AppointmentManager::isPatientAvailable(patient->getId(), date, time)) {
				Console::error("You already have an appointment at this time.");
	        	return;
	        }

			Console::cyan();
			cout << "\n═════════════════════════════════════════\n";
			Console::white();
			cout << "           PAYMENT METHOD";
			Console::cyan();
			cout << "\n═════════════════════════════════════════\n\n";
	
			cout << "💵 [1] Cash\n\n";
			cout << "💳 [2] Visa\n\n";

			Console::lightGray();
			cout << "➜ Choose Payment Method: ";

			Console::white();
			int choice;
			cin >> choice;

			string paymentMethod;

			if (choice == 1)
			{
				paymentMethod = "Cash";
			}
			else if (choice == 2)
			{
				paymentMethod = "Visa";

				if (!AppointmentManager::processVisaPayment(patient, doctor)) {
					return;
				}

			     Transaction transaction(patient->getAccount().getAccountNumber(),
				  HospitalData::getHospitalAccount().getAccountNumber(), doctor->getConsultationFee() ,"Appointment Payment" );

			  FileManager::addTransaction(transaction);

			}
			else
			{
				Console::error("Invalid choice.");
				return;
			}

			


	        string status = "Scheduled";

	        int appointmentId = FilesHelper::getLast(Files::LAST_APPOINTMENT_ID) + 1;

	        Appointment appointment(appointmentId, patient->getId(), doctorId, date, time, status , paymentMethod);
			if (choice == 2)
			{
				appointment.setPaymentStatus("Completed");
			}


	        FileManager::addAppointment(appointment);

	        FilesHelper::saveLast(Files::LAST_APPOINTMENT_ID, appointmentId);

	        Console::success("Appointment booked successfully.\n");


       }





      // Menu Options

	  bool  PatientManager::patientOptions(Patient* patient)
	 {
		 if (patient == nullptr) {
			 return false;
		 }

		 printPatientMenu();

		 int choice;

		 Console::white();
		 cin >> choice;
		 cin.ignore();
		 Console::cyan();


		 switch (choice)
		 {

		 case 1:
			 while (patientAppointmentOptions(patient));
			 break;


		 case 2:
			 while (patientMedicalRecordOptions(patient));
			 break;


		 case 3:
			 while (patientAccountOptions(patient));
			 break;


		 case 0:
			 return false;


		 default:
			 Console::error("Invalid option. Please choose a number from the menu.\n");
			 break;
		 }

		 return true;
	 }


	  bool  PatientManager::patientAppointmentOptions(Patient* patient)
	 {
		 printPatientAppointmentsMenu();

		 int choice;
		 Console::white();
		 cin >> choice;
		 cin.ignore();
		 Console::cyan();


		 switch (choice)
		 {

		 case 1:
			 cout << "\n═════════════════════════════════════════\n";
			 Console::white();
			 cout << "        BOOK APPOINTMENTS";
			 Console::cyan();
			 cout << "\n═════════════════════════════════════════\n\n";

			 bookAppointment(patient);

			 break;


		 case 2:

			 cout << "\n═════════════════════════════════════════\n";
			 Console::white();
			 cout << "        MY APPOINTMENTS";
			 Console::cyan();
			 cout << "\n═════════════════════════════════════════\n\n";


			 if (!AppointmentManager::viewAppointmentsByPatient(patient->getId()))
			 {
				 Console::error("No appointments found.\n");
			 }

			 break;


		 case 3:
		 {

			 cout << "\n═════════════════════════════════════════\n";
			 Console::white();
			 cout << "        CANCEL APPOINTMENT";
			 Console::cyan();
			 cout << "\n═════════════════════════════════════════\n\n";

			 int appointmentId = DataEntry::enterId("Appointment");

			 Appointment* ap = AppointmentManager::searchAppointment(appointmentId);


			 if (ap != nullptr && ap->getPatientId() == patient->getId())
			 {
				 AppointmentManager::cancelAppointment(appointmentId);

				 AppointmentManager::processRefund(patient, ap);

				 Console::success("Cancellation successful\n");

				 FilesHelper::updateAppointments();
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
			 Console::error("Invalid option.\n");
		 }

		 return true;
	 }


	  bool  PatientManager::patientMedicalRecordOptions(Patient* patient)
	 {
		 printPatientMedicalRecordsMenu();

		 int choice;
		 Console::white();
		 cin >> choice;
		 cin.ignore();
		 Console::cyan();


		 switch (choice)
		 {
		 case 1:

			 cout << "\n═════════════════════════════════════════\n";
			 Console::white();
			 cout << "        MY MEDICAL RECORDS";
			 Console::cyan();
			 cout << "\n═════════════════════════════════════════\n\n";


			 if (!MedicalRecordManager::viewMedicalRecordsPatient(patient->getId()))
			 {
				 Console::error("No medical records found.\n");
			 }

			 break;


		 case 0:
			 return false;


		 default:
			 Console::error("Invalid option.\n");
		 }

		 return true;
	 }


	  bool PatientManager::patientAccountOptions(Patient* patient) {

		 Menu::printAccountMenu();

		 int choice;

		 Console::white();
		 cin >> choice;
		 cin.ignore();
		 Console::cyan();

		 switch (choice) {

		 case 0: return false;

		 case 1:

			 Patient::printPatientHeader();
			 patient->display();

			 break;

		 case 2:
			 if (DataEntry::editInfo(patient)) {

				 FilesHelper::updatePatients();

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
			 cout << patient->getAccount().getAccountNumber();
			

			 Console::cyan();
			 cout << "Current Balance  : ";
			 Console::white();
			 cout << patient->getAccount().getBalance();
			 Console::cyan();
			 cout << " EGP\n\n";
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			
			 break;

		 case 4:
		 {
			 double amount = DataEntry::enterBalance();

			 patient->getAccount().deposit(amount);

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
			 cout << patient->getAccount().getBalance();
			 Console::cyan();
			 cout << " EGP\n\n";

			 break;
		 }

		 default:

			 Console::error("Invalid Choice. \n");

		 }

		 return true;

	 }




