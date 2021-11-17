#include "linkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList<string> list;
    list.push_front("geg");
    list.push_back("ter");
    list.push_back("geg");
    cout << list.toString() << endl;
    list.removeDuplicates();
    cout << list.toString() << endl;


    return 0;
}
