#include <array>
#include <fstream>
#include <iostream>

#include "./Serializable.h"

int main() {
  Parent p;
  p.name = "Alvaro Gallo";
  p.age = 32;
  p.job = "Programmer";
  p.height = 1.78;
  p.weight = 80.0;
  Parent p2;
  p2.name = "Maria Glez";
  p2.age = 31;
  p2.job = "Programmer";
  p2.height = 1.60;
  p2.weight = 60.0;

  constexpr auto universities = std::array<std::string_view, 5>{
      "MIT", "Harvard", "Yale", "Princeton", "Columbia"};
  constexpr auto weights = std::array<float, 5>{40.0, 28.0, 23.1, 50.0, 42.0};
  constexpr auto heights = std::array<float, 5>{1.8, 1.75, 1.68, 1.72, 1.67};
  auto ofs = std::ofstream("parents.bin", std::ios::binary);
  for (size_t i = 0; i < 5; i++) {
    Child c;
    c.name = "John the " + std::to_string(i);
    c.age = 0b11010101 & 0b10101010;
    c.height = heights[i];
    c.weight = weights[i];
    c.school = universities[i];
    p.children[i] = c;
    p2.children[i] = c;
  }
  ofs.write(reinterpret_cast<char*>(&p), sizeof(p));
  ofs.write(reinterpret_cast<char*>(&p2), sizeof(p2));
  ofs.close();
  p.print();
  p2.print();
  return 0;
}
