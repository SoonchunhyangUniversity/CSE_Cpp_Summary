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
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0)
        {
            cout << "박수 ";
        }

        else
        {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
