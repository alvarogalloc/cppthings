#include <iostream>
#include <vector>
#include <stdio.h>

int main()
{
    bool b = 250;
    std::cout << "boolean" << b << std::endl;
    int i = b;
    std::cout << "integer: " << i << std::endl;
    i = 3.14;
    double pi = i;
    std::cout << "double: " << pi << std::endl;
    unsigned char c = -1;
    std::cout << "unsigned char: " << c << std::endl;
    signed char c2 = (1 == 1) ? 't' : 'p';
    std::cout << "signed char: " << c2 << std::endl;

    std::cin.ignore();

    return 0;
}
