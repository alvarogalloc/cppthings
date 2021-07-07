import MyList;
import <iostream>;
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main()
{
    List list(0);
    /* list = new gallo::List(0); */
    for (int i = 1; i <= 10; i++)
        list.append(i);
    list.printList();
    std::cout << GREEN << "Printing reversed list\n" << RESET;
    list.reverse();
    list.printList();
    return 0;
}
