
#include "NumberConverter.h"

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {

    NumberConverter conv;

    // Example 1 binary -> decimal test cases
    std::string binary1 = "1";          // 1
    std::string binary2 = "01101";      // 13
    std::string binary3 = "1101010101"; // 853
    // Example 2 hex -> decimal test cases
    std::string hex1 = "1";             // 1
    std::string hex2 = "D";             // 13

    std::cout << conv.binaryToNumber(conv.buildPlaceVector(binary1)) << std::endl;
    std::cout << conv.binaryToNumber(conv.buildPlaceVector(binary2)) << std::endl;
    std::cout << conv.binaryToNumber(conv.buildPlaceVector(binary3)) << std::endl;

    std::cout << conv.hexToNumber(conv.buildPlaceVector("78BD")) << std::endl;
    std::cout << "finished" << std::endl;

    return 0;
}