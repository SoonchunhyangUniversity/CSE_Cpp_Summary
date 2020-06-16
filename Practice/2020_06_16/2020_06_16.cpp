//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 6월 16일 레포트
//
//  Created by 김민수 on 2020/06/16.
//  Copyright © 2020 SCH. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdarg.h>

using namespace std;

class Complex
{
private:
	int real;
	int image;
public:
	Complex(int r=0, int i=0);
	void ShowComplex() const;
	friend void prnTwo(Complex *pCom);
};

Complex::Complex(int r, int i) : real(r), image(i)
{
}

void Complex::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

void exampleElevenOne()
{
    cout << "예제 11-1 (객체 포인터 사용하기) 실행 결과\n\n";
    
	Complex x(10, 20);
	Complex y;

	cout << " Object x => ";
	x.ShowComplex();

	cout << " Object y => ";
	y.ShowComplex();

	Complex *pCom;
	pCom = &x;

	cout << "\n pCom->ShowComplex() => ";
	pCom->ShowComplex();

	pCom = &y;

	cout << " pCom->ShowComplex() => ";
	pCom->ShowComplex();

	cout << "\n";
}

class ComplexTwo
{
private:
	int real;
	int image;
public:
	ComplexTwo(int r=0, int i=0);
	void ShowComplex() const;
};

ComplexTwo::ComplexTwo(int real, int image)
{
    this->real = real;
    this->image = image;
}

void ComplexTwo::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

void exampleElevenTwo()
{
    cout << "예제 11-2 (this 포인터를 명시적으로 사용하기) 실행 결과\n\n";
    
	Complex x(10, 20);
	x.ShowComplex();

	cout << "\n";
}

class ComplexThree
{
private:
	int real;
	int image;
public:
	ComplexThree(int r=0, int i=0);
	void ShowComplex() const;
	void SetComplex(int r=0, int i=0);
};

ComplexThree::ComplexThree(int r, int i)
{
    real = r;
    image = i;
}

void ComplexThree::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

void ComplexThree::SetComplex(int r, int i)
{
    real = r;
	image = i;
}

void exampleElevenThree()
{
    cout << "예제 11-3 (객체 단위로 값 치환하기) 실행 결과\n\n";
    
	ComplexThree x(10, 20);
	ComplexThree y;

	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();

	cout << "----------------------------\n";

	y = x;
	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();

	cout << "----------------------------\n";

	y.SetComplex(30, 40);
	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();
	cout << "\n";
}

void CopyComplex(ComplexThree des, ComplexThree src)
{
    des = src;
}

void exampleElevenFour()
{
    cout << "예제 11-4 (객체의 값에 의한 전달 방식의 함수 작성하기) 실행 결과\n\n";
    
	ComplexThree x(10, 20);
	ComplexThree y(30, 40);

	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();

	cout << "----------------------------\n";

	CopyComplex(y, x);

	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();

	cout << "\n";
}

ComplexThree CopyComplexTwo(ComplexThree des, ComplexThree src)
{
    des = src;

	return des;
}

void exampleElevenFive()
{
    cout << "예제 11-5 (결과값이 객체인 함수 작성하기) 실행 결과\n\n";

    ComplexThree x(10, 20);
	ComplexThree y(30, 40);

	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();

	cout << "----------------------------\n";

	y = CopyComplexTwo(y, x);

	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();

	cout << "\n";
}

void CopyComplexThree(ComplexThree *pDes, ComplexThree src)
{
    *pDes = src;
}

void exampleElevenSix()
{
    cout << "예제 11-6 (객체의 주소에 의한 전달 방식의 함수 작성하기) 실행 결과\n\n";
    
	ComplexThree x(10, 20);
	ComplexThree y(30, 40);

	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();

	cout << "----------------------------\n";

	CopyComplexThree(&y, x);

	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();

	cout << "\n";
}

ComplexThree &CopyComplexFour(ComplexThree &des, const ComplexThree &src)
{
    des = src;

	return des;
}

