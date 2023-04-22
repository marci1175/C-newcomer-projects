#include <iostream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "depositm.h"
#include "wdmoney.h"
#include "login.h"
#include "deleteacc.h"
#include "sendmon.h"
//recip
int sendmon(std::string dontes, std::string lname, std::string currmoney, std::string lyo) {
	std::cout << "Transfer money" << std::endl;
	std::cout << "\nEnter the amount of money you want to trasnfer :\n";

	std::string valstr;
	std::getline(std::cin >> std::ws, valstr);

	//valstr into int =>
	int val = std::stoi(valstr);
	if (val < 0) {
		std::cout << "You cannot trasnfer a negative amount of data! Returning in 3 seconds";
		Sleep(3000);
		login(lname, lyo);
	}
	std::fstream file(lname, std::ios::in | std::ios::out);  // open file in read and write mode
	std::string line;
	if (file.is_open()) {
		std::vector <std::string> lines;
		while (std::getline(file, line)) {
			lines.push_back(line);
		}
		std::string curr;
		int veg;

		curr = lines[1];

		int curr_veg = std::stoi(curr);

		veg = curr_veg - val;
		if (veg < 0) {
			std::cout << "Negative balance detected! Transfer will not go trough. Returning in 3 seconds. . .";
			Sleep(3000);
			login(lname, lyo);
		}
		std::string veg_string = std::to_string(veg);
		lines[1] = veg_string;
		std::cout << "Deposit complete\nYour balance was : " << curr << "\nYour balance now : " << veg_string << std::endl;
		file.flush();
		file.close();
		//CLOSEPREVFILE---------------
		//reopenIT--------------------
		std::fstream file(lname, std::ios::in | std::ios::out);  // open file in read and write mode
		std::string line;
		file.seekp(0); // set the file pointer to the beginning of the file
		for (const auto& line : lines) {
			file << line << std::endl;
		}

		//current money std::string currmoney;

		if (file.fail() || file.bad()) {
			// print out error message if any errors occur
			perror("Error occurred while writing to file");
		}
		else {
			// couninue with changing the recepients bal: ___________________________



			std::cout << "Enter recepient's username : \n";
			std::string recip;
			std::getline(std::cin >> std::ws, recip);


			//RECIP FILE MODI-----------------------------------------------
			std::fstream file(recip, std::ios::in | std::ios::out);  // open file in read and write mode
			std::string line;
			if (file.is_open()) {

				std::vector <std::string> lines;
				while (std::getline(file, line)) {
					lines.push_back(line);
				}
				std::string curr;
				int veg;

				curr = lines[1];

				int curr_veg = std::stoi(curr);

				veg = curr_veg + val;
				std::string veg_string = std::to_string(veg);
				lines[1] = veg_string;
				file.flush();
				file.close();
				//CLOSEPREVFILE---------------
				//reopenIT--------------------

				std::fstream file(recip, std::ios::in | std::ios::out);  // open file in read and write mode
				std::string line;
				file.seekp(0); // set the file pointer to the beginning of the file
				for (const auto& line : lines) {
					file << line << std::endl;
				}

				//current money std::string currmoney;

				if (file.fail() || file.bad()) {
					// print out error message if any errors occur
					perror("Error occurred while writing to file");
					Sleep(3000);
					login(lname, lyo);
				}
				else {
					// flush the file stream and close the file
					file.flush();
					file.close();
					std::cout << "Returning in 3 seconds. . .";
					Sleep(3000);

					login(lname, lyo);
				}


			}
			else {
				std::cout << "User not found, reverting changes. . .\n";
				std::cout << "Returning in 3 seconds. . .";
				std::fstream file(lname, std::ios::in | std::ios::out);  // open file in read and write mode
				std::string line;
				if (file.is_open()) {
					std::vector <std::string> lines;
					while (std::getline(file, line)) {
						lines.push_back(line);
					}
					std::string curr;
					int veg;

					curr = lines[1];

					int curr_veg = std::stoi(curr);

					veg = curr_veg + val;
					std::string veg_string = std::to_string(veg);
					lines[1] = veg_string;
					file.close();
					file.flush();

					//REOPEN

					std::fstream file(lname, std::ios::in | std::ios::out);  // open file in read and write mode
					std::string line;
					file.seekp(0); // set the file pointer to the beginning of the file
					for (const auto& line : lines) {
						file << line << std::endl;
					}
					if (file.fail() || file.bad()) {
						// print out error message if any errors occur
						perror("Error occurred while writing to file : ");
						Sleep(3000);
						login(lname, lyo);
					}
					else {
						// flush the file stream and close the file
						file.flush();
						file.close();
						Sleep(3000);

						login(lname, lyo);
					}				
				}
			}




		}
	}

	else {
		//line 28
		perror("An error occured while opening the file :");
		std::cout << "Returning in 3 seconds. . .";
		Sleep(3000);
		login(lname, lyo);
	}
	return 0;
}
