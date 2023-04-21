#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "acchandler.h"
std::string currmoney;
std::string dontes;
//iso::in
int login(std::string lname, std::string lyo) {
	system("CLS");
	std::fstream myFile;
	try {
		myFile.open(lname, std::ios::in);
		if (myFile.is_open()) {
			std::string sa;
			std::string date;
			std::getline(myFile, sa);
			std::getline(myFile, currmoney);
			std::getline(myFile, date);
			myFile.close();
			if (sa == lyo) {
				std::cout << "You are logged in as "<< lname << ", choose action!               [0] Logout\n";
				//account actions
				std::cout << "\n1) Deposit money\n2) Withdraw money\n3) Delete account\n4) Send money(beta)\n";
				//acount details
				std::cout << "\n\n\nAccount details: \nBalance : " << currmoney << std::endl;
				std::cout << "Account registration date : " << date <<std::endl;
				
				std::getline(std::cin >> std::ws, dontes);
				acchandler(dontes,lname,currmoney,lyo);
				
			}
			else {
				std::cout << "invalid password! returning. . .\n";
				Sleep(2000);
			}
			
		}
		else { throw 56; }
	}
	catch (int e)
	{
		std::cout << "User not found! Register first.\nReturning in 3 seconds. . .";
		Sleep(3000);
	}
	
	return 0;
}