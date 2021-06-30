/*
 * Gallo's cuadratic Formula
 * Solver
 * This program takes 3 args
 * (a - b - c) and returns the result
 */

#include <cmath>
#include <cstdlib>
#include <iostream>

int main(int argc, const char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: cuadratica <a> <b> <c>\n";
        return -1;
    }

    int a = std::atoi(argv[1]), b = std::atoi(argv[2]), c = std::atoi(argv[3]);
    std::string ecuation = std::to_string(a) + "x^2";
    ecuation += (b < 0) ? (std::to_string(b) + "x") : ("+" + std::to_string(b) + "x");
    ecuation += (c < 0) ? (std::to_string(c)) : ("+" + std::to_string(c));
    ecuation += "=0";
    std::cout << "Ecuation ->  " << ecuation << "\n";
    if (b < 0)
        b = abs(b);

    if (c < 0)
    {
        c = abs(c);
        ecuation = "x = -(" + std::to_string(b) + ")" + "±sqrt(" + std::to_string(b) + "^2+4*" + std::to_string(a) +
                   "*" + std::to_string(std::abs(c)) + ")/2*" + std::to_string(a);
    }
    else
    {
        ecuation = "x = -(" + std::to_string(b) + ")" + "±sqrt(" + std::to_string(b) + "^2-4*" + std::to_string(a) +
                   "*" + std::to_string(std::abs(c)) + ")/2*" + std::to_string(a);
    }
    std::cout << "despeje ->  " << ecuation << "\n";
    ecuation = "x = ";
    if (b < 0)
    {
        b = abs(b);
        ecuation += b;
    }
    else
        ecuation += b;
    /* float result =  */
    ecuation += std::to_string(b) + "±sqrt(" + std::to_string((const int)pow(b, 2)) + "+" + std::to_string(4 * a * c) +
                ")/" + std::to_string(2 * a);
    std::cout << "despeje 2" << ecuation << "\n";
    ecuation =
        std::to_string(b) + "¬±sqrt(" + std::to_string((const int)pow(b, 2) + 4 * a * c) + ")/" + std::to_string(2 * a);

    std::cout << "Resultado->  " << ecuation << "\n";

    return 0;
}
