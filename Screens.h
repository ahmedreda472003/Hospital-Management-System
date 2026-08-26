#pragma once
#include "Console.h"
#include "FileManager.h"
#include "DoctorManager.h"
#include "PatientManager.h"
#include "AdminManager.h"
#include "ManagerService.h"

class Screens
{
public:

	static void welcome();
	

    static void showMainMenu();


	static int getMainMenuChoice();


	static void loginOptions();


	static int loginAs();


	static void welcomeUser(const string& name);



	static void loginScreen(int c);



	static void invalid(int c);


	static void runApp();




};

