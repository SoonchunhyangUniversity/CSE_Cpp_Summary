#include "BankingCommonDecl.h"
#include "AccountHandler.h"

using namespace std;

// 메인 함수
int main()
{
    BankingManagementSystem bmsHandler;
    // BankingManagementSystem 선언 및 생성
    int input;
    
    while (true)
    {
        bmsHandler.showMenu(); // 메뉴 출력
        cin >> input;
        cout << endl;
        
        switch (input)
        {
                // 1 : CREATE (계좌 생성)
            case BankingManagementSystem::CREATE:
                bmsHandler.makeAccount();
                break;
                
                // 2 : DEPOSIT (입금)
            case BankingManagementSystem::DEPOSIT:
                bmsHandler.deposit();
                break;
                
                // 3 : WITHDRAW (출금)
            case BankingManagementSystem::WITHDRAW:
                bmsHandler.withdraw();
                break;
                
                // 4 : SHOW (모든 계좌정보 출력)
            case BankingManagementSystem::SHOW:
                bmsHandler.showAllAccountInfo();
                break;
                
                // 5 : FINISH (프로그램 종료)
            case BankingManagementSystem::FINISH:
                bmsHandler.finish();
                
            default:
                continue;
        }
    }
    
    return 0;
}
