#include <iostream>
#include <ctime>

using namespace std;

int flip();

int main()
{
    int front = 0;
    int back = 0;

    srand((unsigned int)time(0));

    for (int i = 0; i < 100; i++)
    {
        if (flip() == 1)
        {
            front++;
        }

        else
        {
            back++;
        }
    }

    cout << "앞면 : " << front << "번" << endl;
    cout << "뒷면 : " << back<< "번" << endl;
    cout << "앞면 확률 : " << front << "% 뒷면 확률 : " << back << "%" << endl;

    return 0;
}

int flip()
{
    return rand() % 2;
}
