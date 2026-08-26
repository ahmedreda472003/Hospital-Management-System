#include "PaymentManager.h"



void PaymentManager::viewPendingPayments()
{
    auto& appointments = AppointmentManager::getAppointments();

    bool found = false;
    int i = 0 ; 

    for (Appointment& a : appointments)
    {
        if (a.getPaymentMethod() == "Cash" &&
            a.getPaymentStatus() == "Pending")
        {
            i += 1;
            if (!found && i == 1)
            {
                Appointment::printHeader();
                found = true;
            }

            a.display();
        }
    }

    if (!found)
    {

        Console::error("No pending cash payments found.\n");
       
    }

   
}



void PaymentManager::confirmCashPayment()
{
    auto& appointments = AppointmentManager::getAppointments();

    int appointmentId = DataEntry::enterId("appointmentId");

    for (Appointment& a : appointments)
    {
        if (a.getAppointmentId() == appointmentId)
        {
            // Check Payment Method
            if (a.getPaymentMethod() != "Cash")
            {
                Console::error("This appointment is not a Cash payment.\n");
                return;
            }

            // Check Payment Status
            if (a.getPaymentStatus() == "Completed")
            {
                Console::error("Payment has already been confirmed.\n");
                return;
            }

            // Get Doctor
            Doctor* doctor = DoctorManager::searchDoctor(a.getDoctorId());

            if (doctor == nullptr)
            {
                Console::error("Doctor not found.\n");
                return;
            }



            // Consultation Fee
            double consultationFee = doctor->getConsultationFee();



            // Add full payment to Hospital Account
            HospitalData::getHospitalAccount().deposit(consultationFee);


            // Doctor's Entitlement = 30%
            double doctorEntitlement = consultationFee * 0.30;

            FileManager::addFinancialEntitlement(
                doctor->getId(),
                doctorEntitlement
            );



            // Update Payment Status
            a.setPaymentStatus("Completed");
            FilesHelper::updateAppointments();


            // Save Hospital Account
            FilesHelper::saveHospitalAccount(
                HospitalData::getHospitalAccount()
            );



            // Record Transaction
            Transaction transaction(
                "Reception",
                HospitalData::getHospitalAccount().getAccountNumber(),
                consultationFee,
                "Appointment Payment"
            );

            FileManager::addTransaction(transaction);

            Console::success("Cash payment confirmed successfully.\n");
            return;
        }
    }

    Console::error("Appointment not found.\n");
}



