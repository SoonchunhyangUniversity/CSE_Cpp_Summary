//
//  Account.cpp
//  Practice
//
//  Created by 김민수 on 29/05/2019.
//  Copyright © 2019 SCH. All rights reserved.
//

#include "Account.h"

using namespace std;

void bankAccount :: setAccount(int account)
{
    this->account = account;
}

void bankAccount :: setBalance(int balance)
{
    this->balance = balance;
}

void bankAccount :: setPhoneNumber(string phone_number)
{
    this->phone_number = phone_number;
}

void bankAccount :: setName(string name)
{
    this->name = name;
}

int bankAccount :: getAccount()
{
    return this->account;
}

int bankAccount :: getBalance()
{
    return this->balance;
}

string bankAccount :: getPhoneNumber()
{
    return this->phone_number;
}

string bankAccount :: getName()
{
    return this->name;
}
