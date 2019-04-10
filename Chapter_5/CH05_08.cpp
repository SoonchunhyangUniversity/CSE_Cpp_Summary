#include <iostream>
#include <string>

using namespace std;

class Date
{
    int year;
    int month;
    int day;

public:
    Date()
    {

    }

    Date(int y, int m, int d)
    {
        this->year = y;
        this->month = m;
        this->day = d;
    }

    bool isLeapYear(int y)
    {
        if ((y % 4 == 0
                && y % 100 != 0)
                    || y % 400 == 0)
        {
            return true;
        }

        return false;
    }

    void print() const
    {
        printf("%4d.%02d.%02d\n",
                    this->year, this->month, this->day);
    }

    int getYear()
    {
        return this->year;
    }

    Date nextMonth()
    {
        this->month += 1;

        if (this->month > 12)
        {
            this->month -= 12;
            this->year += 1;
        }

        Date next(this->year, this->month, this->day);

        return next;
    }
};

int main()
{
    Date curr(2017, 9, 1);
    curr.print();

    Date next = curr.nextMonth();
    next.print();

    Date leap(2020, 12, 1);

    if (leap.isLeapYear(leap.getYear()))
    {
        cout << "2020년은 윤년입니다." << endl;
    }

    leap.print();
    leap.nextMonth();
    leap.print();

    return 0;
}