void exampleElevenSeven()
{
    cout << "예제 11-7 (객체의 참조에 의한 전달 방식의 함수 작성하기) 실행 결과\n\n";
    
	ComplexThree x(10, 20);
	ComplexThree y(30, 40);
	ComplexThree z;

	z = CopyComplexFour(y, x);
	cout << " x => ";
	x.ShowComplex();
	cout << " y => ";
	y.ShowComplex();
	cout << " z => ";
	z.ShowComplex();

	cout << "\n";
}

class StaticTest
{
public:
	static int a;
	int b;

StaticTest();
};

StaticTest::StaticTest()
{
	b=20;
}

int StaticTest::a = 10;

void exampleElevenEight()
{
    cout << "예제 11-8 (클래스 단위 맴버변수와 인스턴스 단위 맴버변수의 차이점 알아보기) 실행 결과\n\n";
    
	cout << " StaticTest::a => " << StaticTest::a << "\n\n";

	StaticTest s1, s2;

	cout << " s1.a -> " << s1.a << "\t s2.a -> " << s2.a << "\n";
	cout << " s1.b -> " << s1.b << "\t s2.b -> " << s2.b << "\n\n";

	s1.a = 100;

	cout << " s1.a => " << s1.a << "\t";
	cout << " s2.a => " << s2.a << "\n\n";

	s1.b = 200;

	cout << " s1.b => " << s1.b << "\t";
	cout << " s2.b => " << s2.b << "\n";

	cout << "\n";
}

class StaticTestTwo
{
private:
	static int a;
	int b;

public:
	StaticTestTwo();
	static void SetA(int new_a);
	static int GetA();
};

int StaticTestTwo::a=10;

StaticTestTwo::StaticTestTwo()
{
	b=20;
}

void StaticTestTwo::SetA(int new_a)
{
    a = new_a;
}

int StaticTestTwo::GetA()
{
    return a;
}

void exampleElevenNine()
{
    cout << "예제 11-9 (정적 맴버함수 정의하기) 실행 결과\n\n";
    
	cout << " StaticTest::GetA() => " << StaticTestTwo::GetA() << "\n\n";

	StaticTestTwo s1, s2;

	s1.SetA(10000);

	cout << " s1.GetA() -> " << s1.GetA() << "\t";
	cout << " s2.GetA() -> " << s2.GetA() << "\n";

	cout << "\n";
}

class StaticTestThree
{
private:
	static int a;
	int b;

public:
	StaticTestThree();
	static void PrintA();
	void PrintB();
};

int StaticTestThree::a=10;

StaticTestThree::StaticTestThree()
{
	b=20;
}

void StaticTestThree::PrintA()
{
    cout << " a : " << a << endl;
}

void StaticTestThree::PrintB()
{
    cout << " this->b : " << this->b << endl;
}

void exampleElevenTen()
{
    cout << "예제 11-10 (정적 맴버함수 사용 시 주의점 살펴보기) 실행 결과\n\n";
    
	StaticTestThree s1;

	s1.PrintA();
	s1.PrintB();

	cout << "\n";
}

class CStud
{
    char name[30];
	char hphone[20];
	char email[30];
	static int cnt;

public:
	CStud(char *n="성윤정", char *h="017-777-7777", char *e="pink@daum.net");
	~CStud();
	void prn();
	static void prn_cnt();
};

int CStud::cnt=0;

CStud::CStud(char *n, char *h, char *e)
{
    strcpy(name, n);
	strcpy(hphone, h);
	strcpy(email, e);
	cnt++;
}

CStud::~CStud()
{
    cnt--;
}

void CStud::prn()
{
    cout << "이름 : " << name << endl;
    cout << "핸드폰 : " << hphone << endl;
    cout << "이메일 : " << email << endl;
}

void CStud::prn_cnt()
{
    cout << "\n현재까지 등록된 인원수 : " << cnt << "\n\n";
}

