//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 6월 2일 레포트
//
//  Created by 김민수 on 2020/06/02.
//  Copyright © 2020 SCH. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#define PI 3.141592
#define MAX 20
#define _MYDEBUG 10
#define SIZE 10
#define SQUARE1(x) x * x
#define SQUARE2(x) ((x) * (x))
#define add1(a, b) a + b
using namespace std;

void exampleNineOne()
{
    cout << "예제 9-1 (매크로 상수를 이용해서 원의 면적 구하기) 실행 결과\n\n";
    
	int r = 5;
	double area;
	area = r * r * PI;

	cout << "area = " << area << "\n";

	cout << "\n";
}

void exampleNineTwo()
{
    cout << "예제 9-2 (제곱 승을 구하는 매크로 함수의 잘못된 예 살펴보기) 실행 결과\n\n";
	int a = 5, res;

	res = SQUARE1(a+2);
	cout << " SQUARE1(a+2) => " << res << "\n";

	res = 100 / SQUARE1(a);
	cout << " 100/SQUARE1(a) => " << res << "\n";
	
	cout << "\n";
}

void exampleNineThree()
{
    cout << "예제 9-3 (제곱 승을 구하는 매크로 함수 정의하기) 실행 결과\n\n";
	int a = 5, res;

	res = SQUARE2(a+2);
	cout << " SQUARE2(a+2) => " << res << "\n";

	res = 100 / SQUARE2(a);
	cout << " 100/SQUARE2(a) => " << res << "\n";
	
	cout << "\n";
}

inline int add2(int a, int b)
{
    return a + b;
}

int add3(int a, int b)
{
    return a + b;
}

void exampleNineFour()
{
    cout << "예제 9-4 (매크로 함수, 인라인 함수, 일반 함수의 차이점 살펴보기) 실행 결과\n\n";
	int result;

	result = 2 * add1(10, 20);
	cout << "macro 함수 => " << result << "\n";

	result = 2 * add2(10, 20);
	cout << "inline 함수 => " << result << "\n";

	result = 2 * add3(10, 20);
	cout << "일반 함수 => " << result << "\n";
	cout << "\n";
}

void exampleNineFive()
{
    cout << "예제 9-5 (조건부 컴파일을 위한 선행처리자 살펴보기) 실행 결과\n\n";

	int size;

#if MAX > 100
	size = 100;
#elif MAX > 10
	size = 10;
#else
	size = 0;
#endif

	cout << " size = " << size << "\n";

	cout << "\n";
}

#ifdef _MYDEBUG
void sub()
{
    cout << " debug\n";
}
#endif

#ifndef _MYDEBUG
void sub()
{
    cout << " release\n";
}
#endif

void exampleNineSix()
{
    cout << "예제 9-6 (#ifdef문, #ifnedf문 사용하기) 실행 결과\n\n";
	sub();
	cout << "\n";
}

void exampleNineSeven()
{
    cout << "예제 9-7 (#undef문 사용하기) 실행 결과\n\n";
	int i, j;
	i = SIZE;

#ifdef SIZE
	#undef SIZE
	#define SIZE 20
#endif

	j = SIZE;

	cout << " i = " << i << ", j = " << j << "\n";

	cout << "\n";
}

void exampleNineEight()
{
    cout << "예제 9-8 (사용자 정의 헤더파일 만들고 사용하기) 실행 결과\n\n";
	int a;
	double res;
	a = 5;

	res = area(a);

	cout << "area => " << res << "\n";
	cout << "PI => " << PI_TWO << "\n";

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
     cout << "\n201744444 - 김민수" << endl;
}

int main(int argc, const char * argv[])
{
    exampleNineOne();
	useSystem(2, "pause", "cls"); 

	exampleNineTwo();
	useSystem(2, "pause", "cls"); 

	exampleNineThree();
	useSystem(2, "pause", "cls"); 

	exampleNineFour();
	useSystem(2, "pause", "cls"); 

	exampleNineFive();
	useSystem(2, "pause", "cls"); 

	exampleNineSix();
	useSystem(2, "pause", "cls"); 

	exampleNineSeven();
	useSystem(2, "pause", "cls"); 

	exampleNineEight();
	useSystem(2, "pause", "cls"); 

    printStudentInfo();
    useSystem(2, "pause");
    
    return 0;
}
