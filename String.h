/*
 * File     : cstring.h
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 12.03.2020
 */

#ifndef POO1_LABO02_STRING_H
#define POO1_LABO02_STRING_H


#include <cstdlib>

class String {

private:

    char* values;
    size_t _length;


public:

    explicit String();

    explicit String(const char* str);

    explicit String(const String& str);

    explicit String(char c);

    explicit String(int i);

    explicit String(double d);

    explicit String(bool b);

    ~String();



    size_t length();

    const char* getString() const;

    char& at(size_t index) const;

    bool equals(const char* str) const;

    bool equals(const String& str) const;

    String& operator=(const String& str);





};


#endif //POO1_LABO02_STRING_H
