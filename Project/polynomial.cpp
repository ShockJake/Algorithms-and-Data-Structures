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

string Polynomial::representation()
{
    if (is_zero())
    {
        throw EmptyPolynomialException();
    }
    string result = "";
    result += to_string(array[0]);
    for (int i = 1; i < size; i++)
    {
        if (array[i] == 0.0)
        {
            continue;
        }
        if (i < 2)
        {
            result += " + " + to_string(array[i]) + "x";
        }
        else
        {
            result += " + " + to_string(array[i]) + "x^" + to_string(i);
        }
    }
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
    if (this->array == nullptr)
    {
        this->array = right.array;
        this->size = right.size;
        return *this;
    }
    *this = this->operator+(right);
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &right)
{
    if (this->array == nullptr)
    {
        this->array = right.array;
        this->size = right.size;
        return *this;
    }
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
    delete[] result.array;
    result.array = new double[size];
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

    int new_size = this->size + other.size - 1;

    double *temp = result.array;
    result.array = new double[new_size];
    result.size = new_size;
    delete[] temp;

    for (int i = 0; i < new_size; i++)
    {
        result.array[i] = 0;
    }

    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < other.size; j++)
        {
            result.array[i + j] += this->array[i] * other.array[j];
        }
    }

    return result;
}

Polynomial Polynomial::pow(int n)
{
    if (n == 0)
    {
        double result[1] = {1.0};
        return Polynomial(1, result);
    }
    if (n == 1)
    {
        return *this;
    }
    return *this * pow(--n);
}

double pow(int n1, int n2)
{
    if (n2 == 0)
    {
        return 1;
    }
    else
    {
        return n1 * pow(n1, n2 - 1);
    }
}

Polynomial Polynomial::diff()
{
    if (size != 0)
    {
        array[0] += array[1];
        array[1] = 0;
        for (int i = 1; i < size - 1; i++)
        {
            array[i] = (i + 1) * array[i + 1];
            array[i + 1] = 0;
        }
        return Polynomial(size, array);
    }
    return Polynomial(size, array);
}

bool Polynomial::is_zero()
{
    return size == 0;
}

Polynomial Polynomial::integrate()
{
    if (!is_zero())
    {
        double *newArray = new double[size + 1];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        size++;
        for (int i = size; i > 0; i--)
        {
            array[i] = array[i - 1] / (i + 1);
            array[i - 1] = 0;
        }
        return Polynomial(size, array);
    }
    return Polynomial(size, array);
}

double Polynomial::eval_by_Horner(const double &x)
{
    double result = 0.0;
    for (int i = size - 1; i >= 0; i--)
    {
        result = array[i] + (x * result);
    }
    return result;
}

void Polynomial::negation()
{
    if (!is_zero())
    {
        for (int i = 0; i < size; i++)
        {
            array[i] *= -1;
        }
    }
}

int Polynomial::getSize()
{
    return size;
}

Polynomial Polynomial::combine(const Polynomial &_other)
{
    if ((!is_zero()) && _other.size != 0)
    {
        Polynomial result(0, (this->size - 1) * (_other.size - 1));
        for (int i = 0; i < this->size; i++)
        {
            result.array[i] = this->array[i];
        }
        Polynomial other;
        other = _other;
        Polynomial temp;
        for (int i = 1; i < this->size; i++)
        {
            // temp = other.pow(i);
            // for (int i = 0; i < ; i++)
            // {
            //     /* code */
            // }
            
        }

        return result;
    }
    return *this;
}