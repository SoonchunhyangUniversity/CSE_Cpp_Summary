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
    
    // 클래스 생성자
    CreditAccount(const int accountNumber,
                  const String name,
                  int money,
                  int rate,
                  int specRate): NormalAccount(accountNumber, name, money, rate)
    {
        switch (specRate) 
        {
            // 1 : A (7%의 신용 이자율)
            case A:
                this->specRate = 7;
                break;
                
            // 2 : B (4%의 신용 이자율)
            case B:
                this->specRate = 4;
                break;
                
            // 3 : C (2%의 신용 이자율)
            case C:
                this->specRate = 2;
                break;
                
            default:
                this->specRate = 0;
                break;
        }
    }
    
    // 소멸자
    ~CreditAccount()
    {
        
    }
    
    // 입금 함수
    bool deposit(const int &money)
    {
        // 입금이 실패할 경우
        if (!NormalAccount::deposit(money))
            return false;
        
        // 이율 적용이 실패한 경우
        if (!Account::deposit((int)(money * (specRate / 100.0f))))
            return false;
        
        return true; // 입금 성공
    }
    
    // 계좌 정보 출력 함수
    void showAccountInfo() const
    {
        cout << "[신용 예금계좌]" << endl;
        NormalAccount::showAccountInfo();
        // 신용 이자율이 7인 경우 A 4인경우 B 그외 C
        char grade = specRate == 7 ? 'A' : specRate == 4 ? 'B' : 'C';
        cout << "등  급 : " << grade << endl;
    }
};

#endif
