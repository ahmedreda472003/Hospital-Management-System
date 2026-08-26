#pragma once
#include "HospitalData.h"
#include "DataEntry.h"
#include "FilesHelper.h"
#include "FileManager.h"
#include "Manager.h"
#include "AdminManager.h"
#include "TransactionManager.h"
#include <algorithm>
class ManagerService
{
private:

    static bool deleteAdmin(int id);

public:

    // Menus

    static void printManagerMenu();

    static void printAdminManagementMenu();

    static void printHospitalAccountMenu();

    static void printPayrollMenu();

    static void printReportsMenu();

    static void printUpdateAdminMenu();




    // Authentication

    static Manager* login(int id, string password);



    // Admin Management

    static void addAdmin();

    static void removeAdmin();




    // Payroll

    static void payDoctor();

    static void payAdmin();

    static void updateDoctorSalary();

    static void updateAdminSalary();



    // Financial Entitlements

    static bool hasFinancialEntitlement(int doctorId);

    static double getFinancialEntitlement(int doctorId);

    static bool deductFinancialEntitlement(int doctorId, double amount);


    static void listDoctorsEntitlements();

    static void payDoctorEntitlements();



    // Menu Options

    static bool managerOptions(Manager* manager);

    static bool adminManagementOptions();

    static bool hospitalManagementOptions();

    static bool payrollManagementOptions();

    static bool reportManagementOptions();

    static bool updateAdminOptions();



};
    

