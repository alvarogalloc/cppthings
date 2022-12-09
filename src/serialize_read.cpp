#include <fstream>
#include <iostream>
#include "./Serializable.h"

int main() {
  auto file = std::ifstream("parents.bin", std::ios::binary);
  Parent p;
  file.read(reinterpret_cast<char*>(&p), sizeof(p));
  p.print();
  Parent p2;
  file.read(reinterpret_cast<char*>(&p2), sizeof(Parent));
  p2.print();

  return 0;
}
