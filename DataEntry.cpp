#include "DataEntry.h"




	 string DataEntry::enterName() {

		 string name;

		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Name              : ";
			 Console::white();
			 getline(cin, name);
			 Console::cyan();

			 if (Validation::validName(name)) {

				 Console::success("Name accepted.\n");

				 return name;
			 }

			 Console::error("Invalid name! \n");
			 cout << "Name must contain only letters and be between 3 and 20 characters. ";
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }

	 }


	 string DataEntry::enterPassword() {

		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Password          : ";

			 Console::white();
			 string password = Validation::inputPassword();
			 Console::cyan();

			 if (Validation::validPassword(password)) {

				 Console::success("Password accepted.\n");

				 return password;

			 }

			 Console::error("Invalid password! \n");
			 cout << "Password must be between 8 and 20 characters. ";
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }
	 }


	 double DataEntry::enterSalary() {

		 double salary;
		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Salary            : ";
			 Console::white();
			 cin >> salary;
			 cin.ignore();
			 Console::cyan();

			 if (Validation::validSalary(salary,7000)) {

				 Console::success("Salary accepted.\n");

				 return salary;

			 }
			 Console::error("Invalid salary! \n");
			 cout << "Minimum salary is 7000. ";
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }
	 }


	 string DataEntry::enterPhone()
	 {
		 string phone;

		 while (true)
		 {
			 Console::lightGray();
			 cout << "\nEnter Phone             : ";
			 Console::white();
			 getline(cin, phone);

			 if (Validation::validPhone(phone))
			 {
				 Console::success("Phone accepted.\n");
				 return phone;
			 }

			 Console::error("Invalid phone number. Please try again.\n");
		 }
	 }


	 string DataEntry::enterSpecialization()
	 {
		 string specialization;

		 while (true)
		 {
			 Console::lightGray();
			 cout << "\nEnter Specialization    : ";
			 Console::white();
			 getline(cin, specialization);

			 if (!specialization.empty())
			 {
				 Console::success("specialization accepted.\n");
				 return specialization;
			 }

			 Console::error("Specialization cannot be empty.\n");
		 }
	 }


	 double DataEntry::enterBalance() {

		 double balance;
		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter your current bank balance:  ";
			 Console::white();
			 cin >> balance;
			 cin.ignore();
			 Console::cyan();

			 if (balance > 0 ) {

				 Console::success("Bank balance accepted.\n");

				 return balance;

			 }
			
			 Console::error("Bank balance must be greater than 0.");
			 
		 }
	 }


	 double DataEntry::enterConsultationFee()
	 {
		 double consultationFee;

		 while (true)
		 {
			 Console::lightGray();
			 cout << "\nEnter Consultation Fee  : ";
			 Console::white();
			 cin >> consultationFee;
			 cin.ignore();
			 Console::cyan();

			 if (consultationFee > 0)
			 {
				 Console::success("Consultation fee accepted.\n");
				 return consultationFee;
			 }

			 Console::error("Invalid consultation fee!\n");
		 }
	 }


	  double DataEntry::enterEntitlementAmount()
	 {
		 double amount;

		 while (true)
		 {
			 Console::lightGray();
			 cout << "\nEnter entitlement amount: ";
			 Console::white();
			 cin >> amount;
			 Console::cyan();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			 if (amount <= 0)
			 {
				 Console::error("Amount must be greater than zero.\n");
				 continue;
			 }

			 return amount;
		 }
	 }


	 // Appointment

	 string DataEntry::enterDateAppointment() {

		 string date;

		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Date              : ";
			 Console::white();
			 getline(cin, date);

			 if (Validation::validDate(date)) {

				 Console::success("Date accepted.\n");

				 return date;
			 }

			 Console::error("Invalid date! \n");
			 cout << "Date must be in the format DD/MM/YYYY (e.g. 25/07/2026). ";
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }

	 }


	 string DataEntry::enterTimeAppointment() {

		 string time;

		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Time              : ";
			 Console::white();
			 getline(cin, time);

			 if (Validation::validTime(time)) {

				 Console::success("Time accepted.\n");

				 return time;
			 }

			 Console::error("Invalid time! \n");
			 cout << "Time must be in the format HH:MM (e.g. 09:30). ";
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }

	 }



	 string DataEntry::enterAppointmentStatus() {

		 string status;

		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Status!\n(Scheduled, Completed, or Cancelled): ";
			 Console::white();
			 getline(cin, status);

			 if (Validation::validStatusAppointment(status)) {

				 Console::success("Status accepted.\n");

				 return status;
			 }

			 Console::error("Invalid Status! \n");
			 cout << "Valid values are: Scheduled, Completed, or Cancelled. ";
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }

	 }



	 // MedicalRecord

	 string DataEntry::enterDiagnosisMedicalRecord() {

		 string diagnosis;

		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Diagnosis         : ";
			 Console::white();
			 getline(cin, diagnosis);

			 if (!diagnosis.empty()) {
				 Console::success("Diagnosis accepted.\n");
				 return diagnosis;
			 }

			 Console::error("Diagnosis cannot be empty!");
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }

	 }


	 string DataEntry::enterPrescriptionMedicalRecord() {

		 string prescription;

		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Prescription      : ";
			 Console::white();
			 getline(cin, prescription);

			 if (!prescription.empty()) {
				 Console::success("Prescription accepted.\n");
				 return prescription;
			 }

			 Console::error("Prescription cannot be empty!");
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }

	 }


	 string DataEntry::enterNotesMedicalRecord() {

		 string notes;

		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Notes             : ";
			 Console::white();
			 getline(cin, notes);

			 if (!notes.empty()) {
				 Console::success("Notes accepted.\n");
				 return notes;
			 }

			 Console::error("Notes cannot be empty!");
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }

	 }


	 string DataEntry::enterStatusMedicalRecord() {

		 string status;

		 while (true) {
			 Console::lightGray();
			 cout << "\nEnter Status!\n (Active or Archived): ";
			 Console::white();
			 getline(cin, status);

			 if (Validation::validStatusMedicalRecord(status)) {
				 Console::success("Status accepted.\n");
				 return status;
			 }

			 Console::error("Invalid status! \n");
			 cout << "Valid values are: Active or Archived. ";
			 std::this_thread::sleep_for(std::chrono::seconds(1));
			 cout << endl << endl;
		 }

	 }



	 // change

	 bool DataEntry::changePassword(Person* person) {

		 while (true) {

			 cout << "\n═════════════════════════════════════════\n";
			 Console::white();
			 cout << "           CHANGE PASSWORD";
			 Console::cyan();
			 cout << "\n═════════════════════════════════════════\n";

			 cout << "\nNote: Enter 0 to cancel.\n";

			 // Current Password
			 Console::lightGray();
			 cout << "\nCurrent Password        : ";
			 Console::white();
			 string currentPassword = Validation::inputPassword();
			 Console::cyan();

			 if (currentPassword == "0")
				 return false;

			 if (person->getPassword() != currentPassword) {
				 Console::error("Current password is incorrect! \n");
				 continue;
			 }

			 // New Password
			 Console::lightGray();
			 cout << "\nNew Password            : ";
			 Console::white();
			 string newPassword = Validation::inputPassword();
			 Console::cyan();

			 if (newPassword == "0")
				 return false;

			 // Confirm Password
			 Console::lightGray();
			 cout << "\nConfirm Password        : ";
			 Console::white();
			 string confirmPassword = Validation::inputPassword();
			 Console::cyan();

			 if (confirmPassword == "0")
				 return false;

			 if (newPassword != confirmPassword) {
				 Console::error("Passwords do not match! \n");
				 continue;
			 }

			 if (!person->setPassword(newPassword)) {
				 Console::error("Invalid password! \n");
				 continue;
			 }

			 Console::success("Password changed successfully.\n");

			 return true;
		 }
	 }



	 bool DataEntry::changeName(Person* person) {

		 while (true) {

			 cout << "\n═════════════════════════════════════════\n";
			 Console::white();
			 cout << "            CHANGE NAME";
			 Console::cyan();
			 cout << "\n═════════════════════════════════════════\n";

			 cout << "\nNote: Enter 0 to cancel.\n";


			 string newName;
			 // New Name
			 Console::lightGray();
			 cout << "\nNew Name                : ";
			 Console::white();
			 getline(cin, newName);
			 Console::cyan();

			 if (newName == "0")
				 return false;


			 if (!person->setName(newName)) {
				 Console::error("Invalid name! \n");
				 continue;
			 }

			 Console::success("Name changed successfully.\n");

			 return true;
		 }
	 }



	 bool DataEntry::editInfo(Person* person) {

		 if (person == nullptr)
			 return false;

		 cout << "\n═════════════════════════════════════════\n";
		 Console::white();
		 cout << "        UPDATE INFORMATION";
		 Console::cyan();
		 cout << "\n═════════════════════════════════════════\n\n";

		 Console::white();
		 cout << "Personal Information\n";
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
		 cout << "➜ Select an option: ";
		 int choice;
		 Console::white();
		 cin >> choice;
		 cin.ignore();
		 Console::cyan();

		 switch (choice) {

		 case 0:
			 return false;

		 case 1:
			 return changeName(person);

		 case 2:
			 return changePassword(person);

		 default:
			 Console::error("Invalid option!");
			 return false;
		 }
	 }







	 // id

	 int DataEntry::enterId(const string& title) {

		int id;

		while (true) {
			Console::lightGray();
			cout << "\nEnter " << title << " ID: ";

			Console::white();

			if (cin >> id) {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				Console::cyan();
				return id;
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			Console::cyan();

			Console::error("Invalid " + title + " ID!\n");
			cout << "Please enter a valid numeric " << title << " ID.";

			std::this_thread::sleep_for(std::chrono::seconds(1));
			cout << "\n\n";
		}
	}



