#pragma once
#include <vector>
#include <iostream>
void printVector(std::vector<double> vec);
std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros);
