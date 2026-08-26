#include "Appointment.h"


    Appointment::Appointment(int appointmentId, int patientId, int doctorId,
		const string& date, const string& time, const string& status ,const string& paymentMethod , const string& paymentStatus ) :
		appointmentId(appointmentId), patientId(patientId), doctorId(doctorId), date(date), time(time), status(status), paymentMethod(paymentMethod) , 
		paymentStatus(paymentStatus) {}




	bool Appointment::setDate(const string& date) {

		if (Validation::validDate(date))
		{
			this->date = date;
			return true;
		}
		return false;

	}



	bool Appointment::setTime(const string& time) {

		if (Validation::validTime(time)) {
			this->time = time;
			return true;
		}
		return false;
	}



	bool Appointment::setStatus(const string& status) {

		if (Validation::validStatusAppointment(status))
		{
			this->status = status;
			return true;
		}
		return false;

	}


	bool Appointment::setPaymentMethod(string method)
	{
		paymentMethod = method;
		return true;
	}




	void Appointment::setPaymentStatus(string paymentStatus)
	{
		this->paymentStatus = paymentStatus;
	}


	string Appointment::getPaymentStatus() const {

		return paymentStatus;

	}



	int Appointment::getAppointmentId() const {
		return appointmentId;
	}



	int Appointment::getPatientId() const {
		return patientId;
	}



	int Appointment::getDoctorId() const {
		return doctorId;
	}



	string Appointment::getDate() const {
		return date;
	}



	string Appointment::getTime() const {
		return time;
	}



	string Appointment::getStatus() const {
		return status;
	}


	string Appointment::getPaymentMethod() const
	{
		return paymentMethod;
	}


	void Appointment::display() const {

		Console::white();
		cout << left
			<< setw(8) << appointmentId
			<< setw(14) << patientId
			<< setw(14) << doctorId
			<< setw(15) << date
			<< setw(10) << time
			<< setw(15) << status
		    << setw(15) << paymentMethod
			<< setw(20) << paymentStatus
			<< '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));
		Console::cyan();

	}



	void Appointment::printHeader() {

		Console::white();
		cout << endl << left
			<< setw(8) << "ID"
			<< setw(14) << "Patient ID"
			<< setw(14) << "Doctor ID"
			<< setw(15) << "Date"
			<< setw(10) << "Time"
			<< setw(15) << "Status"
			<< setw(15) << "payment"
			<< setw(20) << "Payment Status"
			<< '\n';
		Console::cyan();
		cout << string(105, '-') << '\n';
	}


