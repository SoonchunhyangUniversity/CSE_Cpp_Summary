#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int counter[256] = { 0 };

    cout << "문자열을 입력하세요 : ";
    getline(cin, str);

    for (auto& c: str)
    {
        counter[c]++;
    }

    for (int i = 0; i < sizeof(counter) / sizeof(int); i++)
    {
        cout << (char)i << " : " << counter[i] << endl;
    }

    return 0;
}
