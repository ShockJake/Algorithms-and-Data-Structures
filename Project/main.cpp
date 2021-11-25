#include "polynomial.hpp"

int main()
{
    double arr1[3] = {1.0, 2.0, 3.0};
    Polynomial p(3, arr1);
    double arr2[4] = {1.2, 2.3, 3.4, 4.5};
    Polynomial p2(4, arr2);
    cout << p.toString() << endl;
    cout << p2.toString() << endl;;
    Polynomial p3;
    p3 = p + p2;
    cout << p3.toString() << endl;
    p3 += p;
    cout << p3.toString() << endl;
    Polynomial p4(0, 6);
    cout << p4.toString() << endl;
    return 0;
}