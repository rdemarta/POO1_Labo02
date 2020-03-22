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

    String(const String& str); // TODO ? Had to remove 'explicit' keyword because of operator+()

    explicit String(char c);

    explicit String(int i);

    explicit String(double d);

    explicit String(bool b);

    virtual ~String();



    size_t length() const;

    const char* getString() const;

    char& at(size_t index) const;

    /**
     * Extract a new substring of range [start, end[
     * @param start
     * @param end
     * @return
     */
    const char* subString(size_t start, size_t end) const;

    bool equals(const char* str) const;

    bool equals(const String& str) const;

    String& operator=(const String& str);

    friend std::ostream& operator<<(std::ostream& os, const String& str);

    String& operator+=(const String& rhs);
    String& operator+=(const char* rhs);
    friend String operator+(String lhs, const String& rhs);
    friend String operator+(String lhs, const char* rhs);

    String& append(const String& str);
    String& append(const char* str);

private:

    /**
     * Counts number of digits of an int (including "-" sign if < 0).
     * @param i
     * @return
     */
    static size_t countDigit(int i);

};


#endif //POO1_LABO02_STRING_H
