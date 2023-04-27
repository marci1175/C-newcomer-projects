#include <iostream>
#include <string>
#include <vector>
int main() {
	int szam;
	std::string text;
	std::vector <std::string> lines;
	std::cout << "Enter a number!" << std::endl;
	std::cin >> szam;
	std::cout << "Enter text" << std::endl;
	std::getline(std::cin >> std::ws, text);
	lines.push_back(text);

	//int conv into string
	std::string sSzam = std::to_string(szam);
	lines.push_back(sSzam);
	//print out result
	for (const auto& line : lines) {
		std::cout << line;
	}
}