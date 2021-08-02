#include <chrono>
#include <iostream>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// For benchmarking
auto get_curr_time() { return std::chrono::high_resolution_clock::now(); }

int linear_search(int arr[100], int n) {
  for (int i = 0; i < 100; i++)
    if (n == arr[i]) return i;
  return -1;
}

int binary_search(int arr[100], int n) {
  int min = 0, max = 100 - 1;
  while (min <= max) {
    int guess = min + (max - min) / 2;
    if (arr[guess] == n)
      // if correct
      return guess;
    else if (arr[guess] < n)
      // if guess < n
      min = guess + 1;
    else
      // if guess < n
      max = guess - 1;
  }
  // If error
  return -1;
}

int main() {
  int primes[100] = {
      2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,
      53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
      127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
      199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
      283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
      383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
      467, 479, 487, 491, 499, 503, 509, 521, 523, 541};
  int secret_number;
  int index_of_secret_number;
  std::cin >> secret_number;

  // Linear Search
  std::cout << RED << "-- Linear Search --\n" << RESET;
  auto now = get_curr_time();
  index_of_secret_number = linear_search(primes, secret_number);
  // Get microseconds passed
  auto delayed = std::chrono::duration_cast<std::chrono::nanoseconds>(
                     get_curr_time() - now)
                     .count();
  if (index_of_secret_number == -1)
    std::cout << secret_number << " not found in array\n";
  else
    std::cout << secret_number << " found at index: " << index_of_secret_number
              << '\n';

  std::cout << "Time delayed by linear search: " << RED << delayed
            << " nanoseconds" << RESET << '\n';

  // Separation
  std::cout << "\n\n\n";

  // Binary Search
  std::cout << GREEN << "-- Binary Search --\n" << RESET;
  now = get_curr_time();
  index_of_secret_number = binary_search(primes, secret_number);
  // Get microseconds passed
  delayed = std::chrono::duration_cast<std::chrono::nanoseconds>(
                get_curr_time() - now)
                .count();
  if (index_of_secret_number == -1)
    std::cout << secret_number << " not found in array\n";
  else
    std::cout << secret_number << " found at index: " << index_of_secret_number
              << '\n';

  std::cout << "Time delayed by linear search: " << GREEN << delayed
            << " nanoseconds" << RESET << '\n';
  return 0;
}