void exampleElevenEleven()
{
    cout << "예제 11-11 (인스턴스의 개수를 세는 정적 맴버변수 이용하기) 실행 결과\n\n";

	CStud::prn_cnt();

	CStud man1("전수빈", "010-9807-0975", "subin@pride.com");
	man1.prn();
	CStud man2("전원지", "010-9807-0975", "won@pride.com");
	man2.prn();

	cout << "\n# 중간에 인원수를 파악합니다.";
	CStud::prn_cnt();

	CStud man3;
	man3.prn();

	cout << "\n클래스의 할당된 메모리 사이즈 : " << sizeof(CStud);
	cout << "\n";

	CStud::prn_cnt();

	cout << "\n";
}

void exampleElevenTwleve()
{
    cout << "예제 11-12 (객체 배열 사용하기) 실행 결과\n\n";

	Complex arr[4] = {
		Complex(2, 4),
		Complex(4, 8),
		Complex(8, 16),
		Complex(16, 32),
	};

	for (int i = 0; i < 4; i++)
		arr[i].ShowComplex();

	cout << "\n";
}

void exampleElevenThirteen()
{
    cout << "예제 11-13 (객체 배열을 객체 포인터로 간접 참조하기) 실행 결과\n\n";

	Complex arr[4] = {
		Complex(2, 4),
		Complex(4, 8),
		Complex(8, 16),
		Complex(16, 32),
	};

	Complex *pCom = arr;

	pCom->ShowComplex();
	(pCom+1)->ShowComplex();

	cout << "\n";
}

void prn(Complex *pCom)
{
    for (int i = 0; i < 4; i++)
		pCom[i].ShowComplex();
}

void exampleElevenFourteen()
{
    cout << "예제 11-14 (매개변수가 객체 배열인 함수 작성하기) 실행 결과\n\n";

	Complex arr[4] = {
		Complex(2, 4),
		Complex(4, 8),
		Complex(8, 16),
		Complex(16, 32),
	};

	prn(arr);

	cout << "\n";
}

void prnTwo(Complex *pCom)
{
    for (int i = 0; i < 4; i++)
		cout << "( " << pCom[i].real << " + " << pCom[i].image << "i )" << endl;
}

void exampleElevenFifteen()
{
    cout << "예제 11-15 (프렌드 함수 정의하기) 실행 결과\n\n";

	Complex arr[4] = {
		Complex(2, 4),
		Complex(4, 8),
		Complex(8, 16),
		Complex(16, 32),
	};

	prnTwo(arr);

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
     cout << "\n201744444 - 김민수\n" << endl;
}

int main(int argc, const char * argv[])
{
    exampleElevenOne();
	useSystem(2, "pause", "cls"); 

	exampleElevenTwo();
	useSystem(2, "pause", "cls"); 

	exampleElevenThree();
	useSystem(2, "pause", "cls"); 

    exampleElevenFour();
	useSystem(2, "pause", "cls"); 

	exampleElevenFive();
	useSystem(2, "pause", "cls"); 

	exampleElevenSix();
	useSystem(2, "pause", "cls"); 

	exampleElevenSeven();
	useSystem(2, "pause", "cls"); 

	exampleElevenEight();
	useSystem(2, "pause", "cls"); 

	exampleElevenNine();
	useSystem(2, "pause", "cls"); 

	exampleElevenTen();
	useSystem(2, "pause", "cls"); 

	exampleElevenEleven();
	useSystem(2, "pause", "cls"); 

	exampleElevenTwleve();
	useSystem(2, "pause", "cls"); 

	exampleElevenThirteen();
	useSystem(2, "pause", "cls"); 

	exampleElevenFourteen();
	useSystem(2, "pause", "cls"); 

	exampleElevenFifteen();
	useSystem(2, "pause", "cls"); 

    printStudentInfo();
    useSystem(2, "pause");
    
    return 0;
}
