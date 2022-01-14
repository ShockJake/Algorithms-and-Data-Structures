#include "functions.hpp"
#include <fstream>

void chooseMode(int mode)
{
    if (mode == 1)
    {
        userMode();
    }
    else if (mode == 2)
    {
        presentationMode();
    }
    else if (mode == 3)
    {
        showInfo();
    }
    else
    {
        throw CommandNotFoundException();
    }
}

void startProgram()
{
    int operaion_int = 0;
    std::string operation_str;

    std::cout << std::string(40, '-') << "\n\n"
              << "\tPolynomial calculator\n\n"
              << std::string(40, '-') << "\n";
    while (true)
    {
        std::cout << "\nWhich mode do you want to enable?\n1) User mode\n2) Presentation mode\n3) Show information\n4) Exit\n\n";
        std::cin >> operation_str;
        try
        {
            operaion_int = atoi(operation_str.c_str());
            if (operaion_int == 4)
            {
                break;
            }
            else
            {
                chooseMode(operaion_int);
            }
        }
        catch (CommandNotFoundException &e)
        {
            std::cout << e.what() << "\n";
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }
}

Polynomial createPoly(int &size)
{
    double *input_args = new double[size];
    std::cout << "Write all arguments for each element of polynomial -\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin >> input_args[i];
    }
    return Polynomial(size, input_args);
}

void userMode()
{
    std::cout << std::string(40, '-') << "\n\n"
              << "\tUser mode...\n\n"
              << std::string(40, '-') << "\n";

    std::cout << "\nNow you need to create a polynomial:\n";
    int size_int;
    std::string size_str;
    while (true)
    {
        std::cout << "*** Write size of your first polynomial: ";
        std::cin >> size_str;
        try
        {
            if (check_number(size_str))
            {
                size_int = atoi(size_str.c_str());
                Polynomial new_poly = createPoly(size_int);
                std::cout << "Now you have such polynomial:\n";
                std::cout << new_poly.representation() << "\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << '\n';
        }
    }
}

void presentationMode()
{
    std::cout << std::string(40, '-') << "\n\n"
              << "\tPresentation mode...\n\n"
              << std::string(40, '-') << "\n";
}

void showInfo()
{
    std::cout << "\nInformation:\n";
    // TODO: ADD TEXT TO THE INFO.TXT !!!!
    std::fstream fs;
    try
    {
        fs.open("info.doc", std::ios::in);
        if (fs.is_open())
        {
            std::string line;
            while (!fs.eof())
            {
                std::getline(fs, line);
                std::cout << line << "\n";
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool check_number(std::string str)
{
    int n = 1;
    if (str[0] == '-')
    {
        n++;
        for (int i = 1; i < str.length(); i++)
        {
            if (isdigit(str[i]) == false)
            {
                n = n - 2;
            }
        }
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (isdigit(str[i]) == false)
            {
                n = n - 2;
            }
        }
    }
    if (n <= 0)
    {
        throw WrongInputException();
    }
    return true;
}