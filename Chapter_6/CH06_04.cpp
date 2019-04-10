#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SMS
{
    string sender;
    string recevier;
    string text;

public:
    SMS()
    {
        this->sender = "";
        this->recevier = "";
        this->text = "";
    }

    void setData(string sender, string recevier, string text)
    {
        this->sender = sender;
        this->recevier = recevier;
        this->text = text;
    }

    void print()
    {
        cout << "발신자 : " << this->getSender();
        cout << " 수신자 : " << this->getRecevier();
        cout << " 내용 : " << this->getText() << endl;
    }

    string getSender()
    {
        return this->sender;
    }

    string getRecevier()
    {
        return this->recevier;
    }

    string getText()
    {
        return this->text;
    }
};

int main()
{
    vector<SMS> vec;
    SMS arr[3];
    SMS temp;

    temp.setData("010-1234-5678", "010-1234-5679", "C++공부는 잘되가나요?");
    vec.push_back(temp);

    temp.setData("010-1234-5679", "010-1234-5678", "네 5장까지는 문제 없네요.");
    vec.push_back(temp);

    temp.setData("010-1234-5678", "010-1234-5679", "열심히 하세요.");
    vec.push_back(temp);

    cout << "Vector" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].print();
    }

    arr[0].setData("010-1234-5678", "010-1234-5679", "C++공부는 잘되가나요?");
    arr[1].setData("010-1234-5679", "010-1234-5678", "네 5장까지는 문제 없네요.");
    arr[2].setData("010-1234-5678", "010-1234-5679", "열심히 하세요.");

    cout << endl << "Array" << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(SMS); i++)
    {
        arr[i].print();
    }

    return 0;
}
