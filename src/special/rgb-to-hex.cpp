/*
 * By: alvaro gallo
 *
 * inputs 3 numbers separated by spaces,
 * copies to clipboard a string of the 6 hex digits
 * conversion.
 */

#include <iostream>

#include "../../clip/clip.h"

std::string rgb_to_hex(int r, int g, int b) {
  std::string hex = "#";
  std::string hex_digits = "0123456789ABCDEF";
  hex += hex_digits[r / 16];
  hex += hex_digits[r % 16];
  hex += hex_digits[g / 16];
  hex += hex_digits[g % 16];
  hex += hex_digits[b / 16];
  hex += hex_digits[b % 16];
  return hex;
}

int main(int argc, char** argv) {
  if (argc < 4) return 1;

  int r = std::atoi(argv[1]), g = std::atoi(argv[2]), b = std::atoi(argv[3]);
  if (!clip::set_text(rgb_to_hex(r, g, b)))
    std::cerr << "Error copying to clipboard" << std::endl;
  else
    std::cout << "Copied to clipboard: " << rgb_to_hex(r, g, b) << std::endl;
  return 0;
}
