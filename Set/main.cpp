#include "hashSet.hpp"

int main(int argc, char const *argv[])
{
    
    HashSet<int> arr1(5);
    HashSet<int> arr2(5);
    HashSet<int> arr3(5);
    HashSet<int> arr4(5);

    arr1.insert(1);
    arr1.insert(2);
    arr1.insert(3);
    arr1.insert(4);
    arr1.insert(5);

    arr2.insert(2);
    arr2.insert(3);
    arr2.insert(4);
    arr2.insert(5);
    arr2.insert(6);

    std::cout << "\n";

    std::cout << arr1.printIntersection(arr2) << "\n";


    return 0;
}
