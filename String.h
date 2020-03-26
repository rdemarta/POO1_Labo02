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
    static const unsigned DECIMAL_PRECISION = 6;

public:

    explicit String();

    explicit String(const char* str);

    String(const String& str);

    explicit String(char c);

    explicit String(int i);

    explicit String(double d);

    explicit String(bool b);

    virtual ~String();

    /**
     * The number of characters in values
     * @return
     */
    size_t length() const;

    /**
     * Get a char* representation of String
     * @return
     */
    const char* getCharArray() const;

    /**
     * Get a reference to the char at position index
     * @param index
     * @return
     */
    char& at(size_t index) const;

    /**
     * Extract a new substring of range [start, end[
     * @param start
     * @param end
     * @return
     */
    const char* subString(size_t start, size_t end) const;

    String& operator=(const String& str);
    String& operator=(const char* str); // TODO

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>> (std::istream& is, String& str);

    String& operator+=(const String& rhs);
    String& operator+=(const char* rhs);
    friend String operator+(String lhs, const String& rhs);
    friend String operator+(String lhs, const char* rhs);
    bool operator==(const String& rhs);
    bool operator==(const char* rhs);
    friend bool operator==(const char* lhs, const String& rhs);
    bool operator!=(const String& rhs);
    bool operator!=(const char* rhs);
    friend bool operator!=(const char* lhs, const String& rhs);

    String& append(const String& str);
    String& append(const char* str);

private:

    /**
     * Counts number of digits of an int (including "-" sign if < 0).
     * @param i
     * @return
     */
    static size_t countDigit(int i);

    bool equals(const char* str) const;

    /**
     * Two String objects are considered equals if their values are equals (_length doesn't matter)
     * @param str
     * @return
     */
    bool equals(const String& str) const;

};


#endif //POO1_LABO02_STRING_H
