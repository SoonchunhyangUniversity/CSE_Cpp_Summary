//
//  순천향대학교
//  컴퓨터소프트웨어공학과
//  20174444 김민수
//  C++ 실습 6월 30일 레포트
//
//  Created by 김민수 on 2020/06/30.
//  Copyright © 2020 SCH. All rights reserved.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <stdarg.h>

using namespace std;

struct insa {
    char name[20];
	int age;
	char address[20];
};

void exampleThirteenOne()
{
    cout << "예제 13-1 (구조체 변숫값을 모니터에 출력하기) 실행 결과\n\n";

	insa man = { "성윤정", 20, "서울" };

	cout << man.name << " " << man.age << " " << man.address << endl;
    
	cout << "\n";
}

void exampleThirteenTwo()
{
    cout << "예제 13-2 (구조체 변수를 << 연산자를 사용해서 파일에 출력하기) 실행 결과\n\n";

	insa man = { "성윤정", 20, "서울" };

	ofstream fout;

	fout.open("insa.dat");

	fout << man.name << " " << man.age << " " << man.address << endl;

	fout.close();

	cout << "\n";
}

void exampleThirteenThree()
{
    cout << "예제 13-3 (구조체 단위로 >> 연산자를 이용해서 파일로 입력받기) 실행 결과\n\n";

	insa man;

	ifstream fin;

	fin.open("insa2.dat");

	if (fin.fail()) {
		cout << "파일 오픈에 실패했습니다." << endl;
		return;
	}

	fin >> man.name >> man.age >> man.address;

	cout << man.name << " " << man.age << " " << man.address << endl;

	fin.close();

	cout << "\n";
}

void exampleThirteenFour()
{
    cout << "예제 13-4 (키보드로 입력받은 문자를 모니터에 출력하기) 실행 결과\n\n";

	cout << "종료하려면 ESC 키를 누르세요\n" << endl;

	char ch;

	while (true) {
		ch = getch();

		if (ch == 27) {
			break;
		}

		cout.put(ch);
	}

	cout << "\n\n";
}

void exampleThirteenFive()
{
    cout << "예제 13-5 (키보드로 입력받은 문자를 파일에 출력하기) 실행 결과\n\n";

	cout << "종료하려면 ESC 키를 누르세요\n" << endl;

	char ch;

	ofstream fout;

	fout.open("test.dat");

	while (true) {
		ch = getch();

		if (ch == 27) {
			break;
		}

		fout.put(ch);
		cout.put(ch);
	}

	fout.close();

	cout << "\n\n";
}

void exampleThirteenSix()
{
    cout << "예제 13-6 (문자 단위로 파일에서 입력받기) 실행 결과\n\n";

	char ch;

	ifstream fin;

	fin.open("test2.dat");

	if (fin.fail()) {
		cout << "파일 오픈에 실패했습니다." << endl;
		return;
	}

	while (!fin.eof()) {
		ch = fin.get();
		cout.put(ch);
	}

	fin.close();

	cout << "\n\n";
}

void exampleThirteenSeven(int argc, char *argv[])
{
    cout << "예제 13-7 (명령행에서 문자열 읽어오기) 실행 결과\n\n";

	cout << "\n 문자열의 수 => " << argc << "\n";

	for (int i = 0; i < argc; i++) {
		cout << " argv[" << i << "]=" << argv[i] << "\n";
	}
    
	cout << "\n";
}

void exampleThirteenEight(int argc, char *argv[])
{
    cout << "예제 13-8 (도스의 type 명령어 만들기) 실행 결과\n\n";
	
	char ch;
	
	if (argc != 2) {
		cout << "명령어 입력한 후 파일명을 반드시 입력하세요" << endl;
		return;
	}

	ifstream fin;
	fin.open(argv[0]);

	if (!fin) {
		cout << "파일 오픈을 실패했습니다." << endl;
		return;
	}

	while (!fin.eof()) {
		ch = fin.get();
		cout.put(ch);
	}

	fin.close();

	cout << "\n\n";
}

void exampleThirteenNine()
{
    cout << "예제 13-9 (파일에서 입력받은 내용을 파일에 출력하기) 실행 결과\n\n";

	ifstream fin;
	ofstream fout;

	char ch;

	fin.open("13_09.cpp");
	fout.open("dest.cpp");

	if (fin.fail() || fout.fail()) {
		cout << "파일 오픈을 실패했습니다." << endl;
		return;
	}

	while (!fin.eof()) {
		ch = fin.get();
		fout.put(ch);
	}

	fin.close();
	fout.close();

	cout << "\n";
}

void exampleThirteenTen(int argc, char *argv[])
{
    cout << "예제 13-10 (도스의 copy 명령어 만들기) 실행 결과\n\n";

	ifstream fin;
	ofstream fout;

	char ch;

	if (argc != 3) {
		cout << "명령어 입력한 후 원본 파일명과 복사본 파일명을 입력하세요" << endl;
		return;
	}

	fin.open(argv[0]);
	fout.open(argv[1]);

	if (fin.fail() || fout.fail()) {
		cout << "파일 오픈을 실패했습니다." << endl;
		return;
	}

	while (!fin.eof()) {
		ch = fin.get();
		fout.put(ch);
	}

	fin.close();
	fout.close();

	cout << "\n";
}

