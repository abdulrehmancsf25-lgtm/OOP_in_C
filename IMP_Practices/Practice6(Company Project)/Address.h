#pragma once
#include"CharString.h"
class Address {
	int HouseNo;
	int streetNo;
	char block;
	CharString city;
public:
	Address();
	Address(int, char, int, CharString);
	void displayAddress();
	
};