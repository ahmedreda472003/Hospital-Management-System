#pragma once
#include <vector>
#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Admin.h"
using namespace std;
class HospitalSystem
{
private:
	static vector<Patient>  patients;
	static vector<Doctor>  doctors;
	static vector<Admin>  admins;
public:

	static void setVectorPatient(const vector<Patient>& patients) {
		HospitalSystem::patients = patients;
	}

	static void setVectorDoctor(const vector<Doctor>& doctors) {
		HospitalSystem::doctors = doctors;
	}

	static void setVectorAdmin(const vector<Admin>& admins) {
		HospitalSystem::admins = admins;
	}


	
	static const vector<Patient>& getVectorPatient() {
		return patients;
	}

	static const vector<Doctor>& getVectorDoctor() {
		return doctors;
	}

	static const vector<Admin>& getVectorAdmin() {
		return admins;
	}


};

