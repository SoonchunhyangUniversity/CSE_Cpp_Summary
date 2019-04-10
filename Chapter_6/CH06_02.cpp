#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b)
{
    return a < b;
}

int main()
{
    vector<string> vec;
    int num;
    string input;

    cout << "문자열의 개수 : ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "문자열을 입력하세요 : ";
        cin >> input;

        vec.push_back(input);
    }

    sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    return 0;
}
