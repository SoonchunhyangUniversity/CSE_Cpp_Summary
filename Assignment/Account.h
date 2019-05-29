//
//  Account.h
//  Practice
//
//  Created by 김민수 on 29/05/2019.
//  Copyright © 2019 SCH. All rights reserved.
//

#ifndef Account_h
#define Account_h
#include <iostream>
#include "BankingCommonDecl.h"
/* ------------------------
 * 고객의 계좌정보 클래스
 * ------------------------
 * Member Variable
 * account : 계좌번호
 * balance : 고객잔액
 * phone_number : 휴대폰번호
 * name : 고객이름
 * ------------------------
 * Member Method
 * getter, setter로 구성
 * ------------------------
 */
class bankAccount
{
    int account;
    int balance;
    string phone_number;
    string name;
    
public:
    void setAccount(int account);
    void setBalance(int balance);
    void setPhoneNumber(string phone_number);
    void setName(string name);
    int getAccount();
    int getBalance();
    string getPhoneNumber();
    string getName();
};

#endif /* Account_h */
