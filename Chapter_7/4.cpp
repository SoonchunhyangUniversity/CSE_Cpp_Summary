#include <iostream>
#include <string>

using namespace std;

class Time
{
public:
    int hour;
    int min;
    int sec;

    Time()
    {

    }

    Time(int hour, int min, int sec)
    {
        this->hour = hour;
        this->min = min;
        this->sec = sec;
    }

    void print()
    {
        printf("Time 객체 : %2d:%2d:%2d",
                    this->hour, this->min, this->sec);
    }
};

bool isEqual(Time& t1, Time& t2)
{
    if (t1.hour == t2.hour
            && t1.min == t2.min
                && t1.sec == t2.sec)
    {
        return true;
    }

    return false;
}

bool isEqual(Time *pt1, Time *pt2)
{
    if (pt1->hour == pt2->hour
            && pt1->min == pt2->min
                && pt1->sec == pt2->sec)
    {
        return true;
    }

    return false;
}

int main()
{
    Time time_1(12, 11, 33);
    Time time_2(12, 11, 33);
    Time time_3(11, 11, 11);

    if (isEqual(time_1, time_2))
    {
        cout << "시간이 일치합니다." << endl;
    }

    else
    {
        cout << "시간이 일치하지 않습니다." << endl;
    }

    if (isEqual(&time_1, &time_3))
    {
        cout << "시간이 일치합니다." << endl;
    }

    else
    {
        cout << "시간이 일치하지 않습니다." << endl;
    }

    return 0;
}
