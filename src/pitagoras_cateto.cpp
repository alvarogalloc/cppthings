#include <cmath>
#include <cstdlib>
#include <iostream>

int main(int argc, const char **argv) {
  float arg1 = std::max(std::atof(argv[1]), std::atof(argv[2]));
  float arg2 = std::min(std::atof(argv[1]), std::atof(argv[2]));

  std::cout << std::sqrt(std::pow(arg1, 2) - std::pow(arg2, 2)) << std::endl;
  return 0;
}
