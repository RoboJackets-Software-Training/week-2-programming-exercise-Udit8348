#include "convolution.h"

void printVector(std::vector<double> vec){
    std::cout << "{";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << (i != (vec.size()-1) ? ", " : "");
    }
    std::cout << "}" << std::endl;
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
    printVector(y);

    return y;
  
    // =========== END ===========
}
