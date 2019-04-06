#include <iostream>

using namespace std;

class Complex
{
public:
    double r;
    double i;
    char oper;

    void print()
    {
        cout << r << " " << oper << " " << i << "i" << endl;
    }
};

int main()
{
    Complex complex1, complex2;

    complex1.r = 5;
    complex1.i = 3;
    complex1.oper = '+';

    complex2.r = 3;
    complex2.i = 4;
    complex2.oper = '-';

    complex1.print();
    complex2.print();

    return 0;
}