void exampleThirteenEleven()
{
    cout << "예제 13-11 (5명의 인사 정보를 텍스트 파일에 출력하기) 실행 결과\n\n";

	insa man[5] = {
		{ "성윤정", 20, "서울" },
		{ "전혜영", 30, "부산" },
		{ "이은정", 24, "대구" },
		{ "오경주", 34, "서울" },
		{ "채제원", 25, "마산" }
	};

	ofstream fout;
	fout.open("insa3.dat");

	for (int i = 0; i < 5; i++) {
		fout << man[i].name << " " << man[i].age << " " << man[i].address << endl;
	}

	fout.close();
    
	cout << "\n";
}

void exampleThirteenTwelve()
{
    cout << "예제 13-12 (5명의 인사 정보를 이진 파일에 출력하기) 실행 결과\n\n";

	insa man[5] = {
		{ "성윤정", 20, "서울" },
		{ "전혜영", 30, "부산" },
		{ "이은정", 24, "대구" },
		{ "오경주", 34, "서울" },
		{ "채제원", 25, "마산" }
	};

	ofstream fout;
	fout.open("insa.bin");

	fout.write((char *)man, sizeof(insa) * 5);

	fout.close();

	cout << "\n";
}

void exampleThirteenThirteen()
{
    cout << "예제 13-13 (이진 파일에서 인사 정보를 읽어오기) 실행 결과\n\n";

	insa man;
	ifstream fin;

	fin.open("insa.bin");

	if (fin.fail()) {
		cout << "Error: file open error" << endl;
		return;
	}

	cout << "  >> 파일에서 읽어온 데이터 << \n";
	cout << "-------------------------------------\n";
	cout << " 이름 나이 주소 \n";
	cout << "-------------------------------------\n";

	while (fin.read((char *) &man, sizeof(man))) {
		cout << man.name << " " << man.age << " " << man.address << endl;
	}

	fin.close();

	cout << "\n";
}

void exampleThirteenFourteen()
{
    cout << "예제 13-14 (순차 파일로 원하는 위치의 레코드 읽어오기) 실행 결과\n\n";

	insa man;
	ifstream fin;

	int pos;

	bool bFind = true;

	fin.open("insa.bin");

	if (fin.fail()) {
		cout << "Error: file open error" << endl;
		return;
	}

	cout << "# 파일에서 몇번째 위치의 데이터를 읽고 싶은가요? => ";
	cin >> pos;

	for (int i = 0; i < pos; i++) {
		fin.read((char *) &man, sizeof(man));

		if (!fin.good()) {
			bFind = false;
			break;
		}
	}

	if (bFind) {
		cout << man.name << " " << man.age << " " << man.address << endl;
	} else {
		cout << "찾고자 하는 데이터가 없다." << endl;
	}

	fin.close();

	cout << "\n";
}

void exampleThirteenFifteen()
{
    cout << "예제 13-15 (랜덤 파일로 원하는 위치의 레코드 읽어오기) 실행 결과\n\n";

	insa man;
	ifstream fin;

	int pos;
	int total_rec;

	fin.open("insa.bin");

	if (fin.fail()) {
		cout << "Error: file open error" << endl;
		return;
	}

	fin.seekg(0, ios::end);

	total_rec = fin.tellg() / sizeof(insa);

	cout << "현재 레코드의 총 개수는 " << total_rec << "입니다.\n";

	cout << "#파일에서 몇번째 위치의 데이터를 읽고 싶은가요(총개수보다 적게)=>";
	cin >> pos;

	if (pos >= total_rec) {
		cout << "레코드 찾기에 실패했습니다." << endl;
		return;
	}

	fin.seekg((pos - 1) * sizeof(insa), ios::beg);

	fin.read((char *) &man, sizeof(man));

	cout << man.name << " " << man.age << " " << man.address << endl;

	fin.close();

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
    exampleThirteenOne();
	useSystem(2, "pause", "cls"); 

	exampleThirteenTwo();
	useSystem(2, "pause", "cls"); 

	exampleThirteenThree();
	useSystem(2, "pause", "cls"); 

    exampleThirteenFour();
	useSystem(2, "pause", "cls"); 

	exampleThirteenFive();
	useSystem(2, "pause", "cls"); 

	exampleThirteenSix();
	useSystem(2, "pause", "cls"); 

	char *arr[] = {"13_07", "one", "two", "three", "four"};
	exampleThirteenSeven(5, arr);
	useSystem(2, "pause", "cls"); 

	char *arr2[] = { "test2.dat" };
	exampleThirteenEight(2, arr2);
	useSystem(2, "pause", "cls"); 

	exampleThirteenNine();
	useSystem(2, "pause", "cls"); 

	char *arr3[] = { "13_09.cpp", "test3.dat" };
	exampleThirteenTen(3, arr3);
	useSystem(2, "pause", "cls"); 

	exampleThirteenEleven();
	useSystem(2, "pause", "cls"); 

	exampleThirteenTwelve();
	useSystem(2, "pause", "cls"); 

	exampleThirteenThirteen();
	useSystem(2, "pause", "cls"); 

	exampleThirteenFourteen();
	useSystem(2, "pause", "cls"); 

	exampleThirteenFifteen();
	useSystem(2, "pause", "cls"); 

    printStudentInfo();
    useSystem(2, "pause");
    
    return 0;
}
