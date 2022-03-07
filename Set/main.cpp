#include <set.hpp>

// Function to check if there one or two sets in the input
bool checkInput(int lenght, const char *args[]);

// Function to perform tests for one set
template <class T>
void testOneSet(Set<T> &set);

// Function to perform tests for two sets
template <class T>
void testTwoSets(Set<T> &fistSet, Set<T> &secondSet);

// Function to create a set of given type
template <class T>
Set<T> &createSet(std::string type, int size, const char *args[]);

// Function to fill set with elements
template <class T>
// TODO: void fillSet(Set<T> &set, )

int main(int argc, char const *argv[])
{
    bool isOneSet = checkInput(argc, argv);

    if (isOneSet)
    {

        testOneSet();
    }

    return 0;
}

bool checkInput(int lenght, const char *args[])
{
    for (int i = 0; i < lenght; i++) // Walk through the arguments
    {
        if (args[i] == "|") // If there is a separator we can assume
        {                   // that there are two sets are given
            return false;
        }
    }
    return true;
}

template <class T>
Set<T> &createSet(std::string type, int size, const char *args[])
{
    if (type == "string")
    {
        Set<std::string> newSet = new Set<std::string>(size);
        
        return 
    }
    if (type == "integer")
    {
        return Set<int>(size);
    }
    if (type == "float")
    {
        return Set<float>(size);
    }
    if (type == "double")
    {
        return Set<double>(size);
    }
}