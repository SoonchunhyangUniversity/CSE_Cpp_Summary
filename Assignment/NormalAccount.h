#ifndef NormalAccount_h
#define NormalAccount_h
#include "BankingCommonDecl.h"
#include "Account.h"

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
    NormalAccount(const int accountNumber,
                  const String name,
                  int money,
                  int rate) : Account(accountNumber, name, money), rate(rate)
    {
        
    }
    
    ~NormalAccount()
    {
        
    }
    
    bool deposit(const int &money)
    {
        if (!Account::deposit(money))
            return false;
        
        if (!Account::deposit((int) (money * (rate / 100.0f))))
            return false;
        
        return true;
    }
    
    void showAccountInfo() const
    {
        cout << "[보통 예금계좌]" << endl;
        Account::showAccountInfo();
        cout << "이자율 : " << rate << endl;
    }
};

#endif
