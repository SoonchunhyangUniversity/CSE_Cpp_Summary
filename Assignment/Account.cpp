#include "Account.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [Account 클래스 생성자]
 * @param accountNumber [계좌번호]
 * @param name          [이름]
 * @param money         [입금액]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
Account::Account (const int accountNumber, const String name, const int &money) : balance(money)
{
    this->accountNumber = accountNumber;
    this->name = name;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [deposit 입금 함수]
 * @param  money [입금액]
 * @return       [입금 성공 여부]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
bool Account::deposit(const int &money)
{
    if (money <= 0)
        throw LowerMoneyException(money);
    
    balance += money;
    
    return true;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [withdraw 출금 함수]
 * @param  money [출금액]
 * @return       [출금 성공 여부]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
bool Account::withdraw(const int &money)
{
    if (money <= 0)
        throw LowerMoneyException(money);
    if (money > balance)
        throw WithdrawException(balance);
    
    balance -= money;
    
    return true;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [showAccountInfo 계좌 정보 출력 함수]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
void Account::showAccountInfo() const
{
    cout << "계좌ID : " << accountNumber << endl;
    cout << "이  름 : " << name << endl;
    cout << "입금액 : " << balance << endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [getAccountNumber 계좌번호 반환 함수]
 * @return [계좌번호]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
int Account::getAccountNumber() const
{
    return accountNumber;
}
