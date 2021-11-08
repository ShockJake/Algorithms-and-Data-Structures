#include <iostream>
#include "arrayList.h"

using namespace std;

int main()
{
    cout << "-Initialization-" << endl;
    ArrayList<int> arr(10);
    cout << arr.toString() << endl;

    cout << "-Push Back-" << endl;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(2);
    cout << arr.toString() << endl;

    cout << "-Insert-" << endl;
    arr.insert(2, 15);
    cout << arr.toString() << endl;

    cout << "-Remove-" << endl;
    arr.remove(2);
    cout << arr.toString() << endl;

    cout << "-Remove duplicates-" << endl;
    arr.removeDuplicates();
    cout << arr.toString() << endl;

    cout << "-Get Length-" << endl;
    cout << arr.getLength() << endl;

    cout << "-Locate- (7)" << endl;
    cout << arr.locate(7) << endl;

    cout << "-Push Front-" << endl;
    arr.push_front(10);
    arr.push_front(5);
    cout << arr.toString() << endl;

    cout << "-Reverse-" << endl;
    arr.revesre();
    cout << arr.toString() << endl;


    return 0;
}