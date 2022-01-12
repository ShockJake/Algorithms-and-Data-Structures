#include "functions.hpp"

int main()
{
    try
    {
        startProgram();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
