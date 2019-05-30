#include "String.h"

// String 클래스 생성자 (매개변수 없음)
String::String() : str(NULL), len(0)
{
    
}

// String 클래스 생성자 (매개변수 있음 pointer)
String::String(const char *s)
{
    len = strlen(s) + 1;
    str = new char[len];
    strcpy(str, s);
}

// String 클래스 생성자 (매개변수 있음 reference)
String::String(const String &s)
{
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
}

// =연산자 재정의 return by reference
String& String::operator=(const String &s)
{
    if (str != NULL)
        delete []str;
    
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
    
    return *this;
}

// +연산자 재정의
String String::operator+(const String &s)
{
    char *tempstr = new char[len + s.len - 1];
    strcpy(tempstr, str);
    strcat(tempstr, s.str);
    String temp(tempstr);
    delete []tempstr;
    
    return temp;
}

// +=연산자 재정의 return by reference
String& String::operator+=(const String &s)
{
    *this = (*this + s);
    return *this;
}

// ==연산자 재정의
bool String::operator==(const String &s)
{
    return strcmp(str, s.str) == 0 ? true : false;
}

// 소멸자 정의
String::~String()
{
    if (str != NULL)
        delete []str;
}
// cout의 << 재정의
ostream& operator<< (ostream& os, const String &s)
{
    os << s.str;
    return os;
}

// cin의 >> 재정의
istream& operator>> (istream& is, String &s)
{
    char temp[50];
    is >> temp;
    s = String(temp);
    return is;
}
