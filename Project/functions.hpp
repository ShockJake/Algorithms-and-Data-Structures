#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "polynomial.hpp"
#include <string>

void startProgram();
void presentationMode();
void chooseMode(int mode);
void userMode();
void showInfo();
class CommandNotFoundException : std::exception
{
public:
    const char *what() const throw()
    {
        return "No command with this number, try again...";
    }
};

#endif //FUNCTIONS_H