#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account (const int accountNumber, const String name, const int &money) : balance(money)
{
    this->accountNumber = accountNumber;
    this->name = name;
}

bool Account::deposit(const int &money)
{
    if (money <= 0)
        throw LowerMoneyException(money);
    
    balance += money;
    
    return true;
}

bool Account::withdraw(const int &money)
{
    if (money <= 0)
        throw LowerMoneyException(money);
    if (money > balance)
        throw WithdrawException(balance);
    
    balance -= money;
    
    return true;
}

void Account::showAccountInfo() const
{
    cout << "계좌ID : " << accountNumber << endl;
    cout << "이  름 : " << name << endl;
    cout << "입금액 : " << balance << endl;
}

int Account::getAccountNumber() const
{
    return accountNumber;
}
