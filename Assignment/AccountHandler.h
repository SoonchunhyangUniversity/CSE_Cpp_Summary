#ifndef AccountHandler_h
#define AccountHandler_h
#include <iostream>

using namespace std;

class Account;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [ArrayLengthChecker 크기확인 템플릿 클래스]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
template <typename T>
class ArrayLengthChecker
{
    T *arr;
    int arrLen;
    
    ArrayLengthChecker& operator= (const ArrayLengthChecker& arr)
    {
        
    }
    
    ArrayLengthChecker (const ArrayLengthChecker& arr)
    {
        
    }
    
public:
    // 템플릿 클래스 생성자 정의
    ArrayLengthChecker(int len) : arrLen(len)
    {
        arr = new T[len];
    }
    
    // 템플릿 클래스 소멸자 정의
    ~ArrayLengthChecker()
    {
        delete []arr;
    }
    
    // []연산자 재정의 return by reference
    T& operator[](const int &idx)
    {
        if (idx < 0 || idx >= arrLen)
        {
            cout << "배열 범위 초과" << endl;
            exit(1);
        }
        
        return arr[idx];
    }
    
    // []연사잔자 재정의 return by copy
    T operator[](const int &idx) const
    {
        if (idx < 0 || idx >= arrLen)
        {
            cout << "배열 범위 초과" << endl;
            exit(1);
        }
        
        return arr[idx];
    }
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [BankingManagementSystem 계좌관리 시스템 클래스]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
class BankingManagementSystem
{
    ArrayLengthChecker<Account *> accountList;
    // 템플릿 배열 클래스 선언
    int account_num;
    // 계좌의 개수
    
public:
    // enum자료형 선언 메뉴 선택, 계좌 종류
    enum {CREATE = 1, DEPOSIT, WITHDRAW, SHOW, FINISH};
    enum {NORMAL = 1, CREDIT};
    
    BankingManagementSystem(); // 생성자 선언
    
    void showMenu(); // 메뉴 출력 함수 선언
    void makeAccount(); // 계좌 생성 함수 선언
    void deposit(); // 입금 함수 선언
    void withdraw(); // 출금 함수 선언
    void showAllAccountInfo(); // 모든 계좌 출력 함수 선언
    void finish(); // 종료 함수 선언
    
protected:
    void makeNormalAccount(); // 보통계좌 생성 함수 선언
    void makeCreditAccount(); // 신용계좌 생성 함수 선언
};

#endif
