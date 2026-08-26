#include "MedicalRecordManager.h"
vector<MedicalRecord> MedicalRecordManager::records;


    // Data

    void  MedicalRecordManager::addMedicalRecord(const MedicalRecord& record)
    {
        records.push_back(record);
    }

    vector<MedicalRecord>& MedicalRecordManager::getMedicalRecords() {

        return records;

    }



    // Search

    MedicalRecord* MedicalRecordManager::searchMedicalRecord(int appointmentId) {

        for (MedicalRecord& record : records) {
            if (record.getAppointmentId() == appointmentId) {
                return &record;
            }
        }
        return nullptr;

    }



    // Medical Record Management

    void MedicalRecordManager::createMedicalRecord(Doctor* doctor) {

        int appointmentId = DataEntry::enterId("Appointment");

        Appointment* a = AppointmentManager::searchAppointment(appointmentId);

        if (a == nullptr)
        {
            Console::error("Appointment not found.\n");
            return;
        }

        if (doctor->getId() != a->getDoctorId())
        {
            Console::error("You are not allowed to create a medical record for this appointment.\n");
            return;
        }

        if (a->getStatus() != "Completed")
        {
            Console::error("Medical records can only be created for completed appointments.\n");
            return;
        }

        if (MedicalRecordManager::searchMedicalRecord(appointmentId) != nullptr)
        {
            Console::error("A medical record already exists for this appointment.\n");
            return;
        }

        string diagnosis = DataEntry::enterDiagnosisMedicalRecord();
        string prescription = DataEntry::enterPrescriptionMedicalRecord();
        string notes = DataEntry::enterNotesMedicalRecord();

        string status = "Active";

        MedicalRecord record(appointmentId, a->getPatientId(), a->getDoctorId(), diagnosis, prescription, notes, status);

        FileManager::addMedicalRecord(record);

        Console::success("Medical record created successfully.\n");



    }

    bool  MedicalRecordManager::deleteRecord(int appointmentId) {

        for (MedicalRecord& record : records) {
            if (record.getAppointmentId() == appointmentId) {
                record.setStatus("Archived");
                return true;
            }
        }
        return false;
    }




    // View

    void  MedicalRecordManager::viewRecord(int appointmentId) {
        MedicalRecord::printHeader();
        for (MedicalRecord& record : records) {
            if (record.getAppointmentId() == appointmentId) {
                record.display();
            }
        }

    }

    void  MedicalRecordManager::viewRecords() {

        for (MedicalRecord& record : records) {
            record.display();

        }

    }

    bool MedicalRecordManager::listMedicalRecordsByDoctor(int doctorId)
    {
        bool found = false;

        const auto& records = MedicalRecordManager::getMedicalRecords();
        MedicalRecord::printHeader();
        for (const MedicalRecord& record : records)
        {
            if (record.getDoctorId() == doctorId)
            {
                record.display();
                found = true;
            }
        }

        return found;
    }

    bool MedicalRecordManager::listMedicalRecordsByPatient(int patientId)
    {
        bool found = false;

        const auto& records = MedicalRecordManager::getMedicalRecords();

        MedicalRecord::printHeader();
        for (const MedicalRecord& record : records)
        {
            if (record.getPatientId() == patientId)
            {
                record.display();
                found = true;
            }
        }

        return found;
    }

    bool  MedicalRecordManager::viewMedicalRecordsPatient(int patientId) {

        bool found = false;

        MedicalRecord::printHeader();
        for (MedicalRecord& m : records) {

            if (m.getPatientId() == patientId) {

                m.display();
                found = true;

            }
        }

        return found;

    }




