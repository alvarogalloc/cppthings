/*
 * Program that recieves an input of books (isbn, number of transactions, unitary price)
 * And prints how many times does every isbn had
 */

#include "Sales_item.h"
#include <iostream>

int main()
{
    int cnt = 1;
    Sales_item total;
    if (std::cin >> total)
    {
        Sales_item current;
        while (std::cin >> current)
        {
            if (total.isbn() == current.isbn())
                ++cnt;
            else
            {
                std::cout << total.isbn() << " had " << cnt << " transactions" << std::endl;
                total = current;
                cnt = 1;
            }
        }
        std::cout << total.isbn() << " had " << cnt << " transactions" << std::endl;
    }
    else
    {
        std::cerr << "Theres no input!!" << std::endl;
        return -1;
    }
}
