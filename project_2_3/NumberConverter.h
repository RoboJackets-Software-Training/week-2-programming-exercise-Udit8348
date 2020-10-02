#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

class NumberConverter {
	public:
	// Constructor not provided. Relying on default constructor

	// Helper Methods
	int hexCharToNumber(char input);

	char numberToHexChar(int input);

	std::vector<int> buildPlaceVector(std::string raw);

	// Conversion Methods
	int binaryToNumber(std::vector<int> places);

	int hexToNumber(std::vector<int> places);

};