#include "linkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList<int> list;
    list.push_front(1);
    list.push_back(2);
    cout << list.toString() << endl;
    return 0;
}
