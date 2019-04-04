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
    int l, w, h;

    cout << "길이 : ";
    cin >> l;

    cout << "너비 : ";
    cin >> w;

    cout << "높이 : ";
    cin >> h;

    printf("상자의 부피 : %d\n", l * w * h);
    printf("상자의 표면적 : %d\n", 2 * ((l * w) + (l * h) + (h * w)));

    return 0;
}
