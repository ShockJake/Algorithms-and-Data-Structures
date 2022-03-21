#include "hashSet.hpp"
#include "limits.h"
#include <fstream>

void testSet(int argc, char const *argv[])
{
    HashSet<int> arr(INT8_MAX);
    
    ifstream in;
    int data;
    in.open(argv[2]);
    in >> data;
    arr.insert(data);

    while(!in.eof())
    {
        in >> data;
        arr.insert(data);
    }

    if(arr.contains(1000010))
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }
    
    std::cout << "Union\n";
    std::cout << arr.printUnion(arr) << "\n";
    std::cout << "Intersection\n";
    std::cout << arr.printIntersection(arr) << "\n";
    std::cout << "Difference\n";
    std::cout << arr.printDifference(arr) << "\n";
}

int main(int argc, char const *argv[])
{
    HashSet<int> intArr1(INT8_MAX);
    HashSet<int> intArr2(INT8_MAX);

    HashSet<std::string> strArr1(10);
    HashSet<std::string> strArr2(10);

    bool isTwoSets = false;
    int separationPoint = 0;

    for (int i = 0; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "|")
        {
            isTwoSets = true;
            separationPoint = i;
        }
    }

    if (argc < 2)
    {
        std::cout << "To small amount of arguments...\n";
        exit(1);
    }

    std::string file_name = argv[2];
    if (file_name == "test_set.txt")
    {
        testSet(argc, argv);
        exit(0);
    }

    std::string type = argv[1];
    if (type == "integer")
    {
        if (!isTwoSets)
        {
            for (int i = 2; i < argc; i++)
            {
                intArr1.insert(atoi(argv[i]));
            }

            std::cout << intArr1.toString() << '\n';
        }
        else
        {
            for (int i = 2; i < separationPoint; i++)
            {
                intArr1.insert(atoi(argv[i]));
            }
            for (int i = separationPoint + 1; i < argc; i++)
            {
                intArr2.insert(atoi(argv[i]));
            }

            std::cout << "Difference = " << intArr1.printDifference(intArr2) << "\n";
            std::cout << "Intersection = " << intArr1.printIntersection(intArr2) << "\n";
            std::cout << "Union = " << intArr1.printUnion(intArr2) << "\n";

            intArr1.popAll(intArr2);

            std::cout << "PopAll = " << intArr1.toString() << "\n";
        }
    }

    else if (type == "string")
    {
        if (!isTwoSets)
        {
            for (int i = 2; i < argc; i++)
            {
                strArr1.insert(argv[i]);
            }

            std::cout << strArr1.toString() << '\n';
        }
        else
        {
            for (int i = 2; i < separationPoint; i++)
            {
                strArr1.insert(argv[i]);
            }
            for (int i = separationPoint + 1; i < argc; i++)
            {
                strArr2.insert(argv[i]);
            }

            std::cout << "Difference = " << strArr1.printDifference(strArr2) << "\n";
            std::cout << "Intersection = " << strArr1.printIntersection(strArr2) << "\n";
            std::cout << "Union = " << strArr1.printUnion(strArr2) << "\n";

            strArr1.popAll(strArr2);

            std::cout << "PopAll = " << strArr1.toString() << "\n";
        }
    }

    return 0;
}
