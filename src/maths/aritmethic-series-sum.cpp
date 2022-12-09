#include <array>
#include <iostream>

using std::cout, std::cin, std::cerr;
struct Term {
  float value;
  uint16_t n_of_term;
};

auto first_term(std::array<Term, 2> terms) {
  auto diff{0.f};
  if (terms[0].n_of_term < terms[1].n_of_term) {
    diff = (terms[1].value - terms[0].value) /
           (terms[1].n_of_term - terms[0].n_of_term);
  } else {
    diff = (terms[0].value - terms[1].value) /
           (terms[0].n_of_term - terms[1].n_of_term);
  }
  auto a = terms[1].value - ((terms[1].n_of_term - 1) * diff);
  return a;
}

template <uint8_t n_terms>
std::array<Term, n_terms> prompt_terms() {
  auto retval = std::array<Term, n_terms>{};
  for (auto &term : retval) {
    cout << "enter term in form (value, n): ";
    std::cin >> term.value >> term.n_of_term;
  }
  return retval;
}

int main() {
  cout << "what do you want to know\n"
          "1. a: first term\n"
          "2. Sn: summatory of n terms\n"
          "3. Tn: nth term\n"
          "4. d: difference\n";
  int option;
  cin >> option;
  switch (option) {
    case 1: {
      auto result = first_term(prompt_terms<2>());
      cout << "result is: " << result << '\n';
      break;
    }
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    default:
      cerr << "choose a valid option\n";
      return 1;
  }
}
