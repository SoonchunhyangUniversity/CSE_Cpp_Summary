#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    string *arr;
    string temp;

    cout << "얼마나 많은 이름을 입력하시겠습니다? ";
    cin >> num;

    arr = new string[num];

    for (int i = 0; i < num; i++)
    {
        cout << "이름 입력 # " << i + 1 << ": ";
        cin >> temp;

        arr[i] = temp;
    }

    cout << endl << "다음은 이름 목록입니다." << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "이름 # " << i + 1 << ": " << arr[i] << endl;
    }

    return 0;
}
