#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
    string number;
    int balance;

public:
    void init(string number, int balance)
    {
        this->number = number;
        this->balance = balance;

        cout << "현재 잔액 : " << this->balance << endl;
    }

    void deposit(int amount)
    {
        this->balance += amount;

        cout << "after deposit(" << amount << ")"
            << "현재 잔액 : " << this->balance << endl;;
    }

    void withdraw(int amount)
    {
        if (this->balance > amount)
        {
            cout << "after withdraw(" << amount << ") ";

            this->balance -= amount;

            cout << "현재 잔액 : " << this->balance << endl;
        }

        else
        {
            cout << "현재 잔액이 모자릅니다." << endl;
        }
    }
};

int main()
{
    BankAccount bankaccount;

    bankaccount.init("111-222-3333", 1000000);
    bankaccount.deposit(1000000);
    bankaccount.withdraw(1000000);

    return 0;
}
