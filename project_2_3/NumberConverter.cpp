#include "NumberConverter.h"

/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return
 */
int NumberConverter::hexCharToNumber(char input) {
  // this means it is [A,B,C,D,E,F]
  if(input > 57) {
    return input - (65 - 10);
  } else {
    // this is a digit in ascii
    return input - 48;
  }
}

/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return
 */
char NumberConverter::numberToHexChar(int input) {
  if(input < 10) {
    // it is a digit
    return input + 48;
  } else {
    return (input - 10) + 65;
  }
}

std::vector<int> NumberConverter::buildPlaceVector(std::string raw) {
	std::vector<int> output;
	for (int i = 0; i < raw.length(); i++) {
		output.push_back(hexCharToNumber(raw.at(i)));
	}	
	return output;
}

int NumberConverter::binaryToNumber(std::vector<int> places) {
  int sum = 0;
  
  // need to reverse the vector for the correct place values
  std::reverse(places.begin(), places.end());

  for (int i = 0; i < places.size(); i++) {
    sum += places[i] * std::pow(2, i);
  }
	return sum;
}

int NumberConverter::hexToNumber(std::vector<int> places){
	int sum = 0;
  
  // need to reverse the vector for the correct place values
  std::reverse(places.begin(), places.end());

  for (int i = 0; i < places.size(); i++) {
    sum += places[i] * std::pow(16, i);
  }
  return sum;
}
