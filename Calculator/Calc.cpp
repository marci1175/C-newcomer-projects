#include <iostream>
#include <stdlib.h>
#include <Windows.h>
std::string dontes;
int dontes1;
int dontes2;
int answ;
bool resti = true;
std::string fasz;
void inv() {
    system("CLS");
    std::cout << "\nThis number is bigger than the 32bit integer, therefor i wont calculate that!\nExiting in 10 seconds\n";
    Sleep(10);
    resti = false;
}
int main()
{
    while(resti == true){
        std::cout << "Welcome to Marci's calculator\n1) +\n2) -\n3) :\n4) *\n";
        std::cin >> dontes;
        if (dontes > "4") {
            while (true) {
                std::cout << "I hope you die in your sleep\n";
            }


        }

        std::cout << "User's decision : \n" << dontes;
        std::cout << "\nEnter the first number!\n";
        std::cin >> dontes1;
        std::cout << "\nEnter the second number!\n";
        std::cin >> dontes2;


        if (dontes == "1") {
            if (2147483647 <= dontes1 + dontes2 or -2147483639 >= dontes1 + dontes2) {
                inv();
            }
            else
                answ = dontes1 + dontes2;
        }

        else if (dontes == "2") {
            if (2147483647 <= dontes1 - dontes2 or -2147483639 >= dontes1 - dontes2) {
                inv();
            }
            else
                answ = dontes1 - dontes2;
        }
        else if (dontes == "3") {
            if (2147483647 <= dontes1 / dontes2 or -2147483639 >= dontes1 / dontes2) {
                inv();
            }
            else
                answ = dontes1 / dontes2;
        }
        else if (dontes == "4") {
            if (2147483647 <= dontes1 * dontes2 or -2147483639 >= dontes1 * dontes2) {
                inv();
            }
            else
                answ = dontes1 * dontes2;
        }
        std::cout << "Answer : " << answ;

        std::string rest;

        std::cout << "\nWould you like to restart?(y/n)\n";
        std::cin >> rest;
        if (rest == "Y" or rest == "y") {
            system("CLS");
            continue;
        }
        else if (rest == "N" or rest == "n") {
            resti = false;
        }
        else
        std::cout << "\nYou have entered a wrong answer!\n\nrestarting in 3 seconds. . . .";
        Sleep(3);
        continue;
        
}
    std::cout << "FINISH";
}
