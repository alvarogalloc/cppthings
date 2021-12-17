/*
 * Dado un string, determinar cuantas
 * veces se puede formar una palabra
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::string s;
  std::cin >> s;
  std::string keyword = "miguel";
  std::vector<int> keyword_values_count{0, 0, 0, 0, 0, 0};
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < keyword.length(); j++) {
      if (s[i] == keyword[j]) {
        keyword_values_count[j]++;
      }
    }
  }

  std::cout << *std::min_element(keyword_values_count.begin(),
                                 keyword_values_count.end())
            << std::endl;
  return 0;
}
