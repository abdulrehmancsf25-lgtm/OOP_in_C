// ROLL NO : BCSF25M_521
// ABDUL REHMAN ARSHAD

// i have changed size function with name csize because size is also an attribute name
// of class CharString also size() is an inbuilt function
#pragma once

int mystrlen(const char *str); // helper function
class CharString
{

    char *cstr;
    int size;

public:
    CharString(); // default ctor

    CharString(const char *temp); // parametrized Ctor

    CharString(const CharString &src);

    int csize() const;

    void clear();

    void print() const;

    void copyFrom(const char *src);

    void copyFrom(const CharString &src);

    // concat
    void concat(const char *str);

    void concat(const CharString &str);

    bool isEqualTo(const char *str) const;

    bool isEqualTo(const CharString &str) const;

    bool checkPalindrome() const;

    CharString reverseStr() const;

    CharString SubString(int start, int n);

    int countOccurrenceOf(const char *substr) const;
};
