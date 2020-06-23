//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 6월 23일 레포트
//
//  Created by 김민수 on 2020/06/23.
//  Copyright © 2020 SCH. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdarg.h>

using namespace std;

class Calc {
protected:
	int a;
	int b;
	int c;
public:
	void Init(int new_A, int new_B);
	void Prn();
};

void Calc::Init(int new_A, int new_B)
{
    a = new_A;
	b = new_B;
	c = 0;
}

void Calc::Prn()
{
    cout << a << "\t" << b << "\t" << c << endl;
}

class Add : public Calc {
public:
	void Sum();
};

void Add::Sum()
{
    c = a + b;
}

class Mul : public Calc {
public:
	void Gob();
};

void Mul::Gob()
{
    c = a * b;
}

void exampleTwelveOne()
{
    cout << "예제 12-1 (기반 클래스와 파생 클라스 설계하기) 실행 결과\n\n";
    
	Add x;
	x.Init(3, 5);

	Mul y;
	y.Init(2, 7);

	x.Sum();
	x.Prn();

	y.Gob();
	y.Prn();

	cout << "\n";
}

class Base {
public:
	Base();
	~Base();
};

Base::Base()
{
    cout << " 기반 클래스의 생성자 " << endl;
}

Base::~Base()
{
    cout << " 기반 클래스의 소멸자 \n" << endl;
}

class Derived : public Base {
public:
	Derived();
	~Derived();
};

Derived::Derived()
{
    cout << " 파생 클래스의 생성자 " << endl;
}

Derived::~Derived()
{
    cout << " 파생 클래스의 소멸자 " << endl;
}

void exampleTwelveTwo()
{
    cout << "예제 12-2 (상속 관계에서의 생성자와 소멸자 알아보기) 실행 결과\n\n";
    
	Derived obj;
}

class CalcTwo {
protected:
	int a;
	int b;
	int c;
public:
	CalcTwo(int new_A, int new_B);
	CalcTwo();
	void Prn();
};

CalcTwo::CalcTwo(int new_A, int new_B)
{
    a = new_A;
	b = new_B;
	c = 0;
}

CalcTwo::CalcTwo()
{
    a = 0;
	b = 0;
	c = 0;
}

void CalcTwo::Prn()
{
    cout << a << "\t" << b << "\t" << c << endl;
}

void exampleTwelveThree()
{
    cout << "예제 12-3 (Calc 클래스에 생성자 정의하기) 실행 결과\n\n";
    
	CalcTwo x(3, 5);
	x.Prn();

	cout << "\n";
}

class AddTwo : public CalcTwo {
public:
	void Sum();
};

void AddTwo::Sum()
{
    c = a + b;
}

void exampleTwelveFour()
{
    cout << "예제 12-4 (생성자를 정의한 Calc 클래스의 파생 클래스 설계하기) 실행 결과\n\n";
    
	cout << " 함수는 2개의 매개 변수를 사용하지 않습니다." << endl;

	// AddTwo y(3, 5);
	// y.Prn();

	cout << "\n";
}

class AddThree : public CalcTwo {
public:
	void Sum();
	AddThree(int new_A, int new_B);
	AddThree();
};

void AddThree::Sum()
{
    c = a + b;
}

AddThree::AddThree(int new_A, int new_B) : CalcTwo(new_A, new_B)
{
	a = new_A;
	b = new_B;
	c = 0;
}

AddThree::AddThree() : CalcTwo()
{
}

class AddFour : public CalcTwo {
public:
	void Sum();
	AddFour(int new_A, int new_B);
	AddFour();
	void Prn();
};

void AddFour::Sum()
{
    c = a + b;
}

void AddFour::Prn()
{
   cout << a << " + " << b << " = " << c << endl;
}

AddFour::AddFour(int new_A, int new_B) : CalcTwo(new_A, new_B)
{
	a = new_A;
	b = new_B;
	c = 0;
}

AddFour::AddFour() : CalcTwo()
{
}

class MulTwo : public CalcTwo {
public:
	void Gob();
	MulTwo(int new_A, int new_B);
	MulTwo();
	void Prn();
};

void MulTwo::Gob()
{
    c = a * b;
}

void MulTwo::Prn()
{
   cout << a << " * " << b << " = " << c << endl;
}

MulTwo::MulTwo(int new_A, int new_B) : CalcTwo(new_A, new_B)
{
	a = new_A;
	b = new_B;
	c = 0;
}

MulTwo::MulTwo() : CalcTwo()
{
}

void exampleTwelveFive()
{
    cout << "예제 12-5 (Add 클래스에 생성자 정의하기) 실행 결과\n\n";
    
	cout << " 사용할 수 있는 적절한 기본 생성자가 없습니다." << endl;

	// AddThree y(3,5);
	//y.Prn();

	cout << "\n";
}

void exampleTwelveSix()
{
    cout << "예제 12-6 (상속 관계에서 생성자 문제 해결하기) 실행 결과\n\n";
    
	CalcTwo x(3, 5);
	x.Prn();

	AddThree y(3, 5);
	y.Prn();

	AddThree z;
	z.Prn();

	cout << "\n";
}

