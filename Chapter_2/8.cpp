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
    int input;

    cout << "정수를 입력하시오 : ";
    cin >> input;

    for (int i = 1; i <= input; i++)
    {
        if (input % i == 0)
        {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
