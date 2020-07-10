//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 7월 7일 레포트
//
//  Created by 김민수 on 2020/07/07.
//  Copyright © 2020 SCH. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdarg.h>

using namespace std;

void exampleFourteenOne()
{
    cout << "예제 14-1 (예외가 발생할 여지가 있는 프로그램 작성하기) 실행 결과\n\n";

	int a, b , c, d;

	cout << "나눗셈을 하기 위해서 데이터를 입력하시오." << endl;
	cout << "나누는 수(피제수)를 입력하시오 => ";
	cin >> a;
	cout << "나누는 수(제수)를 입력하시오 => ";
	cin >> b;
	c = a / b;
	cout << "몫은 -> " << c << endl;
	d = a % b;
	cout << "나머지 -> " << d << endl;

	cout << "\n";
}

void exampleFourteenTwo()
{
    cout << "예제 14-2 (조건문을 이용한 예외처리) 실행 결과\n\n";

	int a, b , c, d;

	cout << "나눗셈을 하기 위해서 데이터를 입력하시오." << endl;
	cout << "나누는 수(피제수)를 입력하시오 => ";
	cin >> a;
	cout << "나누는 수(제수)를 입력하시오 => ";
	cin >> b;

	if (b == 0) {
		cout << "예외 사항이 발생했습니다." << endl;
	} else {
		c = a / b;
		cout << "몫은 -> " << c << endl;
		d = a % b;
		cout << "나머지 -> " << d << endl;
	}

	cout << "\n";
}

void exampleFourteenThree()
{
    cout << "예제 14-3 (try~catch문으로 예외 처리하기) 실행 결과\n\n";

	int a, b , c, d;

	cout << "나눗셈을 하기 위해서 데이터를 입력하시오." << endl;
	cout << "나누는 수(피제수)를 입력하시오 => ";
	cin >> a;
	cout << "나누는 수(제수)를 입력하시오 => ";
	cin >> b;

	try {
		if (b == 0) {
			throw b;
		}
		c = a / b;
		cout << "몫은 -> " << c << endl;
		d = a % b;
		cout << "나머지 -> " << d << endl;
	} catch (int ex) {
		cout << ex << "로 나누려는 시도가 있었으므로 예외 발생" << endl;
	}

	cout << "예외가 발생하더라도 정상 종료된다." << endl;

	cout << "\n";
}

void exampleFourteenFour()
{
    cout << "예제 14-4 (예외 자료형과 catch문의 자료형이 일치하지 않는 경우의 비정상 종료) 실행 결과\n\n";

	int a, b , c, d;

	cout << "나눗셈을 하기 위해서 데이터를 입력하시오." << endl;
	cout << "나누는 수(피제수)를 입력하시오 => ";
	cin >> a;
	cout << "나누는 수(제수)를 입력하시오 => ";
	cin >> b;

	try {
		if (b == 0) {
			throw b;
		}
		c = a / b;
		cout << "몫은 -> " << c << endl;
		d = a % b;
		cout << "나머지 -> " << d << endl;
	} catch (double ex) {
		cout << ex << "로 나누려는 시도가 있었으므로 예외 발생" << endl;
	}

	cout << "예외가 발생하더라도 정상 종료된다." << endl;

	cout << "\n";
}

void divide(int a, int b)
{
    cout << " *** divide 함수 *** " << endl;

	int c, d;

	if (b == 0)
		throw b;

	c = a / b;
	cout << "몫은 -> " << c << endl;
	d = a % b;
	cout << "나머지 -> " << d << endl;
	cout << endl;
}

void exampleFourteenFive()
{
    cout << "예제 14-5 (호출한 함수에 예외 전달하기) 실행 결과\n\n";

	try {
		divide(10, 2);
		divide(10, 0);
		divide(10, 4);
	} catch (int ex) {
		cout << ex << "로 나누려는 시도가 있었으므로 예외 발생" << endl;
	}

	cout << "\n예외가 발생하더라도 정상 종료된다." << endl;

	cout << "\n";
}

void divideTwo(int a, int b)
{
    cout << " *** divide 함수 *** " << endl;

	int c, d;

	try{
		if (b == 0)
			throw b;

		c = a / b;
		cout << "몫은 -> " << c << endl;
		d = a % b;
		cout << "나머지 -> " << d << endl;
	} catch (int ex) {
		cout << ex << "로 나누려는 시도가 있었으므로 예외 발생" << endl;
	}
}

void exampleFourteenSix()
{
    cout << "예제 14-6 (예외를 발생시킨 함수에서 예외처리하기) 실행 결과\n\n";

	divideTwo(10, 2);
	divideTwo(10, 0);
	divideTwo(10, 4);

	cout << "\n";
}

