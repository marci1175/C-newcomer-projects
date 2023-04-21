#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "main.h"
#include "login.h"
int deleteacc(std::string dontes, std::string lname, std::string currmoney, std::string lyo) {
	std::cout << "Enter your password to delete your account!\n";
	std::fstream myFile;
	myFile.open(lname, std::ios::in | std::ios::out);
	if (myFile.is_open()) {
		std::string sa;
		std::string currmoney;
		std::string date;
		std::getline(myFile, sa);
		std::getline(myFile, currmoney);
		std::getline(myFile, date);
		myFile.close();
		if (sa == lyo) {
			//IF CORR PASS
			std::cout << "Are you sure?\n	Yes/No \n(CASE SENSITIVE)";
			std::string acdel;
			std::getline(std::cin >> std::ws, acdel);
			if (acdel == "Yes") {
				char fileName[20];
				std::cout << "Enter your username : ";
				std::cin >> fileName;
				int status;
				status = remove(fileName);
				if (status == 0) {
					std::cout << "\nFile Deleted Successfully!\nExiting in 3 seconds. . .";
					Sleep(3000);
					main();
				}
				else {
					std::cout << "\nError Occurred!";
				}
			}
			else {
				std::cout << "No, or incorrect keyword was given, returning. . .\n";
				Sleep(2000);
				login(lname, lyo);
			}

		}
		else {
			//IF INCORR PASS
		}
	}
	return 0;
}