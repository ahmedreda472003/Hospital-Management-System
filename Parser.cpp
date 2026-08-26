#include "Parser.h"



     // Utility      
 
     vector<string> Parser::split(string line, char delimiter = '-') {

         vector<string> data;

         while (line.find(delimiter) != string::npos)
         {
             long long pos = line.find(delimiter);

             string element = line.substr(0, pos);

             data.push_back(element);

             line.erase(0, pos + 1);
         }


         data.push_back(line);

         return data;

     }



     // Accounts

     BankAccount Parser::parseToHospitalAccount(string line)
     {
         vector<string> data = split(line);

         return BankAccount(data[0], stod(data[1]));
     }



     // Users

     Patient Parser::parseToPatient(string line) {
         vector <string> data;
         data = split(line);
         BankAccount account(data[4], stod(data[5]));
         return { stoi(data[0]), data[1], data[2], data[3] , account };
     }

     Doctor Parser::parseToDoctor(string line) {

         vector <string> data;
         data = split(line);

         BankAccount account(data[5], stod(data[6]));
         double consultationFee = stod(data[7]);

         return { stoi(data[0]), data[1], data[2], data[3] , stod(data[4]) , account , consultationFee };

     }

     Admin Parser::parseToAdmin(string line) {

         vector <string> data;
         data = split(line);
         BankAccount account(data[4], stod(data[5]));
         return { stoi(data[0]), data[1], data[2] , stod(data[3]) , account };

     }

     Manager Parser::parseToManager(string line) {

         vector <string> data;
         data = split(line);
         BankAccount account(data[3], stod(data[4]));
         return { stoi(data[0]), data[1], data[2] ,  account };

     }




     // Appointments

     Appointment Parser::parseToAppointment(string line) {

         vector <string> data;
         data = split(line);
         return { stoi(data[0]),stoi(data[1]),stoi(data[2]) , data[3], data[4], data[5] ,data[6] , data[7] };

     }



     // Medical Records

     MedicalRecord Parser::parseToMedicalRecord(string line) {

        vector <string> data;
        data = split(line);
        return { stoi(data[0]),stoi(data[1]),stoi(data[2]) , data[3], data[4], data[5] , data[6] };

     }



     // Transactions

     Transaction Parser::parseToTransaction(string line) {

         vector <string> data;
         data = split(line);
         return { data[0], data[1],stod(data[2]) , data[3] , data[4] };

     }


     // Financial

     pair<int, double> Parser::parseToFinancialEntitlement(string line)
     {
         vector<string> data = split(line);

         return { stoi(data[0]), stod(data[1]) };
     }