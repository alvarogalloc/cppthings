// #ifdef __cpp_modules
import std;
import MyList;
// #else
// #include <iostream>
//
// #endif

constexpr auto GREEN = "\033[32m";
constexpr auto RESET = "\033[0m";

int main() {
  List list(0);
  /* list = new gallo::List(0); */
  for (int i = 1; i <= 10; i++) list.append(i);
  list.printList();
  std::cout << GREEN << "Printing reversed list\n" << RESET;
  list.reverse();
  list.printList();
  return 0;
}
