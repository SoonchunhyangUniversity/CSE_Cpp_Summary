#include <iostream>

using namespace std;

int main()
{
    int hour, minute, second;

    cout << "시 : ";
    cin >> hour;

    cout << "분 : ";
    cin >> minute;

    cout << "초 : ";
    cin >> second;

    printf("전체 초 : %d\n", hour * 3600 + minute * 60 + second);

    return 0;
}
