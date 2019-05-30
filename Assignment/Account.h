#ifndef Account_h
#define Account_h
#include "String.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 계좌 정보 클래스
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Member Variables
 * accountNumber : 계좌번호
 * name : 이름
 * balance : 예금액
 * phoneNumber : 전화번호 (요구사항에 있지만 예제에 없어서 제거)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Member Method
 * Account(accountNumber, name, &money) : 생성자
 * deposit(&money) : 입금
 * withdraw(&money) : 출금
 * showAccountInfo() : 계좌정보출력
 * getAccountNumber() : 계좌번호반환
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
class Account
{
    int accountNumber;
    String name;
    int balance;
    
public:
    Account (const int accountNumber, const String name, const int &money);
    virtual bool deposit(const int &money);
    bool withdraw(const int &money);
    virtual void showAccountInfo() const;
    int getAccountNumber() const;
};

#endif
