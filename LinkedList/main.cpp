#include "linkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList<int> list;
    list.push_front(1);
    list.push_back(2);
    list.push_back(3);
    cout << list.toString() << endl;
    //list.removeDuplicates();
    cout << list.toString() << endl;

    for (int i = 0; i < list.getLength(); i++)
    {
        cout << list[i] << endl;
    }
    
    return 0;
}
