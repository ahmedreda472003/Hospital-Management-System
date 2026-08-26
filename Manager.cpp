#include "Manager.h"



    Manager::Manager(int id, string& name, string& password, BankAccount& account) :
    	Person(id, name, password, account) {
    }





  void Manager::display() const {
	Console::white();
	cout << left
		<< setw(8) << id
		<< setw(20) << name
		<< '\n';
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Console::cyan();
}


  void Manager::printManagerHeader() {

	Console::white();
	cout << endl << left
		<< setw(8) << "ID"
		<< setw(20) << "Name"
		<< '\n';
	Console::cyan();
	cout << string(57, '-') << '\n';

}

