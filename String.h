/*
 * File     : String.h
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
    static const size_t CIN_BUFFER = 4096; // Maximum of 4096 char can be stored

public:

    /**
     * Empty constructor
     * Constructs an empty string, with a length of zero characters.
     */
    explicit String();

    /**
     * Copy constructor
     * Constructs a copy of str.
     * @param str The String we want to copy
     */
    String(const String& str);

    /**
     * From c-string
     * Constructs from c-string
     * @param str The const char* we want to copy
     */
    explicit String(const char* str);

    /**
     * From char
     * Consructs from character
     * @param c The character
     */
    explicit String(char c);

    /**
     * From int
     * Consructs from integer
     * @param i The integer
     */
    explicit String(int i);

    /**
     * From double
     * Constructs from double, careful that it will have a precision of DECIMAL_PRECISION (6)
     * @param d The double
     */
    explicit String(double d);

    /**
     * From bool
     * Consructs from bool
     * @param b The bool
     */
    explicit String(bool b);

    /**
     * Destructor
     */
    virtual ~String();

    /**
     * The number of characters in our String
     * @return The length of our String
     */
    size_t length() const;

    /**
     * Get a char* representation of String
     * @return A c-string representation of our String
     */
    const char* c_str() const;

    /**
     * Cast a String object into a c-string value like that : (const char *) myString
     * @return A const char* cast of our String object
     */
    explicit operator const char*() const;

    /**
     * Get a reference to the char at position index
     * @param index The position of our String we want to access
     * @return A reference on the char at position [index]
     * @throw out_of_range if the index is out of range
     */
    char& at(size_t index) const;

    /**
     * Get a reference to the char at position index (use the at method)
     * @param index The position of our String we want to access
     * @return A reference on the char at position [index]
     * @throw out_of_range if the index is out of range
     */
    char& operator[](size_t index);

    /**
     * Extract a new substring (c-string) of range [start, end[
     * @param start The start index (include)
     * @param end The end index (exclude)
     * @return A c-string substring
     * @throw out_of_range if start or end is out of range
     */
    const char* substr(size_t start, size_t end) const;

    /**
     * String assignment
     * Assigns a new value to the String, replacing its current contents.
     * @param str A String object
     * @return A String reference on the current String modified (*this)
     */
    String& operator=(const String& str);

    /**
     * String assignment
     * Assigns a new value to the String, replacing its current contents.
     * @param str a c-string value
     * @return A String reference on the current String modified (*this)
     */
    String& operator=(const char* str);

    /**
     * Insert String into output stream
     * @param os The output stream
     * @param str The String object
     * @return The same as parameter os
     */
    friend std::ostream& operator<<(std::ostream& os, const String& str);

    /**
     * Extract String from input stream
     * @param is The input stream
     * @param str The String object where the extracted content is stored
     * @return The same as parameter is
     */
    friend std::istream& operator>> (std::istream& is, String& str);

    /**
     * Extends the string by appending additional characters at the end of its current value
     * (use the append method)
     * @param rhs A string object, whose value is copied at the end.
     * @return A String reference on the current String modified (*this)
     */
    String& operator+=(const String& rhs);

    /**
     * Extends the string by appending additional characters at the end of its current value
     * (use the append method)
     * @param rhs A c-string, whose value is copied at the end.
     * @return A String reference on the current String modified (*this)
     */
    String& operator+=(const char* rhs);

    /**
     * Returns a newly constructed string object with its value being the concatenation of the characters
     * in lhs followed by those of rhs. (use the += operator)
     * @param lhs The String object for which we'll concatenate characters
     * @param rhs The String object we want to concatenate to lhs param
     * @return A newly constructed string object with its new value
     */
    friend String operator+(String lhs, const String& rhs);

    /**
     * Returns a newly constructed string object with its value being the concatenation of the characters
     * in lhs followed by those of rhs. (use the += operator)
     * @param lhs The String object for which we'll concatenate characters
     * @param rhs A c-string value we want to concatenate to lhs param
     * @return A newly constructed string object with its new value
     */
    friend String operator+(String lhs, const char* rhs);

    /**
     * Check if a String object is equals to another String object (use the equals method)
     * @param rhs The String object that will be compared
     * @return True if both String are equals, false otherwise
     */
    bool operator==(const String& rhs);

    /**
     * Check if a String object is equals to a c-string value (use the equals method)
     * @param rhs The c-string value that will be compared
     * @return True if they are equals, false otherwise
     */
    bool operator==(const char* rhs);

    /**
     * Check if a c-string value is equals to a String object (use the equals method)
     * @param lhs The c-string value
     * @param rhs The String object that will be compared
     * @return True if they are equals, false otherwise
     */
    friend bool operator==(const char* lhs, const String& rhs);

    /**
     * Check if a String object is NOT equals to another String object (use the equals method)
     * @param rhs The String object that will be compared
     * @return True if both String are NOT equals, false otherwise
     */
    bool operator!=(const String& rhs);

    /**
     * Check if a String object is NOT equals to a c-string value (use the equals method)
     * @param rhs The c-string value that will be compared
     * @return True if they are NOT equals, false otherwise
     */
    bool operator!=(const char* rhs);

    /**
     * Check if a String object is NOT equals to a c-string value (use the equals method)
     * @param rhs The c-string value that will be compared
     * @return True if they are NOT equals, false otherwise
     */
    friend bool operator!=(const char* lhs, const String& rhs);

    /**
     * Extends the current String object by appending additional characters at the end of its current value
     * @param str A string object, whose value is copied at the end.
     * @return A String reference on the current String modified (*this)
     */
    String& append(const String& str);

    /**
     * Extends the string by appending additional characters at the end of its current value
     * @param str A c-string, whose value is copied at the end.
     * @return A String reference on the current String modified (*this)
     */
    String& append(const char* str);

private:

    /**
     * Dynamically allocate a new memory space for a char array.
     * The char array will be as long as the length parameter (+ 1 for the '\0' that will be automatically added)
     * @param length The length of the char array (\0 exclude)
     */
    void init(size_t length);

    /**
     * Counts number of digits of an int (including "-" sign if < 0).
     * @param i The integer
     * @return The number of digit of the integer param
     */
    size_t countDigit(int i) const;

    /**
    * Check if a String object is equals to a c-string value
    * @param str The c-string value that will be compared
    * @return True if they are equals, false otherwise
    */
    bool equals(const char* str) const;

    /**
     * Check if a String object is equals to another String object (use the equals method)
     * @param str The String object that will be compared
     * @return True if both String are equals, false otherwise
     */
    bool equals(const String& str) const;

    /**
     * Test if our index is inside the this.values range
     * @param index The index we want to check
     * @throw out_of_range if our index is out of range
     */
    void testRange(size_t index) const;

};


#endif //POO1_LABO02_STRING_H
