#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP
#include <iostream>

using namespace std;

const int MAX_SIZE = 12;

class Polynomial
{
private:
    double *array;
    int size;

public:
    Polynomial();
    Polynomial(int size, double arr[] = {}) : size(size), array(arr){};
    Polynomial(double arg, int number);
    ~Polynomial(){};

    Polynomial operator+(const Polynomial &other);
    Polynomial operator-(const Polynomial &other);
    Polynomial operator*(const Polynomial &other);
    Polynomial operator*(const int& number);
    Polynomial operator=(const Polynomial &other);
    Polynomial &operator+=(const Polynomial &right);
    Polynomial &operator-=(const Polynomial &right);
    bool operator==(const Polynomial &other);
    bool operator!=(const Polynomial &other);

    Polynomial pow(int n);
    Polynomial diff();
    Polynomial integrate();
    Polynomial combine();

    void negation();
    bool is_zero();
    double eval(Polynomial &other);

    string toString();
    string representation();

    class EmptyPolynomialException : public exception
    {
        const char *what() const throw()
        {
            return "The polynomial equals 0";
        }
    };
};

#endif // POLYNOMIAL_HPP