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
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i >= j)
            {
                cout << j + 1;
            }

            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}
