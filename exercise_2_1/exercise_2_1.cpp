#include <vector>
#include <iostream>

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

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {
    std::vector<double> y;
    int buf = (w.size()-1)/2;

    // 2D loop to convolude vector x
    for (int i = 0; i < x.size(); i++) {
        double sum = 0;
        for (int j = 0; j < w.size(); j++) {
        // standard handling
        if(i - buf + j >= 0 && i - buf + j < x.size()) {
            sum += x[i - buf + j] * w[j];
        } 
        // underflow handling
        else if (!pack_with_zeros && i - buf + j < 0) {
            sum += x[0] * w[j];
        }
        // overflow handling
        else if (!pack_with_zeros && i - buf + j >= x.size()) {
            sum += x[x.size() -1] * w[j];
        }
        }
        // store in output vector
        y.push_back(sum);
    }

    // Print output vector
    std::cout << "{";
    for (int i = 0; i < y.size(); i++) {
        std::cout << y[i] << (i != (y.size()-1) ? ", " : "");
    }
    std::cout << "}" << std::endl;

    return y;
  
    // =========== END ===========
}

int main() {
    // get info from textfiles
    std::vector<double> x;
    std::vector<double> w;
    std::vector<double> y;
    bool pack_with_zeros = true;

    std::string s;
    std::cin >> s;
    if(s == "false") {
      pack_with_zeros = false;
    }
    std::cin >> s;
    x = readInVector(s);
    std::cin >> s;
    w = readInVector(s);

    // method call
    applyConvolution(x, w, pack_with_zeros);
    applyConvolution(x, w, false);

}

