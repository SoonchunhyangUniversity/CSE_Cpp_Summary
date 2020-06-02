
//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 5월 26일 레포트
//
//  Created by 김민수 on 2020/05/26.
//  Copyright © 2020 SCH. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdarg.h>

using namespace std;

struct sungjuck
{
    char no[8]; char name[16];
    int kor, eng, mat, tot;
    double ave;
    char level;
    int grade;
};

typedef struct sungjuck SJ;

struct namecard
{
    char name[20];
	char job[30];
	char tel[20];
	char email[40];
};

union u_data {
    char ch;
	int num;
};

enum COLOR { RED, GREEN, BLUE, WHITE, BLACK };
enum COLOR_TWO { RED_TWO=-1, GREEN_TWO, BLUE_TWO=35, WHITE_TWO, BLACK_TWO=2 };

void structPrn(namecard temp)
{
    cout << "\n" << temp.name << "\t" << temp.job << "\t"
		<< temp.tel << " \t" << temp.email;
}

void structPointerInput(namecard *pTemp)
{
    cout << "이름을 입력하세요 => ";
	cin >> pTemp->name;
	cout << "직업을 입력하세요 => ";
	cin >> pTemp->job;
	cout << "연락처를 입력하세요 => ";
	cin >> pTemp->tel;
	cout <<"이메일을 입력하세요 => ";
	cin >> pTemp->email;

	cout << "\n";
}

void exampleEightSix()
{
    cout << "예제 8-6 (구조체 변수와 포인터의 관계 알아보기) 실행 결과\n\n";
    
	namecard x = {"전수빈", "치과의사", "356-0868", "eldy@naver.com"};
	namecard y = {"전원지", "디자이너", "345-0876", "onejee@naver.com"};
	namecard *p;
	p = &x;

	cout << "  이름 \t 직업 \t\t 연락처 \t 이메일";
	cout << "\n ========================================";
	cout << "\n " << (*p).name << "\t" << (*p).job << "\t"
		        << (*p).tel << "\t" << (*p).email;

	p = &y;
	cout << "\n " << p->name << "\t" << p->job << "\t" << p->tel << "\t" << p->email;
	cout << "\n ========================================";

	cout << "\n sizeof(x) => " << sizeof(x);
	cout << "\n sizeof(p) => " << sizeof(p) << "\n";

	cout << "\n";
}

void exampleEightSeven()
{
    cout << "예제 8-7 (구조체 포인터를 매개변수로 사용하는 함수 작성하기) 실행 결과\n\n";

	namecard x, y, z;

	structPointerInput(&x);
	structPointerInput(&y);
	structPointerInput(&z);

	cout << "  이름 \t 직업 \t\t 연락처 \t 이메일 ";
	cout << "\n=============================================";
	structPrn(x);
	structPrn(y);
	structPrn(z);
	cout << "\n=============================================";

	cout <<"\n";
}

void structReferenceInput(namecard &temp)
{
    cout << "이름을 입력하세요 => ";
	cin >> temp.name;
	cout << "직업을 입력하세요 => ";
	cin >> temp.job;
	cout << "연락처를 입력하세요 => ";
	cin >> temp.tel;
	cout <<"이메일을 입력하세요 => ";
	cin >> temp.email;

	cout << "\n";
}

void exampleEightEight()
{
    cout << "예제 8-8 (구조체 참조 매개변수로 사용하는 함수 작성하기) 실행 결과\n\n";

	namecard x, y, z;

	structReferenceInput(x);
	structReferenceInput(y);
	structReferenceInput(z);

	cout << "  이름 \t 직업 \t\t 연락처 \t 이메일 ";
	cout << "\n=============================================";
	structPrn(x);
	structPrn(y);
	structPrn(z);
	cout << "\n=============================================";

	cout <<"\n";
}

void exampleEightNine()
{
    cout << "예제 8-9 (구조체 배열 사용하기) 실행 결과\n\n";

	namecard x[3] = {
		{ "김주현", "MSCE전문강사", "418-9876", "freentour@naver.com" },
		{ "박혜경", "웹마스터", "551-6986", "hk@naver.com" },
		{ "김동식", "기획A팀대리", "318-3961", "ds@naver.com" }
	};

	cout << " 이름 \t 직업 \t\t 연락처 \t 이메일 \n";
	cout << "=============================================\n";
	for (int i = 0; i < 3; i++)
	{
	cout << x[i].name << "\t" << x[i].job << "\t"
		<< x[i].tel << "\t" << x[i].email << "\n";
	}
	cout << "=============================================\n";

	cout << "\n";
}

