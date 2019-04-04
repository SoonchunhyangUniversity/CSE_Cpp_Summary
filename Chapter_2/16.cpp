#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int money = 50;
    int bets = 0, win = 0;

    cout << "초기 금액 $" << money << endl;
    cout << "목표 금액 $250" << endl;

    srand((unsigned int)time(0));

    while (true)
    {
        bets++;

        if ((double)rand() / RAND_MAX < 0.5)
        {
            money++;
            win++;
        }

        else
        {
            money--;
        }

        if (money >= 250)
        {
            break;
        }
    }

    cout << "이긴 확률 = " << (double)win / bets * 100 << endl;

    return 0;
}
