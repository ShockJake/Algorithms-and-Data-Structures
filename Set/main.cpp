#include "hashSet.hpp"

int main(int argc, char const *argv[])
{
    
    HashSet<int> intww(5);

    intww.insert(1);
    intww.insert(2);
    intww.insert(3);

    intww.printHashTable();


    return 0;
}
