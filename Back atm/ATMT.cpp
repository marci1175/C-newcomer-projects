#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "login.h"
#include "register.h"
int action;
bool access;
//register
std::string name;
std::string yo;
//login
std::string lname;
std::string lyo;
int main()
{
    while (access = true) {
    system("CLS");
    std::cout << "Welcome, user!\n";
    std::cout << "\n\nSelect action: \n\n1)Login\n\n2)Register\n";
    std::cin >> action;
    if (action == 1){
        system("CLS");
        std::cout << "Login";
        std::cout << "\nEnter username :";
        std::getline(std::cin >> std::ws, lname);
        std::cout << "\nEnter password :";
        std::getline(std::cin >> std::ws, lyo);
        login(lname, lyo);
    }
    else if (action == 2) {
        system("CLS");
        std::cout << "Register"<<std::endl;
        std::cout << "\nEnter your Username :\n";
        std::getline(std::cin >> std::ws, name);
        std::cout << "\nEnter your custom password (Please dont use special characters!) : \n";
        std::getline(std::cin >> std::ws, yo);
        regisz(name, yo);
    }
    else {
        std::cout << "\nYou have selected an invalid option!\n";
        break;
    }
    }
}

