#pragma once
#include "Files.h"
#include "DateTime.h"
#include "Console.h"
class Transaction
{
private:
    int id;
    string senderAccount;
    string receiverAccount;
    double amount;
    string type;
    string dateTime ;

public:

    Transaction(string senderAccount, string receiverAccount, double amount, string type, string dateTime = DateTime::getCurrentDateTime());
       
   

    // Getters
    string getSenderAccount() const;

    string getReceiverAccount() const;

    double getAmount() const;

    string getType() const;

    string getDateTime() const;



    static void printHeader();

    void display() const;



};

