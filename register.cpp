#include <Windows.h>
#include <iostream>
#include <fstream>

int regisz(std::string name , std::string yo) {
	std::fstream myFile;
	myFile.open(name, std::ios::out);
	if (myFile.is_open()) {
		myFile << "Username : " << name;
		myFile << "\nBirthday : " << yo;
		myFile.close();
	}
	return 0;
}