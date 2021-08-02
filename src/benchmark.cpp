#include <chrono>
#include <functional>
#include <iostream>

auto now() { return std::chrono::high_resolution_clock::now(); }

// Return the microseconds that took to call a function
int benchmark(std::function<void(std::string, uint16_t)> function) {
  const auto start = now();
  function("hola", 100);
  return std::chrono::duration_cast<std::chrono::microseconds>(now() - start)
      .count();
}

void cout_n_times(std::string text, uint16_t times) {
  for (size_t i = 0; i < times; i++) {
    std::cout << text << "\r";
  }
}

int main() {
  const int duration = benchmark(cout_n_times);
  std::cout << "Time taken by function was: " << duration << " microseconds\n";
  return 0;
}
