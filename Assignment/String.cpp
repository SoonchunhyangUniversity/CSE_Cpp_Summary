//
//  String.cpp
//  Practice
//
//  Created by 김민수 on 29/05/2019.
//  Copyright © 2019 SCH. All rights reserved.
//

#include "String.h"
#include "BankingCommonDecl.h"

using namespace std;

int accountStrToInt(string account)
{
    string delimiter = "-";
    string temp = account;
    string result = "";
    size_t last = 0;
    size_t next = 0;
    
    while ((next = account.find(delimiter, last)) != string::npos)
    {
        result += temp.substr(last, next - last);
        last = next + 1;
    }
    
    result += temp.substr(last, next - last);
    
    return stoi(result);
}
