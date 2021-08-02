#include <cmath>
#include <cstdlib>
#include <iostream>

int main(int argc, const char **argv) {
  float arg1 = std::atof(argv[1]);
  float arg2 = std::atof(argv[2]);
  std::cout << std::sqrt(std::pow(arg2, 2) + std::pow(arg2, 2)) << std::endl;
  return 0;
}
