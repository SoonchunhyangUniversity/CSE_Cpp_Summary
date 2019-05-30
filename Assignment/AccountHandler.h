#ifndef AccountHandler_h
#define AccountHandler_h

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
    ArrayLengthChecker(int len = 100);
    ~ArrayLengthChecker();
    T& operator[] (const int &idx);
    T operator[] (const int &idx) const;
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
