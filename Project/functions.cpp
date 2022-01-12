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

void userMode()
{
    std::cout << std::string(40, '-') << "\n\n"
              << "\tUser mode...\n\n"
              << std::string(40, '-') << "\n";
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