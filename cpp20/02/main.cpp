import MyList;

int main()
{
    List list(0);
    /* list = new gallo::List(0); */
    for (int i = 1; i <= 10; i++)
        list.append(i);
    list.printList();
    list.reverse();
    list.printList();
    return 0;
}
