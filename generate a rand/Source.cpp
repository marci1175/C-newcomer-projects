#include <iostream>
#include <string>
#include <random>
int main() {
	std::vector <int> choices  { 1,2,3 };
	std::default_random_engine rng(std::random_device{}()); // Make the random number generator
	std::uniform_int_distribution<int> dist(1, 3); // Define the range of numbers you want to make
	int val = dist(rng); // Generate a number
	std::cout << val;
}
