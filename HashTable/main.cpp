#include "hashTable.hpp"

int main(int argc, char const *argv[])
{
    HashTable<int> myTable(5);
    try
    {
        std::cout << "\t--- HashTable test ---\n";
        myTable.insert(1);
        myTable.insert(7);
        myTable.insert(3);
        myTable.insert(4);
        myTable.insert(17);
        myTable.printHashTable();
        std::cout << "contains(3) - " << myTable.contains(3) << '\n';
        myTable.remove(3);
        std::cout << "removed 3\n";
        std::cout << "contains(3) - " << myTable.contains(3) << '\n';
        myTable.printHashTable();
        myTable.remove(17);
        std::cout << "removed 17\n";
        myTable.printHashTable();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}
