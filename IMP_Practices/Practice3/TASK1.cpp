#include<iostream>
#include"Set.h"
using namespace std;

int main() {
	Set s1(4);
	cout << " 2nd set " << endl;
	Set s2(4);
	//Set u = s1.Union(s2);
	//u.print();

	//Set i = s1.Intersection(s2);
	//i.print(); 

	if (s1.isEqualTo(s2))
		cout << "Sets are equal " << endl;
	else
		cout << "Sets are not equal " << endl;


	return 0;
}