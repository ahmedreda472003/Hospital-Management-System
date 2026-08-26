#include "Validation.h"





	 bool Validation::validName(const string& name) {

		 int count = 0;

		 for (char ch : name) {
			 if (isalpha(ch)) {
				 count++;
			 }
			 else if (ch != ' ')
				 return false;
		 }

		 return count >= 3 && count <= 20;

	 }

	 bool Validation::validPassword(const string& password) {

		 if (password.size() < 8 || password.size() > 20) {
			 return false;
		 }

		 bool hasLower = false;
		 bool hasUpper = false;
		 bool hasDigit = false;

		 for (char ch : password) {
			 if (isspace(ch)) {
				 return false;
			 }

			 if (islower(ch)) {
				 hasLower = true;
			 }
			 if (isupper(ch)) {
				 hasUpper = true;
			 }
			 if (isdigit(ch)) {
				 hasDigit = true;
			 }

		 }
		 return hasLower && hasUpper && hasDigit;

	 }

	 bool Validation::validPhone(const string& phone) {

		 if (phone.size() != 11) {
			 return false;
		 }

		 for (char ch : phone) {
			 if (!isdigit(ch)) {
				 return false;
			 }
		 }

		 return true;

	 }

	 bool Validation::validSalary(double salary, double  minimum = 7000) {
		 return salary >= minimum;
	 }


	 //  Appointment 

	 bool Validation::validTime(const string& time) {

		 if (time.size() != 5)
			 return false;

		 if (!isdigit(time[0]) || !isdigit(time[1]) ||
			 time[2] != ':' ||
			 !isdigit(time[3]) || !isdigit(time[4]))
			 return false;

		 int hour = stoi(time.substr(0, 2));
		 int minute = stoi(time.substr(3, 2));

		 return (hour >= 0 && hour <= 23 &&
			 minute >= 0 && minute <= 59);

	 }

	 bool Validation::validDate(const string& date) {

		 if (date.size() != 10)
			 return false;

		 if (!isdigit(date[0]) || !isdigit(date[1]) ||
			 date[2] != '/' ||
			 !isdigit(date[3]) || !isdigit(date[4]) ||
			 date[5] != '/' ||
			 !isdigit(date[6]) || !isdigit(date[7]) ||
			 !isdigit(date[8]) || !isdigit(date[9]))
			 return false;

		 int day = stoi(date.substr(0, 2));
		 int month = stoi(date.substr(3, 2));
		 int year = stoi(date.substr(6, 4));

		 if (month < 1 || month > 12)
			 return false;

		 if (day < 1 || day > 31)
			 return false;

		 if (year < 1900)
			 return false;

		 return true;
	 }

	 bool Validation::validStatusAppointment(const string& status) {

		 string temp = status;

		 for (char& ch : temp) {

			 ch = tolower(ch);

		 }

		 if (temp == "scheduled" ||
			 temp == "completed" ||
			 temp == "cancelled")
		 {
			 return true;
		 }
		 return false;

	 }


	 // MedicalRecord
	 bool Validation::validStatusMedicalRecord(const string& status) {

		 string temp = status;

		 for (char& ch : temp) {

			 ch = tolower(ch);

		 }

		 if (temp == "active" ||
			 temp == "archived")
		 {
			 return true;
		 }
		 return false;

	 }


	 string Validation::inputPassword() {
		string password = "";
		char ch;

		while ((ch = _getch()) != '\r') { // Enter
			if (ch == '\b') { // Backspace
				if (!password.empty()) {
					password.pop_back();
					cout << "\b \b";
				}
			}
			else {
				password += ch;
				cout << '*';
			}
		}

		cout << endl;
		return password;
	}



