#include <iostream>
#include <string>

using namespace std;

class SMS
{
    string sender;
    string recevier;
    string text;
    int num;

public:
    void setData(string sender, string recevier, string text, int num)
    {
        this->sender = sender;
        this->recevier = recevier;
        this->text = text;
        this->num = num;
    }

    void print() const
    {
        cout << "문자메시지 " << "#" << this->getNum() << endl;
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

    int getNum()
    {
        return this->num;
    }
};

int main()
{
    SMS sms_1;
    SMS sms_2;
    int num = 1;

    sms_1.setData("010-1234-5678",
                  "010-1234-5679",
                  "C++공부는 잘 되어가나요?",
                  num++
                  );

    sms_2.setData("010-1234-5679",
                  "010-1234-5678",
                  "네 5장까지는 문제없네요.",
                  num++);

    sms_1.print();
    cout << endl;
    sms_2.print();

    return 0;
}
