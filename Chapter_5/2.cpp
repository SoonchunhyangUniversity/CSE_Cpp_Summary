#include <iostream>
#include <string>

using namespace std;

class Airplane
{
    string name;
    int capacity;
    int speed;

public:
    Airplane()
    {

    };

    Airplane(string name, int capacity, int speed)
    {
        this->name = name;
        this->capacity = capacity;
        this->speed = speed;
    }

    void setData(string name, int capacity, int speed)
    {
        this->name = name;
        this->capacity = capacity;
        this->speed = speed;
    }

    void print() const
    {
        cout << "비행기 이름 : " << this->getName() << endl;
        cout << "비행기 용량 : " << this->getCapacity() << endl;
        cout << "비행기 속도 : " << this->getSpeed() << " Km/h" << endl;
    }

    string getName()
    {
        return this->name;
    }

    int getCapacity()
    {
        return this->capacity;
    }

    int getSpeed()
    {
        return this->speed;
    }
};

int main()
{
    Airplane airplane_1;
    Airplane airplane_2("에어버스 350", 400, 1000);

    airplane_1.setData("보잉747", 900, 300);

    cout << "비행기 #1" << endl;
    airplane_1.print();

    cout << endl;

    cout << "비행기 #2" << endl;
    airplane_2.print();

    return 0;
}
