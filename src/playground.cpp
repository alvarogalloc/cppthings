#include <algorithm>
#include <cctype>
#include <iostream>

std::string reverseString(std::string &str) {
  std::string reversed;
  for (int n = str.length() - 1; n >= 0; n--) {
    reversed.push_back(str[n]);
  }
  return reversed;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // TODO: fixme.
  std::string s, r;
  int n_of_coincidences = 0;
  std::cin >> s;
  r = reverseString(s);
  for (int i = 0; i < s.length(); i++) {
    if (std::tolower(s[i]) == std::tolower(r[i])) n_of_coincidences++;
  }
  std::cout << n_of_coincidences;
  return 0;
}
