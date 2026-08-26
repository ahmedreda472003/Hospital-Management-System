#include "TransactionManager.h"



     void TransactionManager::listTransactions()
     {
         auto& transactions = HospitalData::getTransactions();

         if (transactions.empty())
         {
             Console::error("No transactions found.\n");
             return;
         }

         Transaction::printHeader();

         for (const auto& transaction : transactions)
         {
             transaction.display();
         }
         cout << endl << endl;
     }


     double TransactionManager::getTotalByType(const string& type)
     {
         double total = 0;

         auto& transactions = HospitalData::getTransactions();

         for (const auto& transaction : transactions)
         {
             if (transaction.getType() == type)
             {
                 total += transaction.getAmount();
             }
         }

         return total;
     }




     double TransactionManager::totalRevenue()
     {
         return getTotalByType("Appointment Payment");
     }


     double TransactionManager::refundedAmounts()
     {
         return getTotalByType("Refund");
     }


     double TransactionManager::doctorsSalaries()
     {
         return getTotalByType("Doctor Salary");
     }


     double TransactionManager::adminsSalaries()
     {
         return getTotalByType("Admin Salary");
     }


     double TransactionManager::doctorsDueEntitlements()
     {
         return getTotalByType("Doctor Entitlement");
     }


     int TransactionManager::numberOfOperations()
     {

         return HospitalData::getTransactions().size();


     }



     void TransactionManager::financialSummary() {


        cout << "\n═══════════════════════════════════════════════════════\n";
        Console::white();
        cout << "                FINANCIAL SUMMARY";
        Console::cyan();
        cout << "\n═══════════════════════════════════════════════════════\n\n";

        cout << left;

        cout << setw(35) << "Total Revenue            :";

        Console::white();
        cout << totalRevenue() << endl;

        Console::cyan();
        cout << setw(35) << "Refunded Amounts         :";

        Console::white();
        cout << refundedAmounts() << endl;

        Console::cyan();
        cout << setw(35) << "Doctors' Salaries Paid   :";

        Console::white();
        cout << doctorsSalaries() << endl;

        Console::cyan();
        cout << setw(35) << "Admins' Salaries Paid    :";

        Console::white();
        cout << adminsSalaries() << endl;

        Console::cyan();
        cout << setw(35) << "Doctors' Due Entitlements:";

        Console::white();
        cout << doctorsDueEntitlements() << endl;

        Console::cyan();
        cout << setw(35) << "Total Transactions       :";

        Console::white();
        cout << numberOfOperations() << endl;

        Console::cyan();
        cout << "\n═══════════════════════════════════════════════════════";

        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << endl << endl;

    }




