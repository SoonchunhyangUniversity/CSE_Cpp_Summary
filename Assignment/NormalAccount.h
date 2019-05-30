#ifndef NormalAccount_h
#define NormalAccount_h
#include "Account.h"
#include "String.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 보통 계좌 정보 클래스 (Account class 상속)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Member Variables
 * rate : 이자율
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Member Method
 * NormalAccount(accountNumber, name, &money, rate) : 생성자
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
class NormalAccount : public Account
{
    int rate;
    
public:
    // 클래스 생성자
    NormalAccount(const int accountNumber,
                  const String name,
                  int money,
                  int rate) : Account(accountNumber, name, money), rate(rate)
    {
        
    }
    
    // 클래스 소멸자
    ~NormalAccount()
    {
        
    }
    
    // 입금 함수
    bool deposit(const int &money)
    {
        // 입금이 실패한 경우
        if (!Account::deposit(money))
            return false;
        
        // 이율 적용이 실패한 경우
        if (!Account::deposit((int) (money * (rate / 100.0f))))
            return false;
        
        return true; // 입금 성공
    }
    
    // 계좌 정보 출력 함수
    void showAccountInfo() const
    {
        cout << "[보통 예금계좌]" << endl;
        Account::showAccountInfo();
        cout << "이자율 : " << rate << endl;
    }
};

#endif
