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

    cout << "s1 (" << s1.length() << ")" << endl;
    cout << "s2 (" << s2.length() << ")" << endl;
    cout << "s3 (" << s3.length() << ")" << endl;
    cout << "s4 (" << s4.length() << ")" << endl;

    return 0;
}
