#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    void setTime(const int h, const int m, const int s)
    {
        this->hour = h;
        this->minute = m;
        this->second = s;

        if (this->second >= 60)
        {
            this->minute += 1;
            this->second -= 60;
        }

        if (this->minute >= 60)
        {
            this->hour += 1;
            this->minute -= 60;
        }

        if (this->hour >= 24)
        {
            this->hour %= 24;
        }
    }

    void print() const
    {
        printf("%02d:%02d:%02d\n",
                this->hour, this->minute, this->second);
    }
};

int main()
{
    Time time;

    time.setTime(7, 10, 20);
    time.print();

    return 0;
}
