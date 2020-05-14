//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 5월 12일 레포트
//
//  Created by 김민수 on 2020/05/12.
//  Copyright © 2020 SCH. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#define ROW 3
#define COL 4

using namespace std;

int arr1[ROW][COL] = {
    { 90, 85, 95, 100 },
    { 75, 95, 80, 90 },
    { 90, 80, 70, 60 }
};

int arr2[5] = { 10, 20, 30, 40, 50 };

void eaxampleSixSixteen()
{
    cout << "예제 6-16 (2차원 배열의 주소값 출력하기) 실행 결과\n\n";
    
    cout << "2차원 배열에 저장된 원소들의 주소\n";
    cout << "-------------------------------------------------------------------";
    
    for (int r = 0; r < ROW; r++)
    {
        cout << "\n" << r << "행 ";
        
        for (int c = 0; c < COL; c++)
        {
            cout << "\t " << &arr1[r][c];
        }
    }
    cout << "\n\n";
}

void exampleSixSeventeen()
{
    cout << "예제 6-17 (2차원 배열의 행만 지정해서 출력하기) 실행 결과\n\n";
    
    cout << "2차원 배열에 저장된 원소들의 주소\n";
    cout << "-------------------------------------------------------------------";
    
    for (int r = 0; r < ROW; r++)
    {
        cout << " \n" << r << "행 ";
        cout << "\t a[" << r << "] = " << arr1[r];
        cout << "\t &a[" << r << "][0] = " << &arr1[r][0];
    }
    
    cout << "\n\n각 행의 첫번째 열에 위치한 원소\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "  *a[0]=" << *arr1[0] << "\t *a[1]=" << *arr1[1] << "\t *a[2]=" << *arr1[2] << "\n";

	cout << "\n";
}

void exampleSixEighteen()
{
    cout << "예제 6-18 (2차원 배열명의 의미 파악하기) 실행 결과\n\n";
    
    cout << "     a : " << arr1 << "\n";
    cout << "    *a : " << *arr1 << "\n";
    cout << "   **a : " << **arr1 << "\n";
    cout << "------------------------\n";
    cout << " a + 1 : " << arr1 + 1 << "\n";
    cout << " a + 2 : " << arr1 + 2 << "\n";

	cout << "\n";
}

void exampleSixNineteen()
{
    cout << "예제 6-19 (배열의 원소를 포인터 연산자를 이용해서 출력하기) 실행 결과\n\n";
    
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            cout << "*(*(a+" << r << ")+" << c << ")):" << *(*(arr1+r)+c) << " \t";
        }
        cout << "\n";
    }

	cout << "\n";
}

void sevenOnePrn(int *pa, int size)
{
    for (int i = 0; i < size; i ++)
    {
        cout << "\t" << *(pa+i);
    }

    cout << "\n";
}

void exampleSevenOne()
{
    cout << "예제 7-1 (배열의 원소를 출력하는 함수 사용하기) 실행 결과\n\n";
    
    sevenOnePrn(arr2, 5);

	cout << "\n";
}

void sevenTwoPrn(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << "\t" << a[i];
    cout << endl;
    cout << "  prn 함수 sizeof(a) : " << sizeof(a) << endl;
}

void exampleSevenTwo()
{
    cout << "예제 7-2 (포인터 변수를 배열로 표현하기) 실행 결과\n\n";
    
    sevenTwoPrn(arr2, 5);
    cout << " main 함수 sizeof(a) : " << sizeof(arr2) << endl;

	cout << "\n";
}

void sevenThreePrn(int (*p)[COL])
{
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
            cout << "*(*(a+" << r << ")+"<< c << ")):" << *(*(p+r)+c) << "   ";
        cout << "\n";
    }
}

void exampleSevenThree()
{
    cout << "예제 7-3 (2차원 배열을 전달받는 함수 작성하기) 실행 결과\n\n";
    sevenThreePrn(arr1);

	cout << "\n";
}

void sevenFourPrn(int p[][4])
{
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            cout <<"a[" << r << "][" << c << " : " << p[r][c] << "\t";
        }
        cout << "\n";
    }
    cout << "prn sizeof(p) = " << sizeof(p) << "\n";
}

void exampleSevenFour()
{
    cout << "예제 7-4 (2차원 배열을 매개변수로 사용하는 함수 작성하기) 실행 결과\n\n";
    
    cout << "main sizeof(a) = " << sizeof(arr1) << "\n";
    sevenFourPrn(arr1);

	cout << "\n";
}

void sevenFivePrn(const int *p, int size)
{
    for (int i = 0; i < size; i++)
        cout << p[i] << "\t";
    cout << "\n";
    // p[0] = 100;
}

void exampleSevenFive()
{
    cout << "예제 7-5 (배열의 원소값이 변하지 않도록 막기 위한 형식 매개변수 지정하기) 실행 결과\n\n";
    
    int size = sizeof(arr2) / sizeof(arr2[0]);
    
    sevenFivePrn(arr2, size);

	cout << "\n";
}

void exampleSevenSix()
{
    cout << "예제 7-6 (포인터 변수에 문자열 대입하기) 실행 결과\n\n";
    
    char str[25] = "Apple";
    char *ptr = "Banana";
    
    cout << "  str = " << (int)str << " \t str = " << str << "\n";
    cout << "  ptr = " << (int)ptr << " \t ptr = " << ptr << "\n";
    
    // str = "Grapes";
    
    ptr = "Orange";
    
    cout << "  ptr = " << (uintptr_t)ptr << "\t ptr = " << ptr << "\n";

	cout << "\n";
}

void useSystem(int args, ...)
{
    va_list ap;

    va_start(ap, args);

    for (int i = 0; i < args; i++)
    {
        char *oper = va_arg(ap, char *);
        system(oper);
    }

    va_end(ap);
}

void printStudentInfo()
{
     std::cout << "\n201744444 - 김민수" << std::endl;
}

int main(int argc, const char * argv[])
{
    
    eaxampleSixSixteen();
    useSystem(2, "pause", "cls");
    
    exampleSixSeventeen();
    useSystem(2, "pause", "cls");
    
    exampleSixEighteen();
    useSystem(2, "pause", "cls");
    
    exampleSixNineteen();
    useSystem(2, "pause", "cls");
    
    exampleSevenOne();
    useSystem(2, "pause", "cls");
    
    exampleSevenTwo();
    useSystem(2, "pause", "cls");
    
    exampleSevenThree();
    useSystem(2, "pause", "cls");
    
    exampleSevenFour();
    useSystem(2, "pause", "cls");
    
    exampleSevenFive();
    useSystem(2, "pause", "cls");
    
    exampleSevenSix();
    useSystem(2, "pause", "cls");
    
    printStudentInfo();
    useSystem(2, "pause");
    
    return 0;
}
