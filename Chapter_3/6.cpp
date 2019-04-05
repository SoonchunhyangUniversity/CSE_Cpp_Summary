#include <iostream>
#include <string>

using namespace std;

void delete_bracket(string str);

int main()
{
    string str;

    while (true)
    {
        cout << "전화번호를 입력하시오 : ";
        cin >> str;

        if (str.compare("quit") == 0)
        {
            break;
        }

        delete_bracket(str);

    }

    return 0;
}

void delete_bracket(string str)
{
    for (auto& c: str)
    {
        if (c == '(' || c == ')')
        {
            continue;
        }

        else
        {
            cout << c;
        }
    }

    cout << endl;
}
