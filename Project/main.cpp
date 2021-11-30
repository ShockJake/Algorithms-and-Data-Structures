#include "polynomial.hpp"

int main()
{
try
{
    double arr1[3] = {1, 1, 1};
    double arr2[3] = {0, 1, 1};
    Polynomial p1(3, arr1);
    Polynomial p2(3, arr2);
    Polynomial p3;
    p3 = p1.combine(p2);
    cout << p3.representation() << endl;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
    
    return 0;
}