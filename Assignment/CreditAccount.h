#ifndef CreditAccount_h
#define CreditAccount_h
#include "NormalAccount.h"
#include "String.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 신용 계좌 정보 클래스 (NormalAccount class 상속)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Member Variables
 * specRate : 등급 이자율
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Member Method
 * CreditAccount(accountNumber, name, &money, rate, specRate) : 생성자
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
class CreditAccount : public NormalAccount
{
    int specRate;
    
public:
    enum { A = 1, B, C };
    // Ato1, Bto2, Cto3
    
    CreditAccount(const int accountNumber,
                  const String name,
                  int money,
                  int rate,
                  int specRate): NormalAccount(accountNumber, name, money, rate)
    {
        switch (specRate) {
            case A:
                this->specRate = 7;
                break;
                
            case B:
                this->specRate = 4;
                break;
                
            case C:
                this->specRate = 2;
                break;
                
            default:
                this->specRate = 0;
                break;
        }
    }
    
    ~CreditAccount()
    {
        
    }
    
    bool deposit(const int &money)
    {
        if (!NormalAccount::deposit(money))
            return false;
        if (!Account::deposit((int)(money * (specRate / 100.0f))))
            return false;
        
        return true;
    }
    
    void showAccountInfo() const
    {
        cout << "[신용 예금계좌]" << endl;
        NormalAccount::showAccountInfo();
        char grade = specRate == 7 ? 'A' : specRate == 4 ? 'B' : 'C';
        cout << "등  급 : " << grade << endl;
    }
};

#endif
