/*
 * Dado un texto, imprimir el reverso
 * en el orden de palabras y las letras
 * de estas, pero a nivel de cada linea
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string currentLine;
  while (std::getline(std::cin, currentLine)) {
    // Insert the string into a stream
    std::stringstream ss(currentLine);
    std::string currentWord;
    // Check line word by word
    while (ss >> currentWord) {
      std::reverse(currentWord.begin(), currentWord.end());
      std::cout << currentWord << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
