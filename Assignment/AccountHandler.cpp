#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "String.h"
#include "NormalAccount.h"
#include "CreditAccount.h"

using namespace std;

BankingManagementSystem:: BankingManagementSystem() : accountList(100), account_num(0)
{
    
}

void BankingManagementSystem:: showMenu()
{
    cout << endl
    << "---------- Menu ----------" << endl
    << "1. 계좌개설" << endl
    << "2. 입    금" << endl
    << "3. 출    금" << endl
    << "4. 계좌정보 전체 출력" << endl
    << "5. 프로그램 종료" << endl
    << endl
    << "   선택 : ";
}
    
void BankingManagementSystem:: makeAccount()
{
    int input;
        
    cout << endl << "[계좌종류 선택]" << endl;
    cout << "1. 보통예금   2. 신용예금" << endl;
    cout << "   선택 : ";
        
    cin >> input;
    cout << endl;
        
    switch (input)
    {
        case BankingManagementSystem::NORMAL:
            makeNormalAccount();
            break;
                
        case BankingManagementSystem::CREDIT:
            makeCreditAccount();
            break;
                
        default:
            break;
    }
}
    
void BankingManagementSystem::deposit()
{
    if (account_num == 0)
    {
        cout << "개설된 계좌가 없습니다." << endl;
        return;
    }
    
    string account;
    int accountInt;
    int money = 0;
    
    cout << "[입    금]" << endl;
    cout << "계좌 ID : "; cin >> account;
    accountInt = accountStrToInt(account);
    
    while (true)
    {
        cout << "입금액 : "; cin >> money;
        
        try
        {
            for (int i = 0; i < account_num; i++)
            {
                if (accountInt == accountList[i]->getAccountNumber())
                {
                    if (accountList[i]->deposit(money))
                    {
                        cout << "입금완료" << endl;
                        return;
                    }
                    
                    else
                    {
                        cout << "입금실패" << endl;
                        return;
                    }
                }
            }
            cout << "없는 고객입니다." << endl;
            return;
        }
        catch (BankingException &expn)
        {
            expn.showExceptionLog();
        }
    }
}

void BankingManagementSystem::withdraw()
{
    if (account_num == 0)
    {
        cout << "개설된 계좌가 없습니다." << endl;
        return;
    }
    
    string account;
    int accountInt;
    int money = 0;
    
    cout << "[출    금]" << endl;
    cout << "계좌 ID : "; cin >> account;
    accountInt = accountStrToInt(account);
    
    while (true)
    {
        cout << "출금액 : "; cin >> money;
        
        try
        {
            for (int i = 0; i < account_num; i++)
            {
                if (accountInt == accountList[i]->getAccountNumber())
                {
                    if (accountList[i]->withdraw(money))
                    {
                        cout << "출금완료" << endl;
                        return;
                    }
                    
                    else
                    {
                        cout << "입금실패" << endl;
                        return;
                    }
                }
            }
            cout << "없는 고객입니다." << endl;
            return;
        }
        catch (BankingException &expn)
        {
            expn.showExceptionLog();
        }
    }
}

void BankingManagementSystem::showAllAccountInfo()
{
    if (account_num == 0)
    {
        cout << "개설된 계좌가 없습니다." << endl;
        return;
    }
    
    for (int i = 0; i < account_num; i++)
        accountList[i]->showAccountInfo();
    
    cout << endl << account_num << "의 계좌 조회" << endl;
}

void BankingManagementSystem::finish()
{
    for (int i = 0; i < account_num; i++)
        delete accountList[i];
    
    exit(0);
}

void BankingManagementSystem::makeNormalAccount()
{
    string accountStr;
    String name;
    int accountInt;
    int money;
    int rate;
        
    cout << "[보통예금 개설]" << endl;
    cout << "계좌ID : "; cin >> accountStr;
    cout << "이  름 : "; cin >> name;
    cout << "입금액 : "; cin >> money;
    cout << "이자율 : "; cin >> rate;
    
    accountInt = accountStrToInt(accountStr);
        
    accountList[account_num++] = new NormalAccount(accountInt, name, money, rate);
}
    
void BankingManagementSystem::makeCreditAccount()
{
    string accountStr;
    String name;
    int accountInt;
    int money;
    int rate;
    int specRate;
    
    cout << "[신용예금 개설]" << endl;
    cout << "계좌ID : "; cin >> accountStr;
    cout << "이  름 : "; cin >> name;
    cout << "입금액 : "; cin >> money;
    cout << "이자율 : "; cin >> rate;
    cout << "고객등급(1toA, 2toB, 3toC) : "; cin >> specRate;
    
    accountInt = accountStrToInt(accountStr);
    
    accountList[account_num++] = new CreditAccount(accountInt, name, money, rate, specRate);
}

template <typename T>
ArrayLengthChecker<T>::ArrayLengthChecker(int len) : arrLen(len)
{
    arr = new T[len];
}

template <typename T>
ArrayLengthChecker<T>::~ArrayLengthChecker()
{
    delete []arr;
}

template <typename T>
T& ArrayLengthChecker<T>::operator[](const int &idx)
{
    if (idx < 0 || idx >= arrLen)
    {
        cout << "배열 범위 초과" << endl;
        exit(1);
    }
    
    return arr[idx];
}

template <typename T>
T ArrayLengthChecker<T>::operator[](const int &idx) const
{
    if (idx < 0 || idx >= arrLen)
    {
        cout << "배열 범위 초과" << endl;
        exit(1);
    }
    
    return arr[idx];
}
