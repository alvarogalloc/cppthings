#include <iostream>

inline void hello(const std::string &name) { std::cout << name << "\n"; }

int main(int argc, const char **argv) {
  std::string alvaro = "Alvaro";
  hello(alvaro);
  return 0;
}
