/*
 * File     : cstring.h
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 12.03.2020
 */

#ifndef POO1_LABO02_STRING_H
#define POO1_LABO02_STRING_H


#include <cstdlib>
#include <iostream>

class String {

private:

    char* values;
    size_t _length = 0;

    static const char END_CHAR = '\0';

    constexpr static const char* const TRUE = "true";
    static const size_t TRUE_LENGTH = 4;
    constexpr static const char* const FALSE = "false";
    static const size_t FALSE_LENGTH = 4;

public:

    explicit String();

    explicit String(const char* str);

    explicit String(const String& str);

    explicit String(char c);

    explicit String(int i);

    explicit String(double d);

    explicit String(bool b);

    virtual ~String();



    size_t length() const;

    const char* getString() const;

    char& at(size_t index) const;

    bool equals(const char* str) const;

    bool equals(const String& str) const;

    String& operator=(const String& str);

    friend std::ostream& operator<<(std::ostream& os, const String& str);

    /**
     * Counts number of digits of an int (including "-" sign if < 0).
     * @param i
     * @return
     */
    static size_t countDigit(int i);
private:



};


#endif //POO1_LABO02_STRING_H
