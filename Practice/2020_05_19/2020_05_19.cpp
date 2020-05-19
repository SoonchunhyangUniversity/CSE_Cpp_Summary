//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 5월 19일 레포트
//
//  Created by 김민수 on 2020/05/19.
//  Copyright © 2020 SCH. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdarg.h>

using namespace std;

struct namecard
{
    char name[20];
	char job[30];
	char tel[20];
	char email[40];
};

void exampleSevenSeven()
{
    cout << "예제 7-7 (char형 포인터 배열 사용하기) 실행 결과\n\n";
    
	char *ptr[3] = {"rabbit", "tiger", "cow"};

	cout << "  &ptr[0]="<< (int)&ptr[0] << " \t &ptr[1]=" << (int)&ptr[1] <<
		" \t &ptr[2]=" << (int)&ptr[2] << " \n";

	cout << "   ptr[0]="<< (int)ptr[0] << " \t  ptr[1]=" << (int)ptr[1] <<
		" \t  ptr[2]=" << (int)ptr[2] << " \n\n";

	cout << "   ptr[0]="<< ptr[0] << "\t  ptr[1]=" << ptr[1] <<
		" \t\t  ptr[2]=" << ptr[2] << " \n";

	cout << "  *ptr[0]="<< *ptr[0] << "\t\t *ptr[1]=" << *ptr[1] <<
		" \t\t *ptr[2]=" << *ptr[2] << " \n";
}

void print_string(char **pptr, int n)
{
    for (int i = 0; i < n; i++)
		cout << pptr[i] << "  \n";
}

void exampleSevenEight()
{
    cout << "예제 7-8 (포인터 배열을 매개변수로 사용하는 함수) 실행 결과\n\n";
    
	char *ptr[3] = {"rabbit", "tiger", "cow"};
	print_string(ptr, 3);

	cout << "\n";
}

void one() 
{ 
	cout << "    one \n"; 
}
void two() 
{ 
	cout << "    two \n"; 
}
void three() 
{ 
	cout << "    three \n"; 
}

void (*pf)(void);

void exampleSevenNine()
{
    cout << "예제 7-9 (함수 포인터를 사용해서 함수 호출하기) 실행 결과\n\n";

	pf = one;
	pf();

	pf = two;
	pf();

	pf = three;
	pf();

	cout << "\n";
}


void exampleSevenTen()
{
    cout << "예제 7-10 (함수 포인터를 사용해서 상황에 따른 서로 다른 함수 호출하기) 실행 결과\n\n";
    
	int num;

	while (1)
	{
	    cout << "0부터 3사이의 숫자를 입력하되 끝내려면 0 입력 => ";
		cin >> num;

		switch(num)
		{
		case 0:
			cout << "    종료 \n";
			return;

		case 1:
			pf = one;
			break;

		case 2:
			pf = two;
			break;

		case 3:
			pf = three;
			break;
		}
		pf();
	}

	cout << "\n";
}

void exampleEightOne()
{
    cout << "예제 8-1 (구조체를 정의하고 사용하기) 실행 결과\n\n";

	struct namecard man;

	cout << " 이름을 입력하세요 => ";
	cin >> man.name;

	cout << " 직업을 입력하세요 => ";
	cin >> man.job;

	cout << " 연락처를 입력하세요 => ";
	cin >> man.tel;

	cout << " 이메일을 입력하세요 => ";
	cin >> man.email;

	cout << "\n 입력받은 데이터를 출력합니다. ";
	cout << "\n 이름 \t 직업 \t 연락처 \t 이메일 ";
	cout << "\n ===================================";
	cout << "\n " << man.name << "\t" << man.job 
		<< "\t" << man.tel << "\t" << man.email;
	cout << "\n ===================================";
    cout << "\n sizeof(namecard) => " << sizeof(namecard);
	cout << "\n 구조체 변수의 메모리 사이즈 => " << sizeof(namecard) << "\n";

	cout << "\n";
}

