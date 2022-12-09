#include <iostream>

#include "Sales_item.h"

int main() {
  /*
  // create an instance of Sales_item
  Sales_item item;
  // Read item's ISBN, copies sold, and price/book
  std::cin >> item;
  // write the item data plus the average price of the book
  std::cout << item << std::endl;*/

  /*
  // sum to Sales_item objects
  Sales_item book1, book2;
  // Read data for the two objects
  std::cin >> book1 >> book2;
  // print the sum of both items
  // if the isbn's are the same
  if (book1.isbn() == book2.isbn())
    std::cout << book1 + book2 << std::endl;
  else
    // error because isbn's are different
    std::cerr << "isbn's are different" << std::endl;*/

  // program that reads several transactions of a same ISBN

  Sales_item total;
  // get input to know if there is data to process
  if (std::cin >> total) {
    Sales_item currTrans;
    // until read all transactions
    while (std::cin >> currTrans) {
      if (total.isbn() == currTrans.isbn()) {
        total += currTrans;
      } else {
        std::cout << total << std::endl;
        total = currTrans;
      }
    }
    std::cout << total << std::endl;
  } else {
    std::cerr << "no data??" << std::endl;
    return -1;
  }
  return 0;
}
