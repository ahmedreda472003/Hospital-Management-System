#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
using namespace std;
class Console
{

public:


    static void cyan() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); }   // لون البرنامج

    static void green() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); }    // النجاح

    static void red() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); }      // الخطا

    static void white() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); }    //  المستخدم و عناوين

    static void lightGray() { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); }    //  

    static void error(const string& message) {
        red();
        cout << "✘ " << message << '\n';
        cyan();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    static void success(const string& message) {
        green();
        cout << "✓ " << message << '\n';
        cyan();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }








};

