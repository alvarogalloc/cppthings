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

using fmt::print, std::ofstream, std::array, std::string_view;

struct person {
  std::string_view name;
  int age{};
};

template <int quantity>
array<person, quantity> generate_persons()  {
  array<person, quantity> retval;
  person persons[100];
  array<string_view, 6> names = {"Alvaro", "Fer",    "Miguel",
                                           "Majo",   "Sandra", "Regina"};
  int index = 0;
  // init array
  for (size_t i = 0; i < 100; i++) {
    auto &[name, age] = persons[i];
    age = i;
    name = names.at(index);
    if (index == 5)
      index = 0;
    else
      index++;
  }
  return retval;
}

int main() {
  try {
    auto persons = generate_persons<100>();
    auto [data, in, out] = zpp::bits::data_in_out();
    out(persons).or_throw();

    // write to file
    ofstream file{"/tmp/serialized.data", std::ios::binary | std::ios::out};
    file.write((char *)data.data(), data.size());
    file.close();

  } catch (const std::exception &e) {
    print("{}", e.what());
    exit(1);
  }
  return 0;
}
