// BCSF25M519
// The member name is "size_" INSTEAD OF "size" Due to compiler confusion with member function size()
#include <iostream>
#pragma once
using namespace std;
int strsize(const char* str);
class CharString {
	char* cstr;
	int size_;
public:
	CharString();
	CharString(const char* src);
	~CharString();
	CharString(const CharString& src);
	int size() const;
	void clear();
	void print() const;
	void CopyFrom(const char* src);
	void CopyFrom(const CharString& src);
	void concat(const char* str);
	void concat(const CharString& str);
	bool IsEqualTo(const char* str) const;
	bool IsEqualTo(const CharString& str) const;
	bool CheckPalindrome() const;
	CharString Reverse() const;
	CharString Substring(int start, int n) const;
	int countOccurenceOf(const char* substr);
};

