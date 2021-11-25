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
    this->array = new double[number + 1];
    for (int i = 0; i < number + 1; i++)
    {
        array[i] = 0;
    }
    array[number] = arg;
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

    if (other.size == 0)
    {
        newPoly.array = this->array;
        newPoly.size = this->size;
        return newPoly;
    }

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

    if (other.size == 0)
    {
        double *temp = newPoly.array;
        newPoly.array = this->array;
        delete[] temp;
        newPoly.size = this->size;
        return newPoly;
    }

    if (this->size >= other.size)
    {
        double *temp = newPoly.array;
        newPoly.array = new double[this->size];
        delete[] temp;
        newPoly.size = this->size;
    }
    else
    {
        double *temp = newPoly.array;
        newPoly.array = new double[other.size];
        delete[] temp;
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

Polynomial Polynomial::operator*(const int &number)
{
    Polynomial result;
    if (this->size == 0)
    {
        return result;
    }
    if (this->size == 1)
    {
        double *temp = result.array;
        result.array = this->array;
        result.size = this->size;
        delete[] temp;
        result.array[0] *= number;
        return result;
    }

    for (int i = 0; i < this->size; i++)
    {
        result.array[i] = this->array[i] * number;
    }
    return result;
}

Polynomial Polynomial::operator*(const Polynomial &other)
{
    Polynomial result;
    if (this->size == 0 || other.size == 0)
    {
        return result;
    }
    if (this->size == 1 && other.size == 1)
    {
        double *temp = result.array;
        result.array = this->array;
        result.size = this->size;
        delete[] temp;
        result.array[0] *= other.array[0];
        return result;
    }
    double *temp = result.array;
    result.array = new double[(this->size - 1) + (other.size - 1) + 2];
    result.size = this->size - 1 + other.size - 1 + 1;
    delete[] temp;

    result.array[0] = this->array[0];
    result.array[0] *= other.array[0];

    for (int i = 1; i < result.size; i++)
    {
        result.array[i] = 0.0;
    }
    for (int i = 1; i < this->size; i++)
    {
        for (int j = 0; j < other.size; j++)
        {
            result.array[i + j] += this->array[i] * other.array[j];
        }
    }
    return result;
}
