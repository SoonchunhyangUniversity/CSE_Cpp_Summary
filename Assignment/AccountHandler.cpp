#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "String.h"
#include "Account.h"
#include "CreditAccount.h"
#include "NormalAccount.h"

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [accountStrToInt 문자열인 계좌번호를 정수형으로 변환]
 * @param  account [문자열 계좌번호]
 * @return         [정수형 계좌번호]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
int accountStrToInt(string account)
{
    string delimiter = "-"; // "-"를 기준으로 구분
    string temp = account;
    string result = ""; // "-"를 없앤 문자열을 저장할 변수
    size_t last = 0;
    size_t next = 0;
    
    // "-"를 기준으로 이전 위치부터 탐색 문자열의 끝까지 반복
    while ((next = account.find(delimiter, last)) != string::npos)
    {
        result += temp.substr(last, next - last);
        // result에 부분 문자열 추가
        last = next + 1;
    }
    
    // account가 123-456-789일 경우
    // 현재 result는 123456
    // 맨뒤의 789는 아직 추가되지 않음
    // 따라서 substr를 한번더 사용해 추가
    result += temp.substr(last, next - last);
    
    return stoi(result); // string to int함수로 정수 반환
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [BankingManagementSystem 생성자]
 * 계좌 리스트 100개, 초기 계좌 개수 0개로 초기화 및 생성
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
BankingManagementSystem:: BankingManagementSystem() : accountList(100), account_num(0)
{
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [showMenu 메뉴 출력 함수]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [makeAccount 계좌 생성 과정 함수]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
void BankingManagementSystem:: makeAccount()
{
    int input;
    
    cout << "[계좌종류 선택]" << endl;
    cout << "1. 보통예금   2. 신용예금" << endl;
    cout << "   선택 : ";
    
    cin >> input;
    cout << endl;
    
    switch (input)
    {
        // 1 : NORMAL (보통계좌 생성)
        case BankingManagementSystem::NORMAL:
            makeNormalAccount();
            break;
            
        // 2 : CREDIT (신용계좌 생성)
        case BankingManagementSystem::CREDIT:
            makeCreditAccount();
            break;
            
        default:
            break;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [deposit 출금 함수]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
void BankingManagementSystem::deposit()
{
    // 개설 계좌가 없는 경우
    if (account_num == 0)
    {
        cout << "개설된 계좌가 없습니다." << endl;
        return;
    }
    
    string account;
    int accountInt;
    int money = 0;
    
    // 입금할 계좌 입력후 문자열로 변환
    cout << "[입    금]" << endl;
    cout << "계좌 ID : "; cin >> account;
    accountInt = accountStrToInt(account);
    
    while (true)
    {
        cout << "입금액 : "; cin >> money;
        
        try
        {
            // 개설 계좌 개수만큼 반복
            for (int i = 0; i < account_num; i++)
            {
                // 계좌번호가 입력값과 같은 경우
                if (accountInt == accountList[i]->getAccountNumber())
                {
                    // 입금 성공시
                    if (accountList[i]->deposit(money))
                    {
                        cout << "입금완료" << endl;
                        return;
                    }
                    
                    // 입금 실패시
                    else
                    {
                        cout << "입금실패" << endl;
                        return;
                    }
                }
            }
            
            // 모든 배열 탐색 완료시 없는 계좌번호
            cout << "없는 고객입니다." << endl;
            return;
        }
        catch (BankingException &expn)
        {
            expn.showExceptionLog();
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [withdraw 출금 함수]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * deposit함수와 동일한 logic으로 구성
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
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
                        cout << "출금실패" << endl;
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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [showAllAccountInfo 모든 계좌 정보 출력 함수]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
void BankingManagementSystem::showAllAccountInfo()
{
    // 계좌가 하나도 없는 경우
    if (account_num == 0)
    {
        cout << "개설된 계좌가 없습니다." << endl;
        return;
    }
    
    // 계좌 개수(account_num)만큼 반복
    for (int i = 0; i < account_num; i++)
    {
        accountList[i]->showAccountInfo();
        // showAccountInfo 매서드 사용
        cout << endl;
    }
    
    // 총 계좌 개수 출력
    cout << account_num << "의 계좌 조회" << endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [finish 프로그램 종료시 실행 함수]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
void BankingManagementSystem::finish()
{
    // 계좌 개수(account_num)만큼 반복
    for (int i = 0; i < account_num; i++)
        delete accountList[i]; // 객체 삭제
    
    exit(0); // 프로그램 종료
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [makeNormalAccount 보통계좌 생성 함수]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
void BankingManagementSystem::makeNormalAccount()
{
    // 변수 선언
    string accountStr;
    String name;
    int accountInt;
    int money;
    int rate;
    
    // 변수에 값 입력
    cout << "[보통예금 개설]" << endl;
    cout << "계좌ID : "; cin >> accountStr;
    cout << "이  름 : "; cin >> name;
    cout << "입금액 : "; cin >> money;
    cout << "이자율 : "; cin >> rate;
    
    // 문자열의 계좌를 정수형으로 변환
    accountInt = accountStrToInt(accountStr);
    
    // 동일 계좌 존재 확인
    for (int i = 0; i < account_num; i++)
    {
        if (accountList[i]->getAccountNumber() == accountInt)
        {
            cout << endl << "동일 계좌번호가 존재합니다." << endl;
            cout << "다시 계좌를 생성해주세요." << endl;
            return;
        }
    }
    
    // 동일 계좌가 존재하지 않을 경우 새 계좌 생성
    accountList[account_num++] = new NormalAccount(accountInt, name, money, rate);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [makeCreditAccount 신용계좌 생성 함수]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
void BankingManagementSystem::makeCreditAccount()
{
    // 변수 선언
    string accountStr;
    String name;
    int accountInt;
    int money;
    int rate;
    int specRate;
    
    // 변수에 값 입력
    cout << "[신용예금 개설]" << endl;
    cout << "계좌ID : "; cin >> accountStr;
    cout << "이  름 : "; cin >> name;
    cout << "입금액 : "; cin >> money;
    cout << "이자율 : "; cin >> rate;
    cout << "고객등급(1toA, 2toB, 3toC) : "; cin >> specRate;
    
    // 문자열의 계좌를 정수형으로 변환
    accountInt = accountStrToInt(accountStr);
    
    for (int i = 0; i < account_num; i++)
    {
        if (accountList[i]->getAccountNumber() == accountInt)
        {
            cout << endl << "동일 계좌번호가 존재합니다." << endl;
            cout << "다시 계좌를 생성해주세요." << endl;
            return;
        }
    }
    
    // 동일 계좌가 존재하지 않을 경우 새 계좌 생성
    accountList[account_num++] = new CreditAccount(accountInt, name, money, rate, specRate);
}
