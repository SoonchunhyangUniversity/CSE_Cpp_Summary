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
    for (int a = 1; a < 100; a++)
    {
        for (int b = 1; b < 100; b++)
        {
            for (int c = 1; c < 100; c++)
            {
                if ((a * a) + (b * b) == (c * c))
                {
                    cout << a << " " << b << " " << c << endl;
                }
            }
        }
    }

    return 0;
}
