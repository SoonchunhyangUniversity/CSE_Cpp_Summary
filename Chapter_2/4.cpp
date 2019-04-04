#include <iostream>
#include <string>

using namespace std;

bool is_digit(string str)
{
    return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}

int main()
{
    string input;

    for (int i = 0; i < 5; i++)
    {
        cout << "정수를 입력하세요 : ";
        getline(cin, input);

        if (is_digit(input))
        {
            cout << input + "을 입력하셨군요! 컴퓨터 승" << endl;
        }

        else
        {
            cout << "인내심이 강합니다. 사용자 승" << endl;
        }
    }

    return 0;
}
