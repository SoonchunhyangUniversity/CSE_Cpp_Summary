//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 6월 9일 레포트
//
//  Created by 김민수 on 2020/06/09.
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
	void SetComplex();
	void ShowComplex();
	void SetReal(int r);
	void SetImage(int i);
};

class ComplexTwo
{
private:
	int real;
	int image;
public:
	void SetComplex()
	{
        real = 2;
		image = 5;
	}
	void ShowComplex();
};

class ComplexThree
{
private:
	int real;
	int image;
public:
	void SetComplex();
	void ShowComplex() const;
};

class ComplexFour
{
private:
	int real;
	int image;
public:
	ComplexFour();
	void ShowComplex() const;
};

class ComplexFive
{
private:
	int real;
	int image;
public:
	ComplexFive(int r, int i);
	void ShowComplex() const;
};

class ComplexSix
{
private:
	int real;
	int image;
public:
	ComplexSix();
	ComplexSix(int r, int i);
	void ShowComplex() const;
};

class ComplexSeven
{
private:
	int real;
	int image;
public:
	ComplexSeven(int r=0, int i=0);
	void ShowComplex() const;
};

class ComplexEight
{
private:
	int real;
	int image;
public:
	ComplexEight(int r=0, int i=0);
	void ShowComplex() const;
};

class ComplexNine
{
private:
	int real;
	int image;
public:
	ComplexNine(int r=0, int i=0);
	~ComplexNine();
	void ShowComplex() const;
};


void Complex::SetComplex()
{
    real = 2;
	image = 5;
}

void Complex::ShowComplex()
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

void Complex::SetReal(int r)
{
    real = r;
}

void Complex::SetImage(int i)
{
    image = i;
}

inline void ComplexTwo::ShowComplex()
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

void ComplexThree::SetComplex()
{
    real = 2;
	image = 5;
}

void ComplexThree::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

ComplexFour::ComplexFour()
{
    real = 5;
	image = 20;
}

void ComplexFour::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

ComplexFive::ComplexFive(int r, int i)
{
    real = r;
	image = i;
}

void ComplexFive::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

ComplexSix::ComplexSix()
{
    real = 0;
	image = 0;
}

ComplexSix::ComplexSix(int r, int i)
{
    real = r;
	image = i;
}

void ComplexSix::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

ComplexSeven::ComplexSeven(int r, int i)
{
    real = r;
	image = i;
}

void ComplexSeven::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

ComplexEight::ComplexEight(int r, int i) : real(r), image(i)
{
}

void ComplexEight::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

ComplexNine::ComplexNine(int r, int i) : real(r), image(i)
{
}

ComplexNine::~ComplexNine()
{
    cout << "소멸자가 호출된다. \n";
}

void ComplexNine::ShowComplex() const
{
    cout << "( " << real << " + " << image << "i )" << endl;
}

void exampleTenOne()
{
    cout << "예제 10-1 (복소수를 클래스로 설계하기) 실행 결과\n\n";
    
	Complex x, y;

	x.SetComplex();
	x.ShowComplex();
	y.SetComplex();
	y.ShowComplex();

	cout << "\n";
}

void exampleTenTwo()
{
    cout << "예제 10-2 (private 멤버 성격 파악하기) 실행 결과\n\n";
    
	Complex x;

	// x.real = 5; 컴파일 에러
	// x.image = 10; // 컴파일 에러
	x.ShowComplex();

	cout << "\n";
}

void exampleTenThree()
{
    cout << "예제 10-3 (private 멤버를 다루기 위한 멤버함수 추가하기) 실행 결과\n\n";
    
	Complex x;

	x.SetReal(5);
	x.SetImage(10);
	x.ShowComplex();

	cout << "\n";
}

void exampleTenFour()
{
    cout << "예제 10-4 (인라인 함수 사용하기) 실행 결과\n\n";
    
	ComplexTwo x;

	x.SetComplex();
	x.ShowComplex();

	cout << "\n";
}

void exampleTenFive()
{
    cout << "예제 10-5 (const 멤버함수 사용하기) 실행 결과\n\n";
    
	ComplexThree x;

	x.SetComplex();
	x.ShowComplex();

	cout << "\n";
}

void printstr(char *the_string)
{
    cout << the_string << endl;
}

void printstr(char the_char, int repeat_cnt)
{
    for (int i = 0; i < repeat_cnt; i++)
		cout << the_char;

	cout << endl;
}

void exampleTenSix()
{
    cout << "예제 10-6 (함수의 오버로딩 살펴보기) 실행 결과\n\n";
    
	printstr("I'm Sorry");
	printstr('a', 3);

	cout << "\n";
}

int myabs(int num)
{
    if (num < 0)
		num = -num;

	return num;
}

double fmyabs(double num)
{
    if (num < 0)
		num = -num;

	return num;
}

long int lmyabs(long int num)
{
    if (num < 0)
		num = -num;

	return num;
}

void exampleTenSeven()
{
    cout << "예제 10-7 (함수의 오버로딩 없이 절댓값 구하기) 실행 결과\n\n";
    
	int a = -10;
	cout << a << "의 절댓값은 -> " << myabs(a) << endl;

	double b = -3.4;
	cout << b << "의 절댓값은 -> " << fmyabs(b) << endl;

	long int c = -20L;
	cout << c << "의 절댓값은 -> " << lmyabs(c) << endl;

	cout << "\n";
}

int abs2(int num)
{
    if (num < 0)
		num = -num;

	return num;
}

double abs2(double num)
{
    if (num < 0)
		num = -num;

	return num;
}

long int abs2(long int num)
{
    if (num < 0)
		num = -num;

	return num;
}

void exampleTenEight()
{
    cout << "예제 10-8 (매개변수의 자료형이 다른 함수의 오버로딩을 이용해서 절댓값 구하기) 실행 결과\n\n";
    
	int a = -10;
	cout << a << "의 절댓값은 -> " << abs2(a) << endl;

	double b = -3.4;
	cout << b << "의 절댓값은 -> " << abs2(b) << endl;

	long int c = -20L;
	cout << c << "의 절댓값은 -> " << abs2(c) << endl;

	cout << "\n";
}

void print(int x, int y, int z)
{
    cout << x << " " << y << " " << z << endl;
}

void print(int x, int y)
{
    cout << x << " " << y << endl;
}

void print(int x)
{
    cout << x << endl;
}

void exampleTenNine()
{
    cout << "예제 10-9 (매개변수의 개수가 다른 함수의 오버로딩 살펴보기) 실행 결과\n\n";
    
	print(10, 20, 30);
	print(10, 20);
	print(10);

	cout << "\n";
}

void printTwo(int x=0, int y=0, int z=0)
{
    cout << x << " " << y << " " << z << endl;
}

void exampleTenTen()
{
    cout << "예제 10-10 (함수의 매개변수에 기본값 지정하기) 실행 결과\n\n";
    
	printTwo(10, 20, 30);
	printTwo(10, 20);
	printTwo(10);
	printTwo();

	cout << "\n";
}

void exampleTenEleven()
{
    cout << "예제 10-11 (매개변수가 없는 생성자 작성하기) 실행 결과\n\n";

	ComplexFour x;
	x.ShowComplex();

	cout << "\n";
}

void exampleTenTwleve()
{
    cout << "예제 10-12 (다양한 초깃값 매개변수를 사용하는 생성자 작성하기) 실행 결과\n\n";

	ComplexFive x(10, 20);
	ComplexFive y(30, 40);

	x.ShowComplex();
	y.ShowComplex();

	cout << "\n";
}

void exampleTenThirteen()
{
    cout << "예제 10-13 (생성자 오버로딩하기) 실행 결과\n\n";

	ComplexSix x(10, 20);
	ComplexSix y(30, 40);
	ComplexSix z;

	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();

	cout << "\n";
}

void exampleTenFourteen()
{
    cout << "예제 10-14 (생성자의 기본 매개변수 값 설정하기) 실행 결과\n\n";

	ComplexSeven x(10, 20);
	ComplexSeven y(30);
	ComplexSeven z;

	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();

	cout << "\n";
}

void exampleTenFifteen()
{
    cout << "예제 10-15 (생성자 콜론 초기화하기) 실행 결과\n\n";

	ComplexEight x(10, 20);
	ComplexEight y(30);
	ComplexEight z;

	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();

	cout << "\n";
}

void exampleTenSixteen()
{
    cout << "예제 10-16 (소멸자 정의하기) 실행 결과\n\n";

	ComplexNine x(10, 20);
	ComplexNine y(30);
	ComplexNine z;

	x.ShowComplex();
	y.ShowComplex();
	z.ShowComplex();

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
    exampleTenOne();
	useSystem(2, "pause", "cls"); 

	exampleTenTwo();
	useSystem(2, "pause", "cls"); 

	exampleTenThree();
	useSystem(2, "pause", "cls"); 

    exampleTenFour();
	useSystem(2, "pause", "cls"); 

	exampleTenFive();
	useSystem(2, "pause", "cls"); 

	exampleTenSix();
	useSystem(2, "pause", "cls"); 

	exampleTenSeven();
	useSystem(2, "pause", "cls"); 

	exampleTenEight();
	useSystem(2, "pause", "cls"); 

	exampleTenNine();
	useSystem(2, "pause", "cls"); 

	exampleTenTen();
	useSystem(2, "pause", "cls"); 

	exampleTenEleven();
	useSystem(2, "pause", "cls"); 

	exampleTenTwleve();
	useSystem(2, "pause", "cls"); 

	exampleTenThirteen();
	useSystem(2, "pause", "cls"); 

	exampleTenFourteen();
	useSystem(2, "pause", "cls"); 

	exampleTenFifteen();
	useSystem(2, "pause", "cls"); 

	exampleTenSixteen();
	useSystem(2, "pause", "cls"); 

    printStudentInfo();
    useSystem(2, "pause");
    
    return 0;
}
