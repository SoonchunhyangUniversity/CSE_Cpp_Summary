#include <iostream>
#include <math.h>

using namespace std;

inline double calc_volume(double radius=1);

int main()
{
    double radius;

    cout << "반지름을 입력하시오 : ";
    cin >> radius;

    cout << "구의 부피는 " << calc_volume(radius) << endl;

    return 0;
}

double calc_volume(double radius)
{
    return (4.0 / 3.0 * 3.14 * pow(radius, 3));
}
