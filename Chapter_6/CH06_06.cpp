#include <iostream>
#include <string>
#define LEN 3

using namespace std;

class Contact
{
private:
    string name;
    string tel;

public:
    void setData(string name, string tel)
    {
        this->name = name;
        this->tel = tel;
    }

    string getTel()
    {
        return this->tel;
    }

    string getName()
    {
        return this->name;
    }
};

int main()
{
    Contact *arr = (Contact *)malloc(sizeof(Contact) * LEN);
    string name, tel;

    for (int i = 0; i < LEN; i++)
    {
        cout << "이름을 입력하시오 : ";
        cin >> name;

        cout << "전화번호를 입력하시오 : ";
        cin >> tel;

        arr[i].setData(name, tel);
    }

    cout << "탐색하고 싶은 이름을 입력하시오 : ";
    cin >> name;

    for (int i = 0; i < LEN; i++)
    {
        if ((arr[i].getName()).compare(name) == 0)
        {
            cout << "전화번호 : " << arr[i].getTel() << endl;
        }
    }

    return 0;
}