void exampleEightTwo()
{
    cout << "예제 8-2 (구조체 초기화하기) 실행 결과\n\n";
    
	namecard x = {"김주현", "MSCE전문강사", "418-9876", "freentour@naver.com"};
	namecard y = {"박혜경", "웹마스터", "551-6986", "hk@naver.com"};
	namecard z = {"김동식", "기획A팀대리", "318-3961", "ds@naver.com"};

	cout << "  이름 \t 직업 \t\t 연락처 \t\t 이메일 ";
	cout << "\n===================================================================";
	cout << "\n " << x.name << "\t" << x.job << "\t" << x.tel << "\t" << x.email;
	cout << "\n " << y.name << "\t" << y.job << "\t" << y.tel << "\t" << y.email;
	cout << "\n " << z.name << "\t" << z.job << "\t" << z.tel << "\t" << z.email;
	cout << "\n ===================================================================";

	cout<< "\n";
}

void exampleEightThree()
{
    cout << "예제 8-3 (구조체 단위로 값 복사하기) 실행 결과\n\n";
    
	namecard x = {"김주현", "MSCE전문강사", "418-9876", "freentour@naver.com"};
	namecard y;

	y = x;

	cout << "\t\t 이름 \t 직업 \t\t 연락처 \t\t 이메일 ";
	cout << "\n\t\t ===================================================================";
	cout << "\n<구조체 변수 x>";
	cout << "\t " << x.name << "\t" << x.job << "\t" << x.tel << "\t" << x.email;
	cout << "\n<구조체 변수 y>";
	cout << "\t " << y.name << "\t" << y.job << "\t" << y.tel << "\t" << y.email;
	cout << "\n\t\t ===================================================================";

	cout<< "\n";
}

void structPrn(namecard temp)
{
    cout << "\n" << temp.name << "\t" << temp.job << "\t"
		<< temp.tel << " \t" << temp.email;
}

void exampleEightFour()
{
    cout << "예제 8-4 (값에 의한 전달 방식으로 구조체를 매개변수로 사용하는 함수) 실행 결과\n\n";
    
	namecard x = {"김주현", "MSCE전문강사", "418-9876", "freentour@naver.com"},
		y = {"박혜경", "웹마스터", "551-6986", "hk@naver.com"},
		z = {"김동식", "기획A팀대리", "318-3961", "ds@naver.com"};

	cout << "\n 이름 \t 직업 \t\t 연락처 \t\t 이메일 ";
	cout << "\n======================================================================";
	structPrn(x);
	structPrn(y);
	structPrn(z);
	cout << "\n=======================================================================";

	cout<< "\n";
}

namecard structInput()
{
    namecard temp;

	cout << "\n이름을 입력하세요 => ";
	cin >> temp.name;

	cout << "직업을 입력하세요 => ";
	cin >> temp.job;

	cout << "연락처를 입력하세요 => ";
	cin >> temp.tel;

	cout << "이메일을 입력하세요 => ";
	cin >> temp.email;

	return temp;
}

void exampleEightFive()
{
    cout << "예제 8-5 (구조체 단위의 입력 함수 작성하기) 실행 결과\n\n";
    
	namecard x, y, z;

	x = structInput();
	y = structInput();
	z = structInput();

	cout << "\n 이름 \t 직업 \t\t 연락처 \t\t 이메일 ";
	cout << "\n======================================================================";
	structPrn(x);
	structPrn(y);
	structPrn(z);
	cout << "\n=======================================================================";

	cout<< "\n";
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
    exampleSevenSeven();
	useSystem(2, "pause", "cls"); 

    exampleSevenEight();
	useSystem(2, "pause", "cls");

    exampleSevenNine();
	useSystem(2, "pause", "cls");

	exampleSevenTen();
	useSystem(2, "pause", "cls");

    exampleEightOne();
	useSystem(2, "pause", "cls");

    exampleEightTwo();
	useSystem(2, "pause", "cls");

	exampleEightThree();
	useSystem(2, "pause", "cls");

	exampleEightFour();
    useSystem(2, "pause", "cls");

    exampleEightFive();
    useSystem(2, "pause", "cls");
   
    
    printStudentInfo();
    useSystem(2, "pause");
    
    return 0;
}
