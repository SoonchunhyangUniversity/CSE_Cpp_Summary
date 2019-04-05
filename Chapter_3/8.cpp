#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int count[10] = { 0 };
    int max = 0;
    int idx = -1;

    srand((unsigned int)time(0));

    for (int i = 0; i < 100; i++)
    {
        count[rand() % 10]++;
    }

    for (int i = 0; i < sizeof(count) / sizeof(int); i++)
    {
        if (max < count[i])
        {
            max = count[i];
            idx = i + 1;
        }
    }

    cout << "가장 많이 생성된 수 : " << idx << endl;

    return 0;
}
