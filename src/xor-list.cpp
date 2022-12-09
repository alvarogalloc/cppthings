#include <string_view>

#include "./XorList.h"

int main() {
  auto list = XorList<std::string_view>("hello");
  for (std::size_t i = 0; i < 200; i++) {
    list.add("item: " + std::to_string(i));
  }
  list.print();
  // list.reverse();
  // list.print();
  std::cout << "List size: " << list.size() << '\n';
  std::cout << "List at 0,1,2: " << list.at(0) << list.at(1) << list.at(2)<< '\n';
}
