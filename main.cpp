/*
 * File     : main.cpp
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 12.03.2020
 */

#include <iostream>
#include "String.h"

using namespace std;

int main() {

    // Tests our String class

    const char* test = "Blabla";
    const char c = 'c';
    String s1;
    String s2(test);
    String s3(s2);
    String s4(c);
    String s5(-42);
    String s6(true);
    String s7(123.456789);

    const char* s2AsConstChar = s2.c_str(); // Or : (const char*) s2
    const char* subStr = s6.substr(1, 2); // "ru"

    cout << "Constructors" << endl;
    cout << "s1 : " << s1 << " (" << s1.length() << ")" << endl;
    cout << "s2 : " << s2 << " (" << s2.length() << ")" << endl;
    cout << "s3 : " << s3 << " (" << s3.length() << ")" << endl;
    cout << "s4 : " << s4 << " (" << s4.length() << ")" << endl;
    cout << "s5 : " << s5 << " (" << s5.length() << ")" << endl;
    cout << "s6 : " << s6 << " (" << s6.length() << ")" << endl;
    cout << "s7 : " << s7 << " (" << s7.length() << ")" << endl;

    cout << endl << "Display as const char*" << endl;
    cout << "s2 as const char* : " << s2AsConstChar << " (" << s2.length() << ")" << endl;
    cout << "s6 substring [1;2] : " << subStr << endl;

    // At and [] operator
    cout << endl << "Modify String with at() (also possible with [])" << endl;
    char& s2Char = s2.at(0);
    cout << s2 << endl;
    s2Char = 'C';
    cout << s2 << endl;

    // Concat and + tests
    cout << endl << "Test concat, +, +=" << endl;
    cout << "s3 (" << s3 << ") append s6 (" << s6 << ") : " << s3.append(s6) << " (" << s3.length() << ")" << endl;
    cout << "s3 (" << s3 << ") += s4 (" << s4 << ") : " << (s3 += s4) << " (" << s3.length() << ")" << endl;
    cout << "s3 (" << s3 << ") + s6 (" << s6 << ") : " << s3 + s6 << " (" << (s3 + s6).length() << ")" << endl;
    cout << "s3 (" << s3 << ") + \"Hello\" : " << s3 + "Hello" << " (" << (s3 + "Hello").length() << ")" << endl;
    cout << "s3 (" << s3 << ") += \"END\" : " << (s3 += "END") << " (" << s3.length() << ")" << endl;

    // Assignment operator
    cout << endl << "Assignment operator" << endl;
    s3 = s2;
    s1 = "Nouveau";
    cout << "s1 : " << s1 << " (" << s1.length() << ")" << endl;

    // Equality tests
    cout << endl << "Test == and !=" << endl;
    cout << boolalpha << "s6 (" << s6 << ") == \"false\" ? " << (s6 == "false") << endl;
    cout << boolalpha << "s6 (" << s6 << ") != \"false\" ? " << (s6 != "false") << endl;
    cout << boolalpha << "s3 (" << s3 << ") == s2 (" << s2 << ") ? " << (s3 == s2) << endl;
    cout << boolalpha << "s3 (" << s3 << ") != s2 (" << s2 << ") ? " << (s3 != s2) << endl;
    cout << boolalpha << "\"true\" == s6 (" << s6 << ") ? " << ("true" == s6) << endl;
    cout << boolalpha << "\"true\" != s6 (" << s6 << ") ? " << ("true" != s6) << endl;

    // Test the >> operator
    cout << endl << "CIN >> operator" << endl;
    cout << "Veuillez entrer une chaine de caracteres (max 4096 caracteres) : ";
    String s;
    cin >> s;

    cout << "Valeur de s : " << s << " (" << s.length() << ")" << endl;


    // Don't forget to delete our sub string
    delete[] subStr;

    return 0;
}
