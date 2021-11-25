#include "polynomial.hpp"

int main()
{
    double arr1[3] = {1.0, 2.0, 3.0};
    double arr2[4] = {2.0, 3.0, 4.0, 5.0};
    Polynomial p1(3, arr1);
    Polynomial p2(4, arr2);

    Polynomial p3;
    p3 = p2 * p1;
    cout << p3.toString() << endl;

    return 0;
}