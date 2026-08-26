#include "Screens.h"





	 void Screens::welcome() {
		 Console::cyan();

		 cout << R"(         
                        __       __  ________  __         ______    ______   __       __  ________  
                       /  |  _  /  |/        |/  |       /      \  /      \ /  \     /  |/        | 
                       $$ | / \ $$ |$$$$$$$$/ $$ |      /$$$$$$  |/$$$$$$  |$$  \   /$$ |$$$$$$$$/  
                       $$ |/$  \$$ |$$ |__    $$ |      $$ |  $$/ $$ |  $$ |$$$  \ /$$$ |$$ |__     
                       $$ /$$$  $$ |$$    |   $$ |      $$ |      $$ |  $$ |$$$$  /$$$$ |$$    |    
                       $$ $$/$$ $$ |$$$$$/    $$ |      $$ |   __ $$ |  $$ |$$ $$ $$/$$ |$$$$$/     
                       $$$$/  $$$$ |$$ |_____ $$ |_____ $$ \__/  |$$ \__$$ |$$ |$$$/ $$ |$$ |_____  
                       $$$/    $$$ |$$       |$$       |$$    $$/ $$    $$/ $$ | $/  $$ |$$       | 
                       $$/      $$/ $$$$$$$$/ $$$$$$$$/  $$$$$$/   $$$$$$/  $$/      $$/ $$$$$$$$/  
 )";
		 Console::lightGray();
		 cout << R"(        
                                 ________  ______         ________  __    __  ________ 
                                /        |/      \       /        |/  |  /  |/        |
                                $$$$$$$$//$$$$$$  |      $$$$$$$$/ $$ |  $$ |$$$$$$$$/ 
                                   $$ |  $$ |  $$ |         $$ |   $$ |__$$ |$$ |__    
                                   $$ |  $$ |  $$ |         $$ |   $$    $$ |$$    |   
                                   $$ |  $$ |  $$ |         $$ |   $$$$$$$$ |$$$$$/    
                                   $$ |  $$ \__$$ |         $$ |   $$ |  $$ |$$ |_____ 
                                   $$ |  $$    $$/          $$ |   $$ |  $$ |$$       |
                                   $$/    $$$$$$/           $$/    $$/   $$/ $$$$$$$$/                                                                                                                                                                                                                                                                              
 )";
		 Console::cyan();
		 cout << R"(             
                        __    __   ______    ______   _______   ______  ________  ______   __       
                       /  |  /  | /      \  /      \ /       \ /      |/        |/      \ /  |      
                       $$ |  $$ |/$$$$$$  |/$$$$$$  |$$$$$$$  |$$$$$$/ $$$$$$$$//$$$$$$  |$$ |      
                       $$ |__$$ |$$ |  $$ |$$ \__$$/ $$ |__$$ |  $$ |     $$ |  $$ |__$$ |$$ |      
                       $$    $$ |$$ |  $$ |$$      \ $$    $$/   $$ |     $$ |  $$    $$ |$$ |      
                       $$$$$$$$ |$$ |  $$ | $$$$$$  |$$$$$$$/    $$ |     $$ |  $$$$$$$$ |$$ |      
                       $$ |  $$ |$$ \__$$ |/  \__$$ |$$ |       _$$ |_    $$ |  $$ |  $$ |$$ |_____ 
                       $$ |  $$ |$$    $$/ $$    $$/ $$ |      / $$   |   $$ |  $$ |  $$ |$$       |
                       $$/   $$/  $$$$$$/   $$$$$$/  $$/       $$$$$$/    $$/   $$/   $$/ $$$$$$$$/                                                                                                                                                                                                                                                
)";



		 std::this_thread::sleep_for(std::chrono::seconds(2));
		 Console::cyan();
	 }




	 void Screens::showMainMenu() {
		 cout << "\n═════════════════════════════════════════\n";
		 Console::white();
		 cout << "   🏥   HOSPITAL MANAGEMENT SYSTEM ";
		 Console::cyan();
		 cout << "\n═════════════════════════════════════════\n\n";

		 Console::white();
		 cout << "Main Menu\n";
		 Console::cyan();
		 cout << "─────────────────────────\n";

		 cout << "▸ [1] Sign In\n\n";

		 Console::white();
		 cout << "Exit\n";
		 Console::cyan();
		 cout << "─────────────────────────\n";
		 Console::red();
		 cout << "■ [0] Exit\n\n";
		 Console::lightGray();
		 cout << "➜ Select an option: ";

	 }



	 int Screens::getMainMenuChoice()
	 {
		 while (true)
		 {
			 showMainMenu();

			 int choice;

			 Console::white();
			 cin >> choice;
			 cin.ignore();
			 Console::cyan();

			 switch (choice)
			 {
			 case 1:
				 return 1;

			 case 0:
				 return 0;
				 break;

			 default:
				 Console::error("Invalid Choice.\n");
			 }
		 }
	 }



	 void Screens::loginOptions()
	 {
		 cout << "\n═════════════════════════════════════════\n";
		 Console::white();
		 cout << "             LOGIN OPTIONS";
		 Console::cyan();
		 cout << "\n═════════════════════════════════════════\n\n";


		 cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		 cout << "┃ ▸ [1] Manager              ┃\n";
		 cout << "┃ ▸ [2] Admin                ┃\n";
		 cout << "┃ ▸ [3] Doctor               ┃\n";
		 cout << "┃ ▸ [4] Patient              ┃\n";
		 cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n";
		 Console::red();
		 cout << "↩ [0] Back\n\n";
		 Console::lightGray();
		 cout << "➜ Select an option: ";
	 }



	 int Screens::loginAs() {

		 while (true) {

			 loginOptions();
			 int choice;
			 Console::white();
			 cin >> choice;
			 cin.ignore();
			 Console::cyan();

			 switch (choice) {

			 case 1:
				 return 1;
				 break;

			 case 2:
				 return 2;
				 break;

			 case 3:
				 return 3;
				 break;

			 case 4:
				 return 4;
				 break;

			 case 0:
				 return 0;
				 break;
			 default:
				 Console::error("Invalid option. Please choose a number from the menu.\n");
				 break;
			 }
		 }

	 }



	 void Screens::welcomeUser(const string& name)
	 {
		 cout << "\n─────────────────────────────────────────\n";
		 Console::lightGray();
		 cout << "       Welcome , " << name << "!\n";
		 cout << " You have successfully signed in. ";
		 Console::cyan();
		 cout << "\n─────────────────────────────────────────\n";

		 std::this_thread::sleep_for(std::chrono::seconds(1));
	 }



	 void Screens::loginScreen(int c) {

		 if (c == 0) {
			 return;
		 }
		 int id;
		 Console::lightGray();
		 cout << "\nid       : ";

		 Console::white();
		 cin >> id;
		 cin.ignore();

		 Console::lightGray();
		 cout << "\npassword : ";

		 Console::white();
		 string pass = Validation::inputPassword();
		 Console::cyan();

		 if (c == 1) {

			 Manager* m = ManagerService::login(id, pass);



			 if (m != nullptr) {

				 welcomeUser(m->getName());
				 while (ManagerService::managerOptions(m));

			 }
			 else {
				 invalid(1);
			 }


		 }
		 else if (c == 2) {


			 Admin* a = AdminManager::login(id, pass);



			 if (a != nullptr) {

				 welcomeUser(a->getName());
				 while (AdminManager::adminOptions(a));

			 }
			 else {
				 invalid(2);
			 }

		 }
		 else if (c == 3) {

			 Doctor* d = DoctorManager::login(id, pass);

			 if (d != nullptr) {

				 welcomeUser(d->getName());
				 while (DoctorManager::doctorOptions(d));

			 }
			 else {
				 invalid(3);
			 }

		 }
		 else if (c == 4) {

			 Patient* p = PatientManager::login(id, pass);

			 if (p != nullptr) {

				 welcomeUser(p->getName());
				 while (PatientManager::patientOptions(p));

			 }
			 else {
				 invalid(4);
			 }
		 }

	 }



	 void Screens::invalid(int c) {

		 Console::error("Wrong id or password!");
		 loginScreen(c);

	 }




	 void Screens::runApp() {
		FileManager::fetchAllData();
		welcome();
		while (true)
		{
			int choice = getMainMenuChoice();

			if (choice == 0)
				break;

			loginScreen(loginAs());
		}

	}






