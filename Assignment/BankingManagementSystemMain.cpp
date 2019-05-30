#include "BankingCommonDecl.h"
#include "AccountHandler.h"

using namespace std;

int main()
{
    BankingManagementSystem bmsHandler;
    int input;
    
    while (true)
    {
        bmsHandler.showMenu();
        cin >> input;
        cout << endl;
        
        switch (input)
        {
            case BankingManagementSystem::CREATE:
                bmsHandler.makeAccount();
                break;
                
            case BankingManagementSystem::DEPOSIT:
                bmsHandler.deposit();
                break;
                
            case BankingManagementSystem::WITHDRAW:
                bmsHandler.withdraw();
                break;
                
            case BankingManagementSystem::SHOW:
                bmsHandler.showAllAccountInfo();
                break;
                
            case BankingManagementSystem::FINISH:
                bmsHandler.finish();
                
            default:
                continue;
        }
    }
    
    return 0;
}
