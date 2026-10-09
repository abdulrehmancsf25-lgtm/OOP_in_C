#include "Set.h"
using namespace std;

	 Set :: Set(int size ) {
		 bool temp[101] = { 0 };
		 
		this->Size = size;
		if (size != 0)
			arr = new int[size];
		else
			arr = nullptr;
		for (int i = 0; i < size; i++) {
			int x;
			cout << "Enter input : ";
			cin >> x;
			while (x < 0 || x > 100 || temp[x]) {
				cout << "Enter input again(0-100) : ";
				cin >> x;
			}
			arr[i] = x;
			temp[x] = true;
		}
	} // ctor 

	Set::Set(const Set& other) {
		this->Size = other.Size;
		if (this->Size == 0)
			arr = 0;
		else
			arr = new int[Size];
		for (int i = 0; i < Size; i++) {
			this->arr[i] = other.arr[i];
		}
	} // copy ctor 

	Set Set::Intersection(const Set& other)const  {
		Set temp;
		int mini = min(this->Size, other.Size);
		int* xrr = new int[mini];
		for (int i = 0; i < mini; i++) {
			xrr[i] = INT_MIN;
		}

		
		int i = 0, cnt = 0;
		if (this->Size < other.Size) {
			for (; i < this->Size; i++) {
				bool isPresent = false;
				for (int j = 0; j < other.Size; j++) {
					if (arr[i] == other.arr[j]) {
						isPresent = true;
						break;
					}
				}
				if (isPresent) {
					xrr[cnt++] = arr[i];
				}
			}
		} // if this < other
		else {
			for (; i < other.Size; i++) {
				bool isPresent = false;
				for (int j = 0; j < this ->Size; j++) {
					if (other.arr[i] == this ->arr[j]) {
						isPresent = true;
						break;
					}
				}
				if (isPresent) {
					xrr[cnt++] = other.arr[i];
				}
			}
		}

		cnt = 0;
		for (int i = 0; i < mini; i++) {
			if (xrr[i] != INT_MIN)
				cnt++;
			else
				break;
		 }

		temp.Size = cnt;
		temp.arr = new int[cnt];
		for (int i = 0; i <= cnt; i++)
			temp.arr[i] = xrr[i]; // copy done size done 
		delete[] xrr;
		return temp;
	}

	void Set::print()const {
		for (int i = 0; i < this->Size; i++)
			cout << this->arr[i] << " ";
		cout << endl;
	}

	Set Set::Union(const Set& other)const {

		Set temp;
		int* xrr = new int[this->Size + other.Size];
		for (int i = 0; i < this->Size + other.Size; i++) {
			xrr[i] = INT_MIN;
		}
		int cnt = 0;


		for (int i = 0; i < this->Size; i++) {
			xrr[cnt++] = this->arr[i];
		}


		for (int i = 0; i < other.Size; i++) {
			bool isPresent = false;
			for (int j = 0; j < this->Size; j++) {
				if (other.arr[i] == this->arr[j]) {
					isPresent = true;
					break;
				}
			}
			if(!isPresent)
			xrr[cnt++] = other.arr[i];
		}

		// copy completed 
		cnt = 0;
		for (int i = 0; i < this->Size + other.Size; i++) {
			if (xrr[i] != INT_MIN)
				cnt++;
			else
				break;
		}

		temp.Size = cnt;
		temp.arr = new int[cnt];
		for (int i = 0; i <= cnt; i++) {
			temp.arr[i] = xrr[i];
		}
		delete[] arr;
		return temp;
	}


	bool Set::isEqualTo(const Set& s) const {
		if (this == &s)
			return true;
			 
		if (this->Size != s.Size)
			return false;
		for (int i = 0; i < this->Size; i++) {
			bool match = false;
			for (int j = 0; j < s.Size; j++)
				if (arr[i] == s.arr[j]) {
					match = true;
					break;
				}
			if (!match)
				return false;
		}
					
		return true;
	}