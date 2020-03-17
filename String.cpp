/*
 * File     : cstring.cpp
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 12.03.2020
 */

#include "String.h"
#include <cstring>
#include <iostream>

using namespace std;

String::String() {
    values = new char[1];
    values[0] = '\0';
}

String::String(const char *str){
    _length = strlen(str);
    values = new char[_length + 1];
    strcpy(values, str);
}

String::String(const String& str) {
    _length = str._length;
    values = new char[_length + 1];
    memcpy(values, str.values, _length + 1);
}

String::String(char c) {
    values = new char[2];
    values[0] = c;
    values[1] = END_CHAR;
    _length = 1;
}

String::String(int i) {
    _length = countDigit(i);
    values = new char[_length];

    sprintf(values, "%d", i);

    /*
    // Using st::string
    string str = to_string(i);
    _length = to_string(i).length();

    values = new char[_length + 1];
    std::copy(str.begin(), str.end(), values);

    values[_length] = END_CHAR;
     */
}


String::~String() {
    delete values;
}



size_t String::length() const {
    return _length;
}

const char* String::getString() const {
    return values;
}

char& String::at(size_t index) const{
    return values[index];
}

ostream& operator<<(ostream& os, const String& str){
    return os << str.values;
}

size_t String::countDigit(int i) {
    size_t count = i <= 0 ? 1 : 0;

    while(i) {
        ++count;
        i /= 10;
    }

    return count;
}
