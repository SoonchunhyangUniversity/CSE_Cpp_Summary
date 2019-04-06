#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    string str = "apple";
    string anagram = str;
    char temp;

    srand((unsigned int)time(0));

    int num_1 = rand() % str.length();
    int num_2 = rand() % str.length();

    while (num_1 == num_2)
    {
        num_2 = rand() % str.length();
    }

    temp = anagram[num_1];
    anagram[num_1] = anagram[num_2];
    anagram[num_2] = temp;

    while (true)
    {
        string input;

        cout << anagram << "은 어떤 단어가 스크램블된 것일까요? ";
        cin >> input;

        if (str.compare(input) == 0)
        {
            cout << "축하합니다." << endl;
            break;
        }
    }

    return 0;
}
