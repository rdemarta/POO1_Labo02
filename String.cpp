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
    values[0] = END_CHAR;
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
}

String::String(double d) {
    _length = countDigit((int)d) + DECIMAL_PRECISION + 1; // +1 is for the char '.'
    values = new char[_length + 1];

    sprintf(values, "%.*f", DECIMAL_PRECISION, d);
}

String::String(bool b) {
    _length = b ? 4 : 5;
    values = new char[_length + 1];
    strcpy(values, b ? "true" : "false");
}

String::~String() {
    delete values;
}


size_t String::length() const {
    return _length;
}

const char* String::getCharArray() const {
    return values;
}

char& String::at(size_t index) const{
    return values[index];
}

const char* String::subString(size_t start, size_t end) const {
    if(start > end || start >= _length || end >= _length)
        throw out_of_range("start/end bounds are out of range or incoherent.");

    size_t subLength = end - start + 1;

    char* subStr = new char[subLength + 1];
    strncpy(subStr, values + start, subLength);
    subStr[subLength] = END_CHAR; // Must terminate String manually because values' END_CHAR may not be copied (range copy)

    return subStr;
}

ostream& operator<<(ostream& os, const String& str){
    return os << str.values;
}

istream& operator>>(std::istream& is, String& str) {
    cout << "_____gcount" << is.gcount() << endl;

    // TODO update _length

    is >> str.values;
    str._length += (size_t)(is.gcount());
    return is;
}

String& String::operator+=(const String& rhs) {
    return append(rhs);
}

String& String::operator+=(const char* rhs){
    return append(rhs);
}

String operator+(String lhs, const String& rhs) {
    lhs += rhs;
    return lhs;
}

String operator+(String lhs, const char* rhs) {
    lhs += rhs;
    return lhs;
}

String& String::append(const String& str) {
    return append(str.getCharArray());
}

String& String::append(const char* str) {
    _length = this->length() + strlen(str); // Update the length with both String
    char* tmp = values;
    values = new char[_length + 1]; // Allocate the new values

    // Put all values into values and concat the new str
    strcpy(values, tmp);
    strcat(values, str);

    return *this;
}

bool String::equals(const String &str) const {
    return equals(str.getCharArray());
}

bool String::equals(const char *str) const {
    bool isEqual = true;

    if(_length != strlen(str)) {
        isEqual = false;
    }else {
        for(size_t i = 0; i < _length; ++i){
            if(values[i] != str[i]){
                isEqual = false;
                break;
            }
        }
    }

    return isEqual;
}

String& String::operator=(const String& str) {
    // Both object must be different to do the copy
    if(this != &str) {
        String newString(str);
        swap(_length, newString._length);
        swap(values, newString.values);
    }

    return *this;
}

size_t String::countDigit(int i) {
    size_t count = i <= 0 ? 1 : 0;

    while(i) {
        ++count;
        i /= 10;
    }

    return count;
}
