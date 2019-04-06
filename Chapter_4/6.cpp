#include <iostream>
#include <string>

using namespace std;

class Employee
{
    string name;
    int age;
    int salary;

public:
    void setData(string name, int age, int salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    void print()
    {
        cout << this->name << endl;
        cout << this->age << endl;
        cout << this->salary << endl;
    }
};

int main()
{
    Employee emp;

    emp.setData("김철수", 38, 2000000);

    cout << "Employee1" << endl;
    emp.print();

    return 0;
}
