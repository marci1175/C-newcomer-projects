#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "login.cpp"
#include "register.h"
int action;
bool access;
std::string name;
std::string yo;
int main()
{

    while (access = true) {
    std::cout << "Welcome, user!\n";
    std::cout << "\n\nSelect action: \n\n1)Login\n\n2)Register\n";
    std::cin >> action;
    if (action == 1){
    
    }
    else if (action == 2) {
        system("CLS");
        std::cout << "Register"<<std::endl;
        std::cout << "\nEnter your Username :\n";
        std::cin;
        std::getline(std::cin, name);
        std::cout << "\nEnter your birthday : \n";
        std::cin;
        std::getline(std::cin, yo);
        regisz(name, yo);
    }
    else {
        std::cout << "\nYou have selected an invalid option!\n";
        break;
    }
    }
}

