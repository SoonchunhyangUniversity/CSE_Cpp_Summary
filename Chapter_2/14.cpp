#include <iostream>

using namespace std;

int main()
{
    char oper;
    int num1, num2;

    cout << "연산의 종류 : ";
    cin >> oper;

    cout << "숫자를 입력하시오 : ";
    cin >> num1 >> num2;

    cout << "계산의 결과 : ";

    switch (oper) {
        case '+':
            cout << num1 + num2;
            break;

        case '-':
            cout << num1 - num2;
            break;

        case '*':
            cout << num1 * num2;
            break;

        case '/':
            if (num2 != 0)
            {
                cout << num1 / num2;
            }

            else
            {
                cout << "몫은 0이 될 수 없습니다.";
            }

            break;

        default:
            cout << "잘못된 연산자입니다.";
            break;
    }

    cout << endl;

    return 0;
}
