#include "polynomial.hpp"

int main()
{
    double arr1[3] = {1.0, 2.0, 3.0};
    double arr2[4] = {2.0, 3.0, 4.0, 5.0};
    Polynomial p1(3, arr1);
    Polynomial p2(4, arr2);

    Polynomial p3;

    p3 = p1 - p2;
    p3 = p1.pow(3);
    cout << p3.toString() << endl;
    p3.diff();
    cout << p3.toString() << endl;
    cout << p3.representation() << endl;
    return 0;
}