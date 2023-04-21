#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "depositm.h"
#include "wdmoney.h"
#include "login.h"
#include "deleteacc.h"
#include "sendmon.h"
#include "main.h"
//2int 3string
//1) Deposit money\n2) Withdraw money\n3) Delete account\n4) Send money(beta)
int acchandler(std::string dontes, std::string lname,std::string currmoney,std::string lyo) {
	//LOGOUT
	if (dontes == "0") {
		system("CLS");
		main();
	}
	//REST
	if (dontes == "1") {
		system("CLS");
		depositm(dontes, lname, currmoney, lyo);
	}
	if (dontes == "2") {
		system("CLS");
		wdmon(dontes, lname, currmoney, lyo);
	}
	if (dontes == "3") {
		system("CLS");
		deleteacc(dontes, lname, currmoney, lyo);
	}
	if (dontes == "4") {
		system("CLS");
		sendmon(dontes, lname, currmoney, lyo);
	}
	else
	{
		std::cout << "Invalid action, returning in 3 seconds. . .";
		Sleep(3000);
		login(lname, lyo);
	}
	return 0;
}
