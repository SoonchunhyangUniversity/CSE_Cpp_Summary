#ifndef BankingCommonDecl_h
#define BankingCommonDecl_h

#include <iostream>
#include <cstring>

using namespace std;

class BankingException
{
    int data;
    
public:
    virtual void showExceptionLog() const = 0;
};


class WithdrawException : public BankingException
{
    int data;
    
public:
    WithdrawException(int data) : data(data)
    {
        
    }
    
    virtual void showExceptionLog(void) const
    {
        cout << "예금된 금액보다 적은 금액을 출금하세요." << endl;
        cout << "현재 잔액 : " << data << endl;
    }
};


class LowerMoneyException : public BankingException
{
    int data;
    
public:
    LowerMoneyException(int data) : data(data)
    {
        
    }
    
    virtual void showExceptionLog(void) const
    {
        cout << data << "원을 요청하셨습니다." << endl;
        cout << "0원보다 큰 금액을 입력해주세요." << endl;
    }
};

#endif