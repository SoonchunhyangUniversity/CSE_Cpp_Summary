#include <iostream>
#include <string>

using namespace std;

class Computer
{
    string name;
    int RAM;
    double cpu_speed;

public:
    void setComputer(string name, int RAM, double cpu_speed)
    {
        this->name = name;
        this->RAM = RAM;
        this->cpu_speed = cpu_speed;
    }

    void print()
    {
        cout << "이름 : " << this->name << endl;
        cout << "RAM : " << this->RAM << endl;
        cout << "CPU 속도 : " << this->cpu_speed << endl;
    }
};

int main()
{
    Computer com;

    com.setComputer("오피스컴퓨터", 8, 4.2);

    com.print();

    return 0;
}
