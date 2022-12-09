import <array>;
import <cctype>;
import <sstream>;
import <algorithm>;
import <random>;
import <fstream>;
import <cstdlib>;
import <string_view>;
#include "fmt/core.h"
#include "zpp_bits.h"

using fmt::print, std::ifstream;

struct person {
  std::string_view name;
  int age{};
};

void print(const person &p) {
  print("{} {}", p.age, p.name);
}

int main() {
  try {
    ifstream file{"/tmp/serialized.data", std::ios::binary | std::ios::in};
    person persons[100];
    auto [data, in, out] = zpp::bits::data_in_out();
    file.read(reinterpret_cast<char*>(&persons[0]), sizeof(person));
    print(persons[0]);
  } catch (const std::exception& e) {
    print("{}", e.what());
  }

  return 0;
}
