#ifndef String_h
#define String_h
#include <iostream>
#include "BankingCommonDecl.h"

int accountStrToInt(string account);

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
