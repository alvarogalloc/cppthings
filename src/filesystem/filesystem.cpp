#include <fstream>
#include <iostream>
#include <initializer_list>

using std::ios;

int main(int argc, const char **argv)
{
    /* std::ifstream file; */
    std::fstream file;
    file.open("text.txt", ios::in | ios::app);

    /* // Write */
    /* file << "Funciono!!"; */

    // Reset position to beginning
    file.seekg(ios::beg);

    // Read
    std::string buffer;
    while (file)
    {
        std::getline(file, buffer);
        std::cout << buffer << '\n';
    }
    file.close();
    return 0;
}
