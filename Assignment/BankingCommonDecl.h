#ifndef BankingCommonDecl_h
#define BankingCommonDecl_h

#include <iostream>
#include <cstring>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [BankingException 클래스]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Member Variables
 * data : 금액
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * showExceptionLog : 예외 출력 가상함수
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
class BankingException
{
    int data;
    
public:
    virtual void showExceptionLog() const = 0;
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [WithdrawException 출금 예외 클래스]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * BankingException 상속
 * @param data [금액]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 부모 클래스의 가상함수 구현
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
class WithdrawException : public BankingException
{
    int data;
    
public:
    WithdrawException(int data) : data(data)
    {
        
    }
    
    virtual void showExceptionLog() const
    {
        cout << "예금된 금액보다 적은 금액을 출금하세요." << endl;
        cout << "현재 잔액 : " << data << endl;
    }
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [LowerMoneyException 잔액 부족 예외 클래스]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * BankingException 상속
 * @param data [금액]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 부모 클래스의 가상함수 구현
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
class LowerMoneyException : public BankingException
{
    int data;
    
public:
    LowerMoneyException(int data) : data(data)
    {
        
    }
    
    virtual void showExceptionLog() const
    {
        cout << data << "원을 요청하셨습니다." << endl;
        cout << "0원보다 큰 금액을 입력해주세요." << endl;
    }
};

#endif