void exampleTwelveSeven()
{
    cout << "예제 12-7 (함수 오버라이딩하기) 실행 결과\n\n";
    
	CalcTwo x(3, 5);
	x.Prn();

	AddFour y(3, 5);
	y.Sum();
	y.Prn();

	MulTwo z(3, 5);
	z.Gob();
	z.Prn();

	cout << "\n";
}

class CalcThree {
protected:
	int a;
	int b;
public:
	CalcThree();
	CalcThree(int new_A, int new_B);
	void CalcPrn();
};

CalcThree::CalcThree()
{
    a = 0;
	b = 0;
}

CalcThree::CalcThree(int new_A, int new_B)
{
    a = new_A;
	b = new_B;
}

void CalcThree::CalcPrn()
{
    cout << "--- Calc::CalcPrn --- " << endl;
	cout << a << "\t" << b << endl;
}

class AddFive : public CalcThree {
protected:
	int c;
public:
	AddFive();
	AddFive(int new_A, int new_B);
	void Sum();
	void AddPrn();
};

AddFive::AddFive() : CalcThree()
{
}

AddFive::AddFive(int new_A, int new_B) : CalcThree(new_A, new_B)
{
    a = new_A;
	b = new_B;
}

void AddFive::Sum()
{
    c = a + b;
}

void AddFive::AddPrn()
{
    cout << "--- Add::Addprn --- " << endl;
	cout << a << " + " << b << " = " << c << endl;
}

void exampleTwelveEight()
{
    cout << "예제 12-8 (업 캐스팅하기) 실행 결과\n\n";
    
	AddFive AddObj(3, 5);
	AddFive *AddPtr;
	AddPtr = &AddObj;
	AddPtr->Sum();
	AddPtr->AddPrn();

	CalcThree *CalcPtr;
	CalcPtr = &AddObj;
	CalcPtr->CalcPrn();

	cout << "\n";
}

void exampleTwelveNine()
{
    cout << "예제 12-9 (다운 캐스팅하기) 실행 결과\n\n";
    
	CalcThree *CalcPtr;
	CalcPtr = new AddFive(3, 5);
	CalcPtr->CalcPrn();

	AddFive *AddPtr;
	AddPtr = (AddFive *)CalcPtr;
	AddPtr->CalcPrn();
	AddPtr->Sum();
	AddPtr->AddPrn();

	cout << "\n";
}

void exampleTwelveTen()
{
    cout << "예제 12-10 (다운 캐스팅의 잘못된 예 알아보기) 실행 결과\n\n";
    
	cout << "'Calc *'에서 'Add *'(으)로 변환할 수 없습니다." << endl;

	//CalcThree Obj(3, 5);
	//AddFive *AddPtr;
	//AddPtr = &Obj;
	// AddPtr = (AddFive *)&Obj;
	//AddPtr->CalcPrn();
	//AddPtr->Sum();

	cout << "\n";
}

class CalcFour {
protected:
	int a;
	int b;
public:
	CalcFour();
	CalcFour(int new_A, int new_B);
	void Prn();
};

CalcFour::CalcFour()
{
    a = 0;
	b = 0;
}

CalcFour::CalcFour(int new_A, int new_B)
{
    a = new_A;
	b = new_B;
}

void CalcFour::Prn()
{
    cout << "--- Calc::Prn --- " << endl;
	cout << a << "\t" << b << endl;
}

class AddSix : public CalcFour {
protected:
	int c;
public:
	AddSix();
	AddSix(int new_A, int new_B);
	void Sum();
	void Prn();
};

AddSix::AddSix() : CalcFour()
{
}

AddSix::AddSix(int new_A, int new_B) : CalcFour(new_A, new_B)
{
    a = new_A;
	b = new_B;
	c = 0;
}

void AddSix::Sum()
{
    c = a + b;
}

void AddSix::Prn()
{
    cout << "--- Add::Prn --- " << endl;
	cout << a << " + " << b << " = " << c << endl;
}

void exampleTwelveEleven()
{
    cout << "예제 12-11 (기반 클래스형 포인터 변수로 오버라이딩된 멤버함수 호출하기) 실행 결과\n\n";
    
	CalcFour * CalcPtr;
	CalcPtr = new AddSix(3, 5);
	CalcPtr->Prn();

	cout << "\n";
}

class CalcFive {
protected:
	int a;
	int b;
public:
	CalcFive();
	CalcFive(int new_A, int new_B);
	virtual void Prn();
};

CalcFive::CalcFive()
{
    a = 0;
	b = 0;
}

CalcFive::CalcFive(int new_A, int new_B)
{
    a = new_A;
	b = new_B;
}

void CalcFive::Prn()
{
    cout << "--- Calc::Prn --- " << endl;
	cout << a << "\t" << b << endl;
}

class AddSeven : public CalcFive {
protected:
	int c;
public:
	AddSeven();
	AddSeven(int new_A, int new_B);
	void Sum();
	void Prn();
};

