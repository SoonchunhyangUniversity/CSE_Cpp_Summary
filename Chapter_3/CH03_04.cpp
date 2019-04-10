#include <iostream>

using namespace std;

void prime(int num);

int main()
{
    prime(100);

    return 0;
}

void prime(int num)
{
    for (int i = 2; i <= num; i++)
    {
        bool check = true;

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                check = false;
                break;
            }
        }

        if (check)
            cout << i << " ";
    }
}
