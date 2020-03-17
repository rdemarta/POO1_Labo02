/*
 * File     : cstring.cpp
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 12.03.2020
 */

#include "String.h"
#include <cstring>

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
    values[1] = '\0';
    _length = 1;
}

String::~String() {
    delete values;
}



size_t String::length() const {
    return _length;
}