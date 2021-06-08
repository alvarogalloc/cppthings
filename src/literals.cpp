#include <chrono>
#include <iostream>

using std::string;
using namespace std::chrono;

int main()
{
    milliseconds mil(3000);
    std::cout << mil.count() << std::endl;
    float example = 6e10f;
    float sec = example / 2e2f;
    unsigned long long hello = 42ULL;
    std::cout << 20 << std::endl;
    std::cout << 024 << std::endl;
    std::cout << 0x14 << std::endl;
    std::cout << example << std::endl;
    std::cout << sec << std::endl;
    // std::cin.ignore();
    return 0;
}
