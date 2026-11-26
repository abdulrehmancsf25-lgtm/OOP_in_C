// BCSF25M519
// The member name is "size_" INSTEAD OF "size" Due to compiler confusion with member function size()
#include "CharString.h"
int strsize(const char* str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i)
		count++;
	return count;
}
CharString::CharString() {
	cstr = nullptr;
	size_ = 0;
	// cout << "Default Ctor called successfully.\n";
}
CharString::CharString(const char* src) {
	int i = strsize(src);
	if (i > 0) {
		cstr = new char[i + 1];
		size_ = i;
		for (i = 0; i < size_ + 1; ++i)
			cstr[i] = src[i];
	}
	else {
		cstr = nullptr;
		size_ = 0;
	}
	// cout << "Object with size_ " << size_
	// << " created successfully.\n";
}
CharString::~CharString() {
	if (cstr)
		delete[] cstr;
	// cout << "Cstr pointer array with size_ "
	// << size_ << " deleted successfully.\n";
}
CharString::CharString(const CharString& src) {
	if (src.size_) {
		size_ = src.size_;
		cstr = new char[size_ + 1];
		for (int i = 0; i < size_ + 1; ++i)
			cstr[i] = src.cstr[i];
	}
	else {
		cstr = nullptr;
		size_ = 0;
	}
	// cout << "Object copy with size_ "
	// << size_ << " created successfully.\n";
}
int CharString::size() const {
	return size_;
}
void CharString::clear() {
	if (cstr)
		delete[] cstr;
	cstr = nullptr;
	// cout << "Object with size_ " << size_
	// << " cleared successfully.\n";
	size_ = 0;
}
void CharString::print() const {
	if (cstr) {
		for (int i = 0; i < size_; ++i)
			cout << cstr[i];
		cout << '\n';
	}
	else
		cout << "Null String cannot be Printed.\n";
}
void CharString::CopyFrom(const char* src) {
	if (cstr)
		delete[] cstr;
	int t = size_;
	size_ = strsize(src);
	if (size_) {
		cstr = new char[size_ + 1];
		for (int i = 0; i < size_ + 1; ++i)
			cstr[i] = src[i];
	}
	else
		cstr = nullptr;
	// cout << "Object with size_ " << t
	// << " is now a copy of string of size_ "
	// << size_ << ", successfully.\n";
}
void CharString::CopyFrom(const CharString& src) {
	if (!(cstr == src.cstr)) {
		if (cstr)
			delete[] cstr;
		int oldsize_ = size_;
		size_ = src.size_;
		cstr = new char[size_ + 1];
		if (size_) {
			for (int i = 0; i < size_ + 1; ++i)
				cstr[i] = src.cstr[i];
		}
		else
			cstr = nullptr;
	}
	// cout << "Object with size_ " << src.size_
	// << " is now a copy of size_ " << oldsize_
	// << " successfully.\n";
}
void CharString::concat(const char* str) {
	int strsize_ = strsize(str);
	int oldsize_ = size_;
	if (cstr) {
		int newsize_ = oldsize_ + strsize_;
		char* temp = new char[newsize_ + 1];
		for (int i = 0; i < newsize_ + 1; ++i)
			if (i < oldsize_)
				temp[i] = cstr[i];
			else
				temp[i] = str[i - oldsize_];
		delete[] cstr;
		size_ += strsize_;
		cstr = temp;
	}
	else if (strsize_) {
		cstr = new char[strsize_ + 1];
		for (int i = 0; i < strsize_ + 1; ++i)
			cstr[i] = str[i];
		size_ = strsize_;
	}
	// cout << "Concatenation of object of size_ "
	// << oldsize_ << " with string of size_ "
	// << strsize_ << " is successful.\n";
}
void CharString::concat(const CharString& str) {
	int oldsize_ = size_;
	if (cstr) {
		char* temp = new char[size_ + 1];
		for (int i = 0; i < size_ + 1; ++i)
			temp[i] = cstr[i];
		delete[] cstr;
		cstr = new char[size_ + str.size_ + 1];
		for (int i = 0; i < size_ + 1; ++i)
			cstr[i] = temp[i];
		for (int i = size_; i < size_ + str.size_ + 1; ++i)
			cstr[i] = str.cstr[i - size_];
		delete[] temp;
		size_ += str.size_;
	}
	else if (str.size_) {
		cstr = new char[str.size_ + 1];
		for (int i = 0; i < str.size_ + 1; ++i)
			cstr[i] = str.cstr[i];
		size_ = str.size_;
	}
	// cout << "Concatenation of object of size_ "
	// << oldsize_ << " with object of size_ "
	// << str.size_ << " is successfull.\n";
}
bool CharString::IsEqualTo(const char* str) const {
	if (strsize(str) == size_) {
		for (int i = 0; i < size_; ++i)
			if (cstr[i] != str[i])
				return 0;
		return 1;
	}
	return 0;
}
bool CharString::IsEqualTo(const CharString& str) const {
	if (size_ != str.size_)
		return 0;
	for (int i = 0; i < size_; ++i)
		if (cstr[i] != str.cstr[i])
			return 0;
	return 1;
}
bool CharString::CheckPalindrome() const {
	for (int i = 0; i < size_ / 2; ++i)
		if (cstr[i] != cstr[size_ - i - 1])
			return 0;
	return 1;
}
CharString CharString::Reverse() const {
	CharString temp;
	if (cstr) {
		temp.size_ = size_;
		temp.cstr = new char[size_ + 1];
		for (int i = 0; i < size_; ++i)
			temp.cstr[i] = cstr[size_ - i - 1];
		temp.cstr[size_] = '\0';
	}
	// cout << "Object with reverse string of size_ "
	// << size_ << " returned successfully.\n";
	return temp;
}
CharString CharString::Substring(int start, int n) const {
	CharString temp;
	if (start < size_) {
		if (n <= size_ - start) {
			temp.size_ = n;
			temp.cstr = new char[size_ + 1];
			for (int i = 0; i < size_; ++i)
				temp.cstr[i] = cstr[start + i];
			temp.cstr[size_] = '\0';
		}
		else {
			temp.size_ = size_ - start;
			temp.cstr = new char[size_ + 1];
			for (int i = 0; i < size_ + 1; ++i)
				temp.cstr[i] = cstr[start + i];
		}
	}
	// cout << "Object with substring of size_ "
	// << temp.size_ << " returned successfully.\n";
	return temp;
}
int CharString::countOccurenceOf(const char* substr) {
	int strsize_ = strsize(substr);
	int count = 0, i, j;
	if (strsize_) {
		for (i = 0; i < size_; ++i) {
			if (cstr[i] == substr[0]) {
				if (strsize_ == 1)
					count++;
				else {
					for (j = 1; j < strsize_; ++j) {
						if (cstr[i + j] != substr[j])
							break;
						else if (j == strsize_ - 1) {
							count++;
							i += j;
						}
					}
				}
			}
		}
	}
	return count;
}