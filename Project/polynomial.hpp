#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP
#include <iostream>

const int MAX_SIZE = 9;

class Polynomial
{
private:
    double *array;
    int size;
    bool blocked = false;
public:
    Polynomial(); //+
    Polynomial(int size, double arr[] = {}) : size(size), array(arr){}; //+
    Polynomial(double arg, int number); //+
    ~Polynomial(){};

    Polynomial operator+(const Polynomial &other);   //+
    Polynomial operator-(const Polynomial &other);   //+
    Polynomial operator*(const Polynomial &other);   //+
    Polynomial operator*(const int &number);         //+
    Polynomial operator=(const Polynomial &other);   //+
    Polynomial &operator+=(const Polynomial &right); //+
    Polynomial &operator-=(const Polynomial &right); //+
    bool operator==(const Polynomial &other);        //+
    bool operator!=(const Polynomial &other);        //+

    Polynomial pow(int n);                       //+
    Polynomial diff();                           //+
    Polynomial integrate();                      //+
    Polynomial combine(const Polynomial &other); //+

    int getSize();
    void negation();                        //+
    bool is_zero();                         //+
    double eval_by_Horner(const double &x); //+

    std::string toString();       //+
    std::string representation(); //+

    class EmptyPolynomialException : public std::exception
    {
        const char *what() const throw()
        {
            return "The polynomial equals 0";
        }
    };

    class FullPolynomialException : public std::exception
    {
        const char *what() const throw()
        {
            return "The polynomial is to big";
        }
    };
};

#endif // POLYNOMIAL_HPP