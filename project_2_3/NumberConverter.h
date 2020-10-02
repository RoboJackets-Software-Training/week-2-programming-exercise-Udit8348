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

	void outputFromHex(std::string input, std::string outputType);

	void outputFromDecimal(int input, std::string outputType);

	// Conversion Methods
	int binaryToDecimal(std::vector<int> places);

	int hexToDecimal(std::vector<int> places);

	std::string decimalToHex(int input);

};