#ifndef AccountHandler_h
#define AccountHandler_h
#include <iostream>

using namespace std;

class Account;

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
    ArrayLengthChecker(int len) : arrLen(len)
    {
        arr = new T[len];
    }
    
    ~ArrayLengthChecker()
    {
        delete []arr;
    }
    
    T& operator[](const int &idx)
    {
        if (idx < 0 || idx >= arrLen)
        {
            cout << "배열 범위 초과" << endl;
            exit(1);
        }
        
        return arr[idx];
    }
    
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


class BankingManagementSystem
{
    ArrayLengthChecker<Account *> accountList;
    int account_num;
    
public:
    enum {CREATE = 1, DEPOSIT, WITHDRAW, SHOW, FINISH};
    enum {NORMAL = 1, CREDIT};
    
    BankingManagementSystem();
    
    void showMenu();
    void makeAccount();
    void deposit();
    void withdraw();
    void showAllAccountInfo();
    void finish();
    
protected:
    void makeNormalAccount();
    void makeCreditAccount();
};

#endif
