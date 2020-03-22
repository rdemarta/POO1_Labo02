/*
 * File     : main.cpp
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 12.03.2020
 */

#include <iostream>
#include "String.h"

using namespace std;

int main() {

    const char* test = "Blabla";
    const char c = 'c';
    String s1;
    String s2(test);
    String s3(s2);
    String s4(c);
    String s5(-42);
    String s6(true);
    const char* s2AsConstChar = s2.getString();
    const char* subStr = s6.subString(1, 2); // "ru"

    cout << "Constructors" << endl;
    cout << "s1 : " << s1 << " (" << s1.length() << ")" << endl;
    cout << "s2 : " << s2 << " (" << s2.length() << ")" << endl;
    cout << "s3 : " << s3 << " (" << s3.length() << ")" << endl;
    cout << "s4 : " << s4 << " (" << s4.length() << ")" << endl;
    cout << "s5 : " << s5 << " (" << s5.length() << ")" << endl;
    cout << "s6 : " << s6 << " (" << s6.length() << ")" << endl;

    cout << endl << "Display as const char*" << endl;
    cout << "s2 as const char* : " << s2AsConstChar << " (" << s2.length() << ")" << endl;
    cout << "s6 substring [1;2] : " << subStr << endl;

    cout << endl << "Modify String with at()" << endl;
    char& s2Char = s2.at(0);
    cout << s2 << endl;
    s2Char = 'C';
    cout << s2 << endl;

    cout << endl << "Test concat / + / += " << endl;
    cout << "s3 (" << s3 << ") append s6 (" << s6 << ") : " << s3.append(s6) << "(" << s3.length() << ")" << endl;
    cout << "s3 (" << s3 << ") += s4 (" << s4 << ") : " << (s3 += s4) << "(" << s3.length() << ")" << endl;
    cout << "s3 (" << s3 << ") + s6 (" << s6 << ") : " << s3 + s6 << "(" << (s3 + s6).length() << ")" << endl;

    delete subStr;

    return 0;
}
