#include <fmt/core.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <string>
#include <string_view>

auto now() { return std::chrono::high_resolution_clock::now(); }

// Return the microseconds that took to call a function
int benchmark(std::function<void(std::string, uint16_t)> function) {
  const auto start = now();
  function("hola", 1000);
  return std::chrono::duration_cast<std::chrono::microseconds>(now() - start)
      .count();
}

void cout_test(const std::string &text, uint16_t times) {
  for (size_t i = 0; i < times; i++) {
    std::cout << text;
  }
  std::cout << '\n';
}

void fmt_test(const std::string &text, uint16_t times) {
  for (size_t i = 0; i < times; i++) {
    fmt::print("hola");
  }
  fmt::print("\n");
}

void printf_test(const std::string &text, uint16_t times) {
  for (size_t i = 0; i < times; i++) {
    std::printf("hola");
  }
  std::printf("\n");
}

int main() {
  const int cout_duration = benchmark(cout_test);
  const int printf_duration = benchmark(printf_test);
  const int fmt_duration = benchmark(fmt_test);
  std::cout << "Time taken by cout was: " << cout_duration << " microseconds\n";
  std::cout << "Time taken by printf was: " << printf_duration
            << " microseconds\n";
  std::cout << "Time taken by fmt::print was: " << fmt_duration
            << " microseconds\n";
  return 0;
}
