#include <algorithm>
#include <array>
#include <iostream>

int main() {
  std::array<int, 10> my_array;
  my_array.fill(100);
  for (auto i : my_array) std::cout << i;
  std::cout << "\n";
  return 0;
}
