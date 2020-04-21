#include <iostream>
#include "stdlib.h" 

int getInput();
void gugudan(int num);
void printStudentInfo();

int main()
{
    int num = getInput();

	gugudan(num);
	printStudentInfo();

	system("PAUSE");

    return 0;
}

int getInput()
{
    float userInput;

     do
	{
	    std::cout << "2에서 9 사이의 값을 입력하세요 :";
	    std::cin >> userInput;

		userInput = (int)userInput;

	} while (userInput <= 1 || userInput >= 10);

	return userInput;
}

void gugudan(int num)
{
    for (int i=1; i<=9; i++)
	{
	    std::cout << num << " * " << i << " = " << num * i << std::endl; 
	}
}

void printStudentInfo()
{
     std::cout << "\n201744444 - 김민수" << std::endl;
}
