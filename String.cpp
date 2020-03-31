/*
 * File     : String.cpp
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 12.03.2020
 */

#include "String.h"
#include <cstring>
#include <iostream>

using namespace std;

String::String() {
    init(0);
}

String::String(const char *str){
    init(strlen(str));
    strcpy(values, str);
}

String::String(const String& str) {
    init(str._length);
    strcpy(values, str.values);
}

String::String(char c) {
    init(1);
    values[0] = c;
}

String::String(int i) {
    init(countDigit(i));
    sprintf(values, "%d", i);
}

String::String(double d) {
    init(countDigit((int)d) + DECIMAL_PRECISION + 1); // +1 is for the char '.'
    sprintf(values, "%.*f", DECIMAL_PRECISION, d);
}

String::String(bool b) {
    init(b ? 4 : 5);
    strcpy(values, b ? "true" : "false");
}

String::~String() {
    delete[] values;
}

size_t String::length() const {
    return _length;
}

const char* String::c_str() const {
    return values;
}

char& String::at(size_t index) const{
    testRange(index);
    return values[index];
}

const char* String::substr(size_t start, size_t end) const {
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
    
    is.getline(str.values, String::CIN_BUFFER + 1);
    str._length = (size_t)(is.gcount() - 1);

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

bool String::operator==(const String& rhs){
    return this->equals(rhs);
}

bool String::operator==(const char* rhs){
    return this->equals(rhs);
}

bool operator==(const char* lhs, const String& rhs){
    return rhs.equals(lhs);
}

bool String::operator!=(const String& rhs){
    return !this->equals(rhs);
}

bool String::operator!=(const char* rhs){
    return !this->equals(rhs);
}

bool operator!=(const char* lhs, const String& rhs){
    return !rhs.equals(lhs);
}

String& String::append(const String& str) {
    return append(str.c_str());
}

String& String::append(const char* str) {
    char* tmp = values;
    init(this->length() + strlen(str));

    // Put all values into values and concat the new str
    strcpy(values, tmp);
    strcat(values, str);

    return *this;
}

String& String::operator=(const String& str) {
    // Both object must be different to do the copy
    if(this != &str) {
        delete[] values;
        init(str._length);
        strcpy(values, str.values);
    }
    return *this;
}

String& String::operator=(const char* str) {
    *this = String(str);
    return *this;
}

String::operator const char *() const {
    return c_str();
}

char &String::operator[](size_t index) {
    return at(index);
}


/*********** PRIVATE METHODS **************/

size_t String::countDigit(int i) const{
    size_t count = i <= 0 ? 1 : 0;

    while(i) {
        ++count;
        i /= 10;
    }

    return count;
}

bool String::equals(const String &str) const {
    return equals(str.c_str());
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

void String::init(size_t length) {
    _length = length;
    values = new char[_length + 1];
    values[_length] = END_CHAR;
}

void String::testRange(size_t index) const {
    if(index >= _length){
        throw out_of_range("index out of range");
    }

}
