//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 5월 5일 레포트
//
//  Created by 김민수 on 2020/05/05.
//  Copyright © 2020 SCH. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdarg.h>

using namespace std;

void exampleSixNine()
{
    int a[5] = { 10, 20, 30, 40, 50 };
    
    cout << "예제 6-9 (배열명과 + 연산자의 관계 알아보기) 실행 결과\n\n";
    
    cout << "   a : " <<   a << " \t &a[0] : " << &a[0] << "\n";
    cout << " a+1 : " << a+1 << " \t &a[1] : " << &a[1] << "\n";
    cout << " a+2 : " << a+2 << " \t &a[2] : " << &a[2] << "\n";
    cout << " a+3 : " << a+3 << " \t &a[3] : " << &a[3] << "\n";
    cout << " a+4 : " << a+4 << " \t &a[4] : " << &a[4] << "\n";
    
    cout << "\n";
}

void exampleSixTen()
{
    int a[5] = { 10, 20, 30, 40, 50 };
    
    cout << "예제 6-10 (포인터를 사용해서 배열의 각 원소값 출력하기) 실행 결과\n\n";
    
    cout << " a[0] : " << a[0] << " \t     *a : " <<     *a << "\n";
    cout << " a[1] : " << a[1] << " \t   *a+1 : " <<   *a+1 << "\n";
    cout << " a[1] : " << a[1] << " \t *(a+1) : " << *(a+1) << "\n";
    
    cout << "\n";
}

void exampleSixEleven()
{
    int a[5] = { 10, 20, 30, 40, 50 };
    int i;
    
    cout << "예제 6-11 (포인터 형태로 배열의 원소값 출력하기) 실행 결과\n\n";
    
    for (i = 0; i < 5; i++)
    {
        cout << "  a+i : " << a+i << "\t &a[i] : " << &a[i] << "\n";
    }
    
    cout << "-------------------------------------------------\n";
    
    for (i = 0; i < 5; i++)
    {
        cout << "  *(a+i) : " << *(a+i) << "\t\t\t a[i] : " << a[i] << "\n";
    }
    
    cout << "\n";
}

void exampleSixTwelve()
{
    int a[5] = { 10, 20, 30, 40, 50 };
    int *p;
    p = a;
    
    cout << "예제 6-12 (배열과 포인터 변수의 관계 알아보기) 실행 결과\n\n";
    cout << "      *p : " << *p;
    cout << "\t  a[0] : " << a[0] << "\n";
    
    cout << "  *(p+1) : " << *(p+1);
    cout << "\t  a[1] : " << a[1] << "\n";
    
    cout << "  *(p+2) : " << *(p+2);
    cout << "\t  a[2] : " << a[2] << "\n";
    
    cout << "\n";
}

void exampleSixThirteen()
{
    int a = 5;
    int *p;
    int **pp;
    p = &a;
    pp = &p;
    
    cout << "예제 6-13 (2차원 포인터 사용하기) 실행 결과\n\n";
    
    cout << "    p : " <<    p << " \t &a : " << &a << endl;
    cout << "   *p : " <<   *p << " \t \t \t \t  a : " << a << endl;
    cout << "   pp : " <<   pp << " \t &p : " << &p << endl;
    cout << "  *pp : " <<  *pp << " \t &p : " << p << endl;
    cout << " **pp : " << **pp << " \t \t \t \t *p : " << *p << endl;
    
    cout << "\n";
}

void exampleSixFourteen()
{
    int a = 10, b = 20, c = 30;
    int *p[3] = { &a, &b, &c };
    
    cout << "예제 6-14 (1차원 포인터를 저장하는 포인터 배열) 실행 결과\n\n";
    
    cout << "     *p[0] : " << *p[0];
    cout << "\t   *p[1] : " << *p[1];
    cout << "\t   *p[2] : " << *p[2] << "\n";
    
    cout << "   p[0][0] : " << p[0][0];
    cout << "\t p[1][0] : " << p[1][0];
    cout << "\t p[2][0] : " << p[2][0] << "\n";
    
    cout << "\n";
}

void exampleSixFifteen()
{
    int a[5] = { 10, 20, 30, 40, 50 };
    int b[5] = { 60, 70, 80, 90, 100 };
    int c[5] = { 110, 120, 130, 140, 150 };
    
    int *p[3] = { a, b, c };
    
    cout << "예제 6-15 (포인터 배열에 1차원 배열의 주소값 저장하기) 실행 결과\n\n";
    
    cout << " >> 각 1 차원 배열의 첫번째 원소 출력 << \n";
    cout << "\t " << p[0][0] << "\t " << p[1][0] << "\t " << p[2][0] << "\n\n";
    
    cout << " >> 각 1 차원 배열의 두번째 원소 출력 << \n";
    cout << "\t " << p[0][1] << "\t " << p[1][1] << "\t " << p[2][1] << "\n";
    
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

int main(int argc, const char * argv[])
{
    exampleSixNine();
    useSystem(2, "pause", "cls");

    exampleSixTen();
    useSystem(2, "pause", "cls");

    exampleSixEleven();
    useSystem(2, "pause", "cls");

    exampleSixTwelve();
    useSystem(2, "pause", "cls");

    exampleSixThirteen();
    useSystem(2, "pause", "cls");

    exampleSixFourteen();
    useSystem(2, "pause", "cls");

    exampleSixFifteen();
    useSystem(1, "pause");
    
    return 0;
}
