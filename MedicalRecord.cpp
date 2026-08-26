#include "MedicalRecord.h"



    MedicalRecord::MedicalRecord(int appointmentId, int patientId, int doctorId,
        const string& diagnosis, const string& prescription, const string& notes, const string& status) :
        appointmentId(appointmentId), patientId(patientId), doctorId(doctorId),
        diagnosis(diagnosis), prescription(prescription), notes(notes), status(status) {
    }


    bool MedicalRecord::MedicalRecord::setDiagnosis(const string& diagnosis) {
        if (diagnosis.empty()) return false;

        this->diagnosis = diagnosis;
        return true;
    }

    bool MedicalRecord::setPrescription(const string& prescription) {
        if (prescription.empty()) return false;
        this->prescription = prescription;
        return true;

    }

    bool MedicalRecord::setNotes(const string& notes) {
        if (notes.empty()) return false;

        this->notes = notes;
        return true;
    }

    bool MedicalRecord::setStatus(const string& status) {

        if (Validation::validStatusMedicalRecord(status)) {
            this->status = status;
            return true;
        }
        return false;
    }


    int MedicalRecord::getAppointmentId() const {
        return appointmentId;
    }

    int MedicalRecord::getPatientId() const {
        return patientId;
    }

    int MedicalRecord::getDoctorId() const {
        return doctorId;
    }

    string MedicalRecord::getDiagnosis() const {
        return diagnosis;
    }

    string MedicalRecord::getPrescription() const {
        return prescription;
    }

    string MedicalRecord::getNotes() const {
        return notes;
    }

    string MedicalRecord::getStatus() const {
        return status;
    }


    void MedicalRecord::display() const
    {
        Console::white();
        cout << left
            << setw(8) << appointmentId
            << setw(13) << patientId
            << setw(13) << doctorId
            << setw(18) << diagnosis
            << setw(18) << prescription
            << setw(12) << notes
            << setw(7) << status
            << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Console::cyan();

    }

     void MedicalRecord::printHeader()
    {
        Console::white();
        cout << endl << left
            << setw(8) << "ID"
            << setw(13) << "Patient ID"
            << setw(13) << "Doctor ID"
            << setw(18) << "Diagnosis"
            << setw(18) << "Prescription"
            << setw(12) << "Notes"
            << setw(12) << "Status"
            << '\n';
        Console::cyan();
        cout << string(92, '-') << '\n';


    }



