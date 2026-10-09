// ROLL NO : BCSF25M_521
// ABDUL REHMAN ARSHAD
#include <iostream>
#include "CharString.h"
using namespace std;
int mystrlen(const char *str)
{ // helper function
    if (!str || str[0] == '\0')
        return 0;

    int i = 0;
    for (; str[i] != '\0'; i++)
        ;
    return i;
}

CharString::CharString() : cstr(NULL), size(0) {} // default ctor

CharString::CharString(const char *temp)
{ // parametrized Ctor
    if (!temp)
    {
        this->cstr = nullptr;
        this->size = 0;
    }
    else
    {
        cstr = new char[mystrlen(temp) + 1];
        int i = 0;
        for (; i < mystrlen(temp); i++)
            this->cstr[i] = temp[i];
        this->cstr[i] = '\0';
        this->size = i;
    }
}

CharString::CharString(const CharString &src) : CharString(src.cstr)
{ // COPY CTOR
}

int CharString::csize() const
{
    if (!cstr)
        return 0;
    int i = 0;
    for (; this->cstr[i] != '\0'; i++)
        ;

    return i;
}

void CharString::clear()
{
    delete[] cstr;
    this->cstr = NULL;
    this->size = 0;
}

void CharString::print() const
{
    if (!cstr)
        return;
    cout << this->cstr << endl;
}

void CharString::copyFrom(const char *src)
{

    delete[] this->cstr;
    if (!src)
    {
        this->size = 0;
        this->cstr = NULL;
        return;
    }

    if (src[0] == '\0')
    {
        size = 0;
        this->cstr = new char[1];
        this->cstr[0] = '\0';
        return;
    }
    else
    {
        size = mystrlen(src);
        cstr = new char[size + 1];
        int i = 0;
        for (; i < size; i++)
            this->cstr[i] = src[i];
        this->cstr[i] = '\0';
    }
}

void CharString::copyFrom(const CharString &src)
{
    if (this != &src)
    { // self assignment check
        size = src.size;
        delete[] this->cstr;

        if (!src.cstr)
        {
            this->size = 0;
            this->cstr = NULL;
            return;
        }

        this->cstr = new char[src.csize() + 1];
        int i = 0;
        for (; i < src.csize(); i++)
            this->cstr[i] = src.cstr[i];
        this->cstr[i] = '\0';
    }
}

// concat
void CharString::concat(const char *str)
{  
    int strSize = mystrlen(str) ;
    char *temp = new char[strSize+ this->csize() + 1];

    int i = 0;
    for (; i < this->csize(); i++)
        temp[i] = cstr[i];

    for (int j = 0; j < strSize ; j++)
        temp[i++] = str[j];

    temp[i] = '\0';

    this->size = i;
    delete[] cstr;
    this->cstr = temp;
    temp = NULL;

} // concat from string

void CharString::concat(const CharString &str)
{
    char *temp = new char[str.csize() + this->csize() + 1];

    int i = 0;

    for (; i < this->csize(); i++)
        temp[i] = cstr[i];
    
        int stemp = mystrlen(str.cstr) ;
    for (int j = 0; j < stemp  ; j++)
        temp[i++] = str.cstr[j];

    temp[i] = '\0';

    this->size = i;
    delete[] cstr;
    this->cstr = temp;
    temp = NULL;

} // concat from Charstr obj

bool CharString::isEqualTo(const char *str) const
{
    if (!str && this->cstr)
        return 0;

    if (mystrlen(str) != this->size)
        return 0;

    for (int i = 0; i < size; i++)
        if (this->cstr[i] != str[i])
            return 0;
    return 1;
} // equal to for char* string

bool CharString::isEqualTo(const CharString &str) const
{

    if (str.csize() != this->size)
        return 0;

    for (int i = 0; i < size; i++)
        if (this->cstr[i] != str.cstr[i])
            return 0;
    return 1;
} // equal to for CharString Obj

bool CharString::checkPalindrome() const
{
    if (!this->cstr)
        return 0;
    if (this->cstr[0] == '\0')
        return 0;
    for (int i = 0, j = size - 1; i < j; i++, j--)
        if (this->cstr[i] != this->cstr[j])
            return 0;
    return 1;
} // palindrome

CharString CharString::reverseStr() const
{
    CharString temp;
    if (size == 0)
        return temp;

    temp.size = this->size;
    temp.cstr = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp.cstr[i] = this->cstr[size - i - 1];
    }
    temp.cstr[size] = '\0';
    return temp;
} // reverse Str

CharString CharString::SubString(int start, int n)
{
    CharString temp;

    if (start < 0 || n <= 0 || start >= size)
        return temp;

    int len;
    if (start + n > size)
        len = size - start;
    else
        len = n;
    temp.size = len;
    temp.cstr = new char[len + 1];
    int s = 0;
    for (int i = 0; i < len; i++)
        temp.cstr[i] = cstr[start + i];
    temp.cstr[len] = '\0';

    return temp;
}

int CharString::countOccurrenceOf(const char *substr) const
{
    int m = mystrlen(substr);

    if (m == 0)
        return 0;
    int cnt = 0;
    for (int i = 0; i + m <= size;)
    {
        int j = 0;
        while (j < m && cstr[i + j] == substr[j])
            j++;
        if (j == m)
        {
            cnt++;
            i += m;
        }
        else
            i++;
    }
    return cnt;
}
