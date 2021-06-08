#include "Sales_item.h"
#include <iostream>

int main()
{
    Sales_item current; // hold the total value of current book
    // if input
    if (std::cin >> current)
    {
        Sales_item trans;
        while (std::cin >> trans)
        {
            if (current.isbn() == trans.isbn())
                current += trans;
            else
            {
                // print total of current book
                std::cout << current << std::endl;
                current = trans;
            }
        }
        std::cout << current << std::endl;
    }
    else
    {
        std::cerr << "there is no input!!" << std::endl;
        return -1;
    }
    return 0;
}
