//
//  BankingManagementSystemMain.cpp
//  Practice
//
//  Created by 김민수 on 29/05/2019.
//  Copyright © 2019 SCH. All rights reserved.
//

#include "String.h"

using namespace std;

void printMenu()
{
    cout <<
    "---------- Menu ----------" << endl
    << "1. 계좌개설" << endl
    << "2. 입    금" << endl
    << "3. 출    금" << endl
    << "4. 계좌정보 전체 출력" << endl
    << "5. 프로그램 종료" << endl << endl;
}

int main()
{
    int input = 0;
    
    do
    {
        printMenu();
        
        cout << "   선택 : ";
        cin >> input;
        
        switch(input)
        {
            case 1:
                break;
                
            case 2:
                break;
                
            case 3:
                break;
                
            case 4:
                break;
                
            case 5:
                break;
                
            default:
                cout << "Input Error!" << endl;
                break;
        }
    } while (input != 5);
    
    return 0;
}