void funcTwo(int a)
{
    try {
		if (a == 0)
			throw "변수의 값이 0 이다.";
		else
			throw a;
	} catch (char * str) {
		cout << str << endl;
	} catch (int ex) {
		cout << "숫자 " << ex << "로 인한 예외발생" << endl;
	}
}

void exampleFourteenSeven()
{
    cout << "예제 14-7 (try문 하나와 catch 블록 여러 개 살펴보기) 실행 결과\n\n";
    
	funcTwo(10);
	funcTwo(0);
	funcTwo(20);

	cout << "\n";
}

void func(int a) throw(char *, int)
{
    if (a == 0)
		throw "변수의 값이 0 이다.";
	else
		throw a;
}

void exampleFourteenEight()
{
    cout << "예제 14-8 (함수에서 발생하는 예외 자료형 명시하기) 실행 결과\n\n";

	try {
		func(10);
	} catch (char * str) {
		cout << str << endl;
	} catch (int ex) {
		cout << "숫자 " << ex << "로 인한 예외발생" << endl;
	}

	cout << "\n";
}

class UserError
{
public:
	void func();
};

void UserError::func()
{
    cout << "사용자 정의 예외" << endl;
}

void exampleFourteenNine()
{
    cout << "예제 14-9 (사용자 정의 예외 클래스(UserError) 정의하기) 실행 결과\n\n";

	try {
		throw UserError();
	} catch (UserError &ex) {
		cout << "사용자 정의 예외발생에 대한 처리" << endl;
		ex.func();
	}

	cout << "\n";
}

class UserErrorTwo 
{
public:
	UserErrorTwo(char *message);
	UserErrorTwo() {}
};

UserErrorTwo::UserErrorTwo(char *message)
{
    cout << message << endl;
}

class Human
{
	char name[20];
	int age;
public:
	Human(char *name, int age);
	void setName(char *name);
	void setAge(int age);
	void prn();
};

Human::Human(char *name, int age)
{
    setName(name);
	setAge(age);
	prn();
}

void Human::setName(char *name)
{
    if (!(strlen(name) >= 2 && strlen(name) <= 8))
		throw UserErrorTwo("이름은 2자이상 8자이하로만 기술하세요.");
	strcpy(this->name, name);
}

void Human::setAge(int age)
{
    if (!(age >= 0 && age <= 120))
		throw UserErrorTwo("나이는 0부터 120사이여야 합니다.");
	this->age = age;
}

void Human::prn()
{
    cout << "name: " << name << "\t age : " << age << endl;
}

void exampleFourteenTen()
{
    cout << "예제 14-10 (예외처리하는 클래스 정의하기) 실행 결과\n\n";

	Human *p1, *p2, *p3;

	try {
		p1 = new Human("전혜빈", 20);
	} catch (UserErrorTwo a) {
		cout << "UserError 예외처리 구문" << endl;
	} 

	try {
		p2 = new Human("안젤리나졸리", 10);
	} catch (UserErrorTwo a) {
		cout << "UserError 예외처리 구문" << endl;
	} 

	try {
		p3 = new Human("고은아", 220);
	} catch (UserErrorTwo a) {
		cout << "UserError 예외처리 구문" << endl;
	} 
	
	cout << "\n";
}

int myabs(int num)
{
    if (num < 0)
		num = -num;
	return num;
}

double myabs(double num)
{
    if (num < 0)
		num = -num;
	return num;
}

long int myabs(long int num)
{
    if (num < 0)
		num = -num;
	return num;
}

void exampleFourteenEleven()
{
    cout << "예제 14-11 (절댓값을 구하는 함수의 오버로딩 살펴보기) 실행 결과\n\n";

	int a = -10;
	cout << a <<"의 절댓값은->" << myabs(a) << endl;
	
	double b = -3.4;
	cout << b <<"의 절댓값은->" << myabs(b) << endl;

	long int c = -20L;
	cout << c <<"의 절댓값은->" << myabs(c) << endl;

	cout << "\n";
}

template <typename T>

T myabsTwo(T num)
{
    if (num < 0)
		num = - num;
	return num;
}

void exampleFourteenTwelve()
{
    cout << "예제 14-12 (젓댓값을 구하는 함수의 템플릿화하기) 실행 결과\n\n";

	int a = -10;
	cout << a <<"의 절댓값은->" << myabsTwo(a) << endl;
	
	double b = -3.4;
	cout << b <<"의 절댓값은->" << myabsTwo(b) << endl;

	long int c = -20L;
	cout << c <<"의 절댓값은->" << myabsTwo(c) << endl;

	cout << "\n";
}

class Test
{
    int value;
public:
	Test (int v);
	void SetValue(int v);
	int GetValue();
};

Test::Test(int v)
{
    value = v;
}

void Test::SetValue(int v)
{
	value = v;
}

int Test::GetValue()
{
    return value;
}

