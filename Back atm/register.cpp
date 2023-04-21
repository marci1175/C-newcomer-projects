#include <Windows.h>
#include <iostream>
#include <fstream>
#include <ctime>
#pragma warning(disable : 4996)
int regisz(std::string name , std::string yo) {
	std::fstream myFile;
	myFile.open(name, std::ios::out);
	if (myFile.is_open()) {
		//write pass
		myFile << yo;

		//write bal
		myFile << "\n0";

		//get, write time
		time_t now = time(0);
		tm* gmtm = gmtime(&now);
		myFile << "\n" << asctime(gmtm);
		
		//close
		
		myFile.close();
		
	}
	return 0;
}