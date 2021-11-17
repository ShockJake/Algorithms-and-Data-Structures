#include "linkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList<int> list;
    try
    {
        list.push_front(1);
        list.push_back(2);
        list.push_back(3);
        cout << list.toString() << endl;

        list.push_back(4);
        list.push_back(4);
        cout << list.toString() << endl;
        list.removeSecondElements();
        cout << list.toString() << endl;
        list.removeSecondElements();
        cout << list.toString() << endl;
    
    }
    catch(const std::exception e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}
