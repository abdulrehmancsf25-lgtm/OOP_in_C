#pragma once
#include<iostream>
class Set {
	int* arr;
	int Size;
public:
	Set(int size = 0);  // ctor 

	Set(const Set& other); // copy ctor 

	Set Union(const Set& s)const ;

	void print() const; 

	Set Intersection(const Set& s) const;

	bool isEqualTo(const Set& s) const;



};