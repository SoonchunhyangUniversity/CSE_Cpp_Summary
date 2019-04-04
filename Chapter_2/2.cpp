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

    cout << "콜라, 물, 스프라이트, 주스, 커피 중에서 하나를 선택하세요 : ";
    cin >> input;

    switch(input)
    {
        case 1:
            cout << "콜라를 선택하셨습니다." << endl;
            break;

        case 2:
            cout << "물을 선택하셨습니다." << endl;
            break;

        case 3:
            cout << "스프라이트 선택하셨습니다." << endl;
            break;

        case 4:
            cout << "주스 선택하셨습니다." << endl;
            break;

        case 5:
            cout << "커피 선택하셨습니다." << endl;
            break;
            
        default:
            cout << "오류. 선택이 유효하지 않습니다. 돈을 반환합니다." << endl;
    }

    return 0;
}
