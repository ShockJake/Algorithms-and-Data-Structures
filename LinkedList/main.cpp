#include "linkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList<int> list;

    list.push_back(1);
    list.push_back(4);
    list.push_back(7);
    list.push_back(2);
    list.push_back(4);

    list.push_back(2);
    cout << list.toString() << endl;
    list.removeDuplicates();
    cout << list.toString() << endl;

    return 0;
}
