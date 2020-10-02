
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
    std::string output, input;

    std::cin >> output;
    std::cin >> input;

    if(input.at(0) == '0' && input.at(1) == 'x'){
      input = input.substr(2, input.size()-1);
      std::cout << "input: " << input << std::endl;
    } else if(input.at(0) == 'b') {
      std::cout << "binary input\n";
      input = input.substr(1, input.size()-1);
      std::cout << "input: " << input << std::endl;   
    }else {
      std::cout << "input: " << input << std::endl;
    }

    conv.decideOutput(input, output); 
    


    

    return 0;
}