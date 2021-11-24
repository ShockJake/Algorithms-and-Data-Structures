#include "polynomial.hpp"
#include <string>
Polynomial::Polynomial()
{
    this->array = {};
    this->size = 0;
}

Polynomial::Polynomial(double arg, int number)
{
    this->size = number + 1;
    this->array = new double[number];
    for (int i = 0; i < number; i++)
    {
        array[i] = 0;
    }
    array[number - 1] = arg;
}

string Polynomial::toString()
{
    string result = "";
    for (int i = 0; i < size; i++)
    {
        result += to_string(array[i]);
        if (i != size - 1)
        {
            result += ", ";
        }
    }

    result = "{ " + result + " }";
    return result;
}

bool Polynomial::operator==(const Polynomial &other)
{
    if (this->size != other.size)
    {
        return false;
    }
    for (int i = 0; i < this->size; i++)
    {
        if (this->array[i] != other.array[i])
        {
            return false;
        }
    }
    return true;
}

bool Polynomial::operator!=(const Polynomial &other)
{
    return !(*this == other);
}

Polynomial Polynomial::operator+(const Polynomial &other)
{
    Polynomial newPoly;
    if (this->size >= other.size)
    {
        newPoly.array = new double[this->size];
        newPoly.size = this->size;
    }
    else
    {
        newPoly.array = new double[other.size];
        newPoly.size = other.size;
    }
    for (int i = 0; i < size; i++)
    {
        newPoly.array[i] = array[i];
    }
    for (int i = 0; i < other.size; i++)
    {
        newPoly.array[i] += other.array[i];
    }
    return newPoly;
}

Polynomial Polynomial::operator-(const Polynomial &other)
{
    Polynomial newPoly;
    if (this->size >= other.size)
    {
        newPoly.array = new double[this->size];
        newPoly.size = this->size;
    }
    else
    {
        newPoly.array = new double[other.size];
        newPoly.size = other.size;
    }
    for (int i = 0; i < newPoly.size; i++)
    {
        newPoly.array[i] = 0;
    }
    for (int i = 0; i < this->size; i++)
    {
        newPoly.array[i] = array[i];
    }
    for (int i = 0; i < other.size; i++)
    {
        newPoly.array[i] -= other.array[i];
    }
    return newPoly;
}

Polynomial Polynomial::operator=(const Polynomial &other)
{
    if (this == &other)
    {
        return *this;
    }
    this->size = other.size;
    this->array = other.array;

    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &right)
{
    *this = this->operator+(right);
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &right)
{
    *this = this->operator-(right);
    return *this;
}
