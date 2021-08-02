// C++ program to find out execution time of
// of functions
#include <chrono>
#include <iostream>
namespace std_time = std::chrono;

void benchmark() {
  unsigned long long init = 0;
  for (size_t i = 1; i < 10000; i++) {
    for (size_t j = 1; i < 100000000; i++) init += i - j;
  }
}

// For demonstration purpose, we will fill up
// a vector with random integers and then sort
// them using sort function. We fill record
// and print the time required by sort function
int main() {
  // Get starting timepoint
  auto start = std_time::high_resolution_clock::now();

  // Call benchmark
  benchmark();
  // Get ending timepoint
  auto stop = std_time::high_resolution_clock::now();

  // Get duration. Substart timepoints to
  // get durarion. To cast it to proper unit
  // use duration cast method
  auto duration = std_time::duration_cast<std_time::milliseconds>(stop - start);

  std::cout << "Time taken by function: " << duration.count() << " milliseconds"
            << std::endl;

  return 0;
}
