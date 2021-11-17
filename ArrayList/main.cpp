#include <iostream>
#include "arrayList.h"
using namespace std;

int main()
{
    cout << "Array List test:" << endl;

    cout << "\n---Initialization--- " << endl;
    ArrayList<int> arr1;
    cout << "|Array List 1| " << arr1.toString() << " - empty array list of integer elements." << endl;
    ArrayList<double> arr2(10);
    cout << "|Array List 2| " << arr2.toString() << " - array list of double elements with reserved length of 10." << endl;

    cout << "\n---isEmpty()---" << endl;
    cout << "|Array List 1| " << arr1.isEmpty() << endl;
    cout << "|Array List 2| " << arr2.isEmpty() << endl;

    cout << "\n---push_front() ---" << endl;
    arr1.push_front(10);
    arr1.push_front(14);
    arr1.push_front(18);
    arr2.push_front(4.2);
    arr2.push_front(3.45);
    arr2.push_front(0.15);
    cout << "|Array List 2| " << arr1.toString() << endl;
    cout << "|Array List 1| " << arr2.toString() << endl;
    cout << "pushed some elements to the front." << endl;

    cout << "\n---push_back()---" << endl;
    arr1.push_back(3);
    arr1.push_back(4);
    arr1.push_back(53);
    arr2.push_back(3.8);
    arr2.push_back(1.2);
    arr2.push_back(8.37);
    cout << "|Array List 1| " << arr1.toString() << endl;
    cout << "|Array List 2| " << arr2.toString() << endl;
    cout << "pushed some elements to the back." << endl;

    cout << "\n---pop_front()---" << endl;
    arr1.pop_front();
    arr2.pop_front();
    cout << "|Array List 1| " << arr1.toString() << endl;
    cout << "|Array List 2| " << arr2.toString() << endl;
    cout << "popped one element from the front." << endl;
    
    cout << "\n---pop_back()---" << endl;
    arr1.pop_back();
    arr2.pop_back();
    cout << "|Array List 1| " << arr1.toString() << endl;
    cout << "|Array List 2| " << arr2.toString() << endl;
    cout << "popped one element from the back." << endl;

    cout << "\n---insert()---" << endl;
    arr1.insert(2, 23);
    arr2.insert(3, 9.5);
    cout << "|Array List 1|" << arr1.toString() << " inserted 23 to the third position." << endl;
    cout << "|Array List 2|" << arr2.toString() << " inserted 9.5 to the fourth position." << endl;

    cout << "\n---locate()---" << endl;
    cout << "|Array List 1| " << arr1.locate(23) + 1 << endl;
    cout << "|Array List 2| " << arr2.locate(9.5) + 1 << endl;
    cout << "located elements that was inserted before." << endl;
    
    cout << "\n---retrive()---" << endl;
    cout << "|Array List 1| " << arr1.retrieve(1) << endl;
    cout << "|Array List 2| " << arr2.retrieve(1) << endl;
    cout << "retrived elements from the second position." << endl;

    cout << "\n---remove()---" << endl;
    arr1.remove(1);
    arr2.remove(1);
    cout << "|Array List 1| " << arr1.toString() << endl;
    cout << "|Array List 2| " << arr2.toString() << endl;
    cout << "removed elements that was located before." << endl;

    arr1.insert(3, 3);
    arr1.insert(1, 3);
    arr2.insert(3, 3.3);
    arr2.insert(1, 3.3);

    cout << "\n---makeUnique---" << endl;
    cout << "|Array List 1| " << arr1.toString() << endl; 
    arr1.makeUnique();
    cout << "|Array List 1| " << arr1.toString() << " after removing repeating elements without first of them." << endl;
    cout << "|Array List 2| " << arr2.toString() << endl;
    arr2.makeUnique();
    cout << "|Array List 2| " << arr2.toString() << " after removing repeating elements without first of them." << endl;

    arr1.insert(3, 3);
    arr1.insert(1, 3);
    arr2.insert(3, 3.3);
    arr2.insert(1, 3.3);

    cout << "\n---removeDuplicates()---" << endl;
    cout << "|Array List 1| " << arr1.toString() << endl; 
    arr1.removeDuplicates();
    cout << "|Array List 1| " << arr1.toString() << " after removing repeating elements." << endl;
    cout << "|Array List 2| " << arr2.toString() << endl;
    arr2.removeDuplicates();
    cout << "|Array List 2| " << arr2.toString() << " after removing repeating elements." << endl;

    cout << "\n---reverse()---" << endl;
    cout << "|Array List 1| " << arr1.toString() << " before reverse" << endl;
    arr1.revesre();
    cout << "|Array List 1| " << arr1.toString() << " after reverse" << endl;
    cout << "|Array List 2| " << arr2.toString() << " before reverse" << endl;
    arr2.revesre();
    cout << "|Array List 2| " << arr2.toString() << " after reverse" << endl;

    
    return 0;
}
