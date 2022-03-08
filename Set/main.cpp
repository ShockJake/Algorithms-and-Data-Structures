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
Set<T> &createSet(const char *type, int size, const char *args[]);

// Function to fill set with elements
template <class T>
void fillSet(Set<T> &set, int size, const char *args[]);

int main(int argc, char const *argv[])
{
    bool isOneSet = checkInput(argc, argv);

    if (isOneSet)
    {

        testOneSet(createSet(argv[1], argc, argv));
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
void fillSet(Set<T> &set, int size, const char *args[], std::string type)
{
    for (int i = 2; i < size; i++)
    {
        set.insert(args[i]);
    }
}

template <class T>
Set<T> &createSet(const char *type, int size, const char *args[])
{
    if (type == "string")
    {
        Set<std::string> newSet = new Set<std::string>(size);
        fillSet(newSet, size, args, type);
        return &newSet;
    }
    if (type == "integer")
    {
        Set<int> newSet = new Set<int>(size);
        fillSet(newSet, size, args, type);
        return &newSet;
    }
    if (type == "float")
    {
        Set<float> newSet = new Set<float>(size);
        fillSet(newSet, size, args, type);
        return &newSet;
    }
    if (type == "double")
    {
        Set<double> newSet = new Set<double>(size);
        fillSet(newSet, size, args, type);
        return &newSet;
    }
}

template <class T>
void testOneSet(Set<T> &set)
{
    set.toString();
}