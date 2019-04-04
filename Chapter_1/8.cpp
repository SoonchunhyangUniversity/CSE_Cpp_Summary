//
//  main.cpp
//  Practice
//
//  Created by 김민수 on 03/04/2019.
//  Copyright © 2019 SCH. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int quiz_1, quiz_2, quiz_3, mid_term, final_term;

    cout << "퀴즈 #1 성적 : ";
    cin >> quiz_1;

    cout << "퀴즈 #2 성적 : ";
    cin >> quiz_2;

    cout << "퀴즈 #3 성적 : ";
    cin >> quiz_3;

    cout << "중간고사 성적 : ";
    cin >> mid_term;
    
    cout << "기말고사 성적 : ";
    cin >> final_term;

    cout << "=================" << endl;
    cout << "성적 총합 : ";
    cout << quiz_1 + quiz_2 + quiz_3 + mid_term + final_term << endl;
    cout << "=================" << endl;

    return 0;
}
