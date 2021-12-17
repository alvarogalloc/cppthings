#include <iostream>
#include <vector>

int main() {
  std::vector<int> registers;
  int input_line = 0, previous = 0, current = 0, count = 0;
  while (std::cin >> input_line) {
    registers.push_back(input_line);
  }
  for (int i = 0; i < registers.size(); i++) {
    previous = registers[i - 1];
    current = registers[i];
    if (previous < current) {
      count++;
    }
  }
  std::cout << count << std::endl;
  return 0;
}
