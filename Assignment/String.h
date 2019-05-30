#ifndef String_h
#define String_h
#include "BankingCommonDecl.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * [String 클래스]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Member Variables
 * *str : 문자열
 * len : 문자열 길이
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Member Methods
 * String() : 생성자
 * String(const char *s) : 문자열 매개변수가 있는 생성자
 * String(const String &s) : String 레퍼런스 매개변수가 있는 생성자
 * ~String() : 소멸자
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Overriding
 * =, +, +=, == 연산자 재정의
 * coute의 <<, >>는 객체에 접근가능하도록 friend로 선언
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
class String
{
    char *str;
    int len;
    
public:
    String();
    String(const char *s);
    String(const String &s);
    String& operator= (const String &s);
    String operator+ (const String &s);
    String& operator+= (const String &s);
    bool operator== (const String &s);
    ~String();
    
    friend ostream& operator<< (ostream& os, const String &s);
    friend istream& operator>> (istream& is, String &s);
};

#endif