void exampleFourteenThirteen()
{
    cout << "예제 14-13 (정수형 데이터를 저장하고 얻어오는 일반적인 클래스 구현하기) 실행 결과\n\n";

	Test obj1(10);
	obj1.SetValue(10);
	cout << obj1.GetValue() << endl;
	
	Test obj2(5.7);
	cout << obj2.GetValue() << endl;

	cout << "\n";
}

template <typename DATATYPE>

class TestTwo
{
    DATATYPE value;
public:
	TestTwo (DATATYPE v);
	void SetValue(DATATYPE v);
	DATATYPE GetValue();
};

template <typename DATATYPE>
TestTwo<DATATYPE>::TestTwo(DATATYPE v)
{
    value = v;
}

template <typename DATATYPE>
void TestTwo<DATATYPE>::SetValue(DATATYPE v)
{
	value = v;
}

template <typename DATATYPE>
DATATYPE TestTwo<DATATYPE>::GetValue()
{
    return value;
}

void exampleFourteenFourteen()
{
    cout << "예제 14-14 (데이터를 저장하고 얻어오는 템플릿 클래스 정의하기) 실행 결과\n\n";

	TestTwo<int> obj1(10);
	obj1.SetValue(10);
	cout << obj1.GetValue() << endl;
	
	TestTwo<double> obj2(5.7);
	cout << obj2.GetValue() << endl;

	cout << "\n";
}

class Data
{
private:
	int value;
public:
	Data(int v);
	void CopyData(int &v);
	int GetData();
};

Data::Data(int v)
{
    value = v;
}

void Data::CopyData(int &v)
{
    value = v;
}

int Data::GetData()
{
    return value;
}

void exampleFourteenFifteen()
{
    cout << "예제 14-15 (자료를 목사하는 일반 클래스 설계하기) 실행 결과\n\n";

	int a = 10;
	Data obj1(10);
	cout << obj1.GetData() << endl;

	obj1.CopyData(a);
	cout << obj1.GetData() << endl;

	/*double b = 3.4;
	Data obj2(1.5);
	cout << obj2.GetData() << endl;

	obj2.CopyData(b);
	cout << obj1.GetData() << endl;*/

	cout << "\n";
}

template <typename TYPE, typename ARG_TYPE>
class DataTwo
{
private:
	TYPE value;
public:
	DataTwo(TYPE v);
	void CopyData(ARG_TYPE &v);
	TYPE GetData();
};

template <typename TYPE, typename ARG_TYPE>
DataTwo<TYPE, ARG_TYPE>::DataTwo(TYPE v)
{
    value = v;
}

template <typename TYPE, typename ARG_TYPE>
void DataTwo<TYPE, ARG_TYPE>::CopyData(ARG_TYPE &v)
{
    value = v;
}

template <typename TYPE, typename ARG_TYPE>
TYPE DataTwo<TYPE, ARG_TYPE>::GetData()
{
    return value;
}

void exampleFourteenSixteen()
{
    cout << "예제 14-16 (자료형 2개에 대해 템플릿화하기) 실행 결과\n\n";

	int a = 10;
	DataTwo<int, int &> obj1(10);
	cout << obj1.GetData() << endl;

	obj1.CopyData(a);
	cout << obj1.GetData() << endl;

	double b = 3.4;
	DataTwo<double, double &> obj2(1.5);
	cout << obj2.GetData() << endl;

	obj2.CopyData(b);
	cout << obj2.GetData() << endl;

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
    exampleFourteenOne();
	useSystem(2, "pause", "cls"); 

	exampleFourteenTwo();
	useSystem(2, "pause", "cls"); 

	exampleFourteenThree();
	useSystem(2, "pause", "cls"); 

    exampleFourteenFour();
	useSystem(2, "pause", "cls"); 

	exampleFourteenFive();
	useSystem(2, "pause", "cls"); 

	exampleFourteenSix();
	useSystem(2, "pause", "cls"); 

	exampleFourteenSeven();
	useSystem(2, "pause", "cls"); 

	exampleFourteenEight();
	useSystem(2, "pause", "cls"); 

	exampleFourteenNine();
	useSystem(2, "pause", "cls"); 

	exampleFourteenTen();
	useSystem(2, "pause", "cls"); 

	exampleFourteenEleven();
	useSystem(2, "pause", "cls"); 

	exampleFourteenTwelve();
	useSystem(2, "pause", "cls"); 

	exampleFourteenThirteen();
	useSystem(2, "pause", "cls"); 

	exampleFourteenFourteen();
	useSystem(2, "pause", "cls"); 

	exampleFourteenFifteen();
	useSystem(2, "pause", "cls"); 

	exampleFourteenSixteen();
	useSystem(2, "pause", "cls"); 

    printStudentInfo();
    useSystem(2, "pause");
    
    return 0;
}
