#include "Transaction.h"



  Transaction::Transaction(string senderAccount, string receiverAccount, double amount, string type, string dateTime )
    : senderAccount(senderAccount), receiverAccount(receiverAccount), amount(amount), type(type), dateTime(dateTime) {
}


// Getters
  string Transaction::getSenderAccount() const
{
    return senderAccount;
}

  string Transaction::getReceiverAccount() const
{
    return receiverAccount;
}

  double Transaction::getAmount() const
{
    return amount;
}

  string Transaction::getType() const
{
    return type;
}

  string Transaction::getDateTime() const
{
    return dateTime;
}



  void Transaction::printHeader()
{
    Console::white();

    cout << endl << left
        << setw(18) << "Sender"
        << setw(18) << "Receiver"
        << setw(12) << "Amount"
        << setw(25) << "Type"
        << setw(22) << "Date & Time" << endl;
    Console::cyan();
    cout << string(95, '-') << endl;
}

  void Transaction::display() const
    {
        Console::white();
        cout << left
            << setw(18) << getSenderAccount()
            << setw(18) << getReceiverAccount()
            << setw(12) << getAmount()
            << setw(25) << getType()
            << setw(22) << getDateTime()
            << endl;
        Console::cyan();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }





