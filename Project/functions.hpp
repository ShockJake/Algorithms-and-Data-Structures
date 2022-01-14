#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "polynomial.hpp"
#include <string>

void startProgram();

// Mode that shows what you can do with polynomials without user input.
void presentationMode();

// Mode that shows what you can do with polynomials with user input.
void userMode();

// Function to choose mode (presentation or user). 
void chooseMode(int mode);

// Function to show information about use of program.
void showInfo();

// Checks if given string is a number.
bool check_number(std::string str);

// Function to create polynomial.
Polynomial createPoly(int &size);
class CommandNotFoundException : std::exception
{
public:
    const char *what() const throw()
    {
        return "No command with this number, try again...";
    }
};

class WrongInputException : std::exception
{
public:
    const char *what() const throw()
    {
        return "Wrong input, try again...";
    }
};

#endif //FUNCTIONS_H