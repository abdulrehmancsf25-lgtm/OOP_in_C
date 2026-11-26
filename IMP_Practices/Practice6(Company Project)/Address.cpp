#include"Address.h"
#include<iostream>
using namespace std;
Address::Address(){}
Address::Address(int houseNo, char block, int streetNo, CharString city):city(city){
	this->HouseNo = houseNo;
	this->block = block;
	this->streetNo = streetNo;
}

void Address::displayAddress() {
	cout << "House No : " << this->HouseNo << endl;
	cout << "Block : " << this->block << endl;
	cout << "Street No: " << this->streetNo << endl;
	cout << "City : ";
	this->city.print();
}