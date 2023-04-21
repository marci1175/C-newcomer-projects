#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "depositm.h"
#include "wdmoney.h"
#include "login.h"
int mon;
int depositm(std::string dontes, std::string lname, std::string currmoney,std::string lyo) {
	system("CLS");
	std::cout << "Deposit";
	std::cout << "\n\nEnter the amount of money you want to deposit : ";

	std::cin >> mon;
	if (mon < 0) {
		std::cout << "You have entered a negative number, if you want to withdraw enter 2\n\n\nReturning in 3 seconds . . .";
		Sleep(3000);
		login(lname, lyo);
	}
	else {
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

			veg = curr_veg + mon;
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
				// flush the file stream and close the file
				file.flush();
				file.close();
				std::cout << "Returning in 3 seconds. . .";
				Sleep(3000);
				
				login(lname, lyo);
			}


		}
		else {
			std::cout << "Failed to open";
		}

	}
	return 0;
}