AddSeven::AddSeven() : CalcFive()
{
}

AddSeven::AddSeven(int new_A, int new_B) : CalcFive(new_A, new_B)
{
    a = new_A;
	b = new_B;
	c = 0;
}

void AddSeven::Sum()
{
    c = a + b;
}

void AddSeven::Prn()
{
    cout << "--- Add::Prn --- " << endl;
	cout << a << " + " << b << " = " << c << endl;
}


void exampleTwelveTwelve()
{
    cout << "예제 12-12 (가상함수로 동적 바인딩하기) 실행 결과\n\n";
    
	CalcFive * CalcPtr;
	CalcPtr = new AddSeven(3, 5);
	CalcPtr->Prn();

	cout << "\n";
}

class Shape
{
protected:
	double area;
public:
	virtual void Draw() = 0;
	virtual double GetSize() = 0;
};

class Rect : public Shape {
protected:
	int width;
	int height;
public:
	Rect(int w=0, int h=0);
	void Draw();
	double GetSize();
};

Rect::Rect(int w, int h)
{
    width = w;
	height = h;
}

void Rect::Draw()
{
    cout << "사각형을 그린다" << endl;
}

double Rect::GetSize()
{
    area = width * height;
	return area;
}

class Circle : public Shape {
protected:
	int radius;
public:
	Circle(int r = 0);
	void Draw();
	double GetSize();
};

Circle::Circle(int r)
{
    radius = r;
}

void Circle::Draw()
{
    cout << "원을 그린다." << endl;
}

double Circle::GetSize()
{
    area = radius * radius * 3.14;
	return area;
}

void exampleTwelveThirteen()
{
    cout << "예제 12-13 (추상 클래스와 완전 가상함수를 이용해서 사각형과 원 클래스 설계하기) 실행 결과\n\n";
    
	Rect recObj(8, 10);
	recObj.Draw();
	cout << "사각형의 면적 : " << recObj.GetSize() << endl;

	Circle cirObj(5);
	cirObj.Draw();
	cout << "원의 면적 : " << cirObj.GetSize() << endl;

	cout << "\n";
}

void CommonPrn(Shape *ptr)
{
    ptr->Draw();
}

void exampleTwelveFourteen()
{
    cout << "예제 12-14 (추상 클래스와 다형성 이용하기) 실행 결과\n\n";
    
	CommonPrn(new Rect);
	CommonPrn(new Circle);

	cout << "\n";
}

void exampleTwelveFifteen()
{
    cout << "예제 12-15 (일반 소멸자 사용 시 문제점 알아보기) 실행 결과\n\n";
    
	Base *BasePtr = new Derived;
	delete BasePtr;
}

class BaseTwo {
public:
	BaseTwo();
	virtual ~BaseTwo();
};

BaseTwo::BaseTwo()
{
    cout << " 기반 클래스의 생성자 " << endl;
}

BaseTwo::~BaseTwo()
{
    cout << " 기반 클래스의 소멸자 \n" << endl;
}

class DerivedTwo : public BaseTwo {
public:
	DerivedTwo();
	~DerivedTwo();
};

DerivedTwo::DerivedTwo()
{
    cout << " 파생 클래스의 생성자 " << endl;
}

DerivedTwo::~DerivedTwo()
{
    cout << " 파생 클래스의 소멸자 " << endl;
}

void exampleTwelveSixteen()
{
    cout << "예제 12-16 (가상 소멸자 사용 예 알아보기) 실행 결과\n\n";
    
	BaseTwo *BasePtr = new DerivedTwo;
	delete BasePtr;
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
    exampleTwelveOne();
	useSystem(2, "pause", "cls"); 

	exampleTwelveTwo();
	useSystem(2, "pause", "cls"); 

	exampleTwelveThree();
	useSystem(2, "pause", "cls"); 

    exampleTwelveFour();
	useSystem(2, "pause", "cls"); 

	exampleTwelveFive();
	useSystem(2, "pause", "cls"); 

	exampleTwelveSix();
	useSystem(2, "pause", "cls"); 

	exampleTwelveSeven();
	useSystem(2, "pause", "cls"); 

	exampleTwelveEight();
	useSystem(2, "pause", "cls"); 

	exampleTwelveNine();
	useSystem(2, "pause", "cls"); 

	exampleTwelveTen();
	useSystem(2, "pause", "cls"); 

	exampleTwelveEleven();
	useSystem(2, "pause", "cls"); 

	exampleTwelveTwelve();
	useSystem(2, "pause", "cls"); 

	exampleTwelveThirteen();
	useSystem(2, "pause", "cls"); 

	exampleTwelveFourteen();
	useSystem(2, "pause", "cls"); 

	exampleTwelveFifteen();
	useSystem(2, "pause", "cls"); 

	exampleTwelveSixteen();
	useSystem(2, "pause", "cls"); 

    printStudentInfo();
    useSystem(2, "pause");
    
    return 0;
}
