#pragma once
#include"Transaction.h"
#include "HospitalData.h"
class TransactionManager
{
public:


    static void listTransactions();


    static double getTotalByType(const string& type);




    static double totalRevenue();


    static double refundedAmounts();


    static double doctorsSalaries();


    static double adminsSalaries();


    static double doctorsDueEntitlements();


    static int numberOfOperations();



    static void financialSummary();



};

