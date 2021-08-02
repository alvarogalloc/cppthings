#include <fstream>
#include <algorithm>
#include <iostream>

using std::ios;

int main(int argc, char **argv) {
  if (argc != 2) return 1;
  std::fstream file;
  file.open("text.txt", ios::in | ios::out | ios::app);
  /* file.open("text.txt"); */
  int linecount = std::count(std::istreambuf_iterator<char>(file),
          std::istreambuf_iterator<char>(), '\n');

  // Write
  /* if (std::string(argv[1]) != "list") file << argv[1] << "\n"; */

  // Reset position to beginning
  file.seekg(ios::beg);

  // Read
  std::string buffer;
  while (file) {
    std::getline(file, buffer);
    std::cout << buffer << '\n';
  }
  std::cout << "Number of lines: " << linecount << '\n';
  file.close();
  return 0;
}