void exampleEightTen()
{
    cout << "예제 8-10 (공용체 분석하기) 실행 결과\n\n";

	u_data test;

	cout << " sizeof(u_data)\t : " << sizeof(u_data) << " byte\n";
	cout << " &t            \t : " << (int)&test << "\n";
	cout << " &test.ch     \t : " << (int)&test.ch << "\n";
	cout << " &test.num   \t : " << (int)&test.num << "\n";

	cout << "\n";
}

void exampleEightEleven()
{
    cout << "예제 8-11 (공용체에 값을 저장한 후 저장된 값을 출력하기) 실행 결과\n\n";

	u_data test;
	test.num = 0x12345678;

	cout << " test.ch = " << hex << (int)test.ch << "\n";
	cout << " test.num = " << hex << test.num << "\n";

	cout << "\n";
}

void exampleEightTwelve()
{
    cout << "예제 8-12 (열거형 사용하기) 실행 결과\n\n";

	enum COLOR test;

	test = BLUE;
	cout << " test   = " << test << "\n\n";

	cout << " RED    = " << RED << "\n";
	cout << " GREEN  = " << GREEN << "\n";
	cout << " BLUE   = " << BLUE << "\n";
	cout << " WHITE  = " << WHITE << "\n";
	cout << " BLACK  = " << BLACK << "\n";

	cout << "\n";
}

void exampleEightThirteen()
{
    cout << "예제 8-13 (열거 상수에 수치 정하기) 실행 결과\n\n";

	enum COLOR_TWO test;

	cout << " RED    = " << RED_TWO << "\n";
	cout << " GREEN  = " << GREEN_TWO << "\n";
	cout << " BLUE   = " << BLUE_TWO << "\n";
	cout << " WHITE  = " << WHITE_TWO << "\n";
	cout << " BLACK  = " << BLACK_TWO << "\n";

	test = BLUE_TWO;

	cout << " test   = " << test << "\n\n";

	switch (test) 
	{
	case RED_TWO:
		cout << " 빨간색 선택\n";
		break;
	case GREEN_TWO:
		cout << " 초록색 선택\n";
		break;	
	case BLUE_TWO:
		cout << " 파란색 선택\n";
		break;
	case WHITE_TWO:
		cout << " 하얀색 선택\n";
		break;	
	case BLACK_TWO:
		cout << " 검정색 선택\n";
		break;
	}

	cout << "\n";
}

void exampleEightFourteen()
{
    cout << "예제 8-14 (구조체에 새로운 자료형 이름 지어주기) 실행 결과\n\n";

    SJ s={"2001029", "이진규", 85, 90, 95};
	s.tot = s.kor + s.eng + s.mat;
	s.ave = s.tot / 3;

	cout << " 학번 \t이름 \t국어 \t영어 \t수학 \t총점 \t평균\n";
	cout << "---------------------------------------------------------\n";
    cout << s.no<< "\t" << s.name << "\t" << s.kor << "\t" 
		<< s.eng << "\t" << s.mat << "\t" << s.tot << "\t" << s.ave << "\n";

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
    exampleEightSix();
	useSystem(2, "pause", "cls"); 

	exampleEightSeven();
	useSystem(2, "pause", "cls"); 

	exampleEightEight();
	useSystem(2, "pause", "cls"); 

	exampleEightNine();
	useSystem(2, "pause", "cls"); 

	exampleEightTen();
	useSystem(2, "pause", "cls"); 

	exampleEightEleven();
	useSystem(2, "pause", "cls"); 

	cout << dec;

	exampleEightTwelve();
	useSystem(2, "pause", "cls"); 

	exampleEightThirteen();
	useSystem(2, "pause", "cls"); 
   
	exampleEightFourteen();
	useSystem(2, "pause", "cls"); 

    printStudentInfo();
    useSystem(1, "pause");
    
    return 0;
}
