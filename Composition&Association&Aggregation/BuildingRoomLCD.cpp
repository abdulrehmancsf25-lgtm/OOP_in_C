#include <iostream>
using namespace std;

class Room; // forward declaration

class LCD
{
	int lcdId;

public:
	Room *rptr;
	LCD(int id) : lcdId(id), rptr(nullptr) { cout << "LCD " << lcdId << endl; }
	int getId() { return lcdId; }
	~LCD() { cout << "LCD::dtor " << lcdId << endl; }
};

class Room
{
	int room_id;
	static int count;
	LCD *lcd;

public:
	int getRoomNo() { return room_id; }
	int getRoomID() { return room_id; }

	Room() : room_id(++count)
	{
		lcd = nullptr;
		cout << "A new room is created " << room_id << endl;
	}
	Room(int no)
	{
		lcd = nullptr;
		room_id = no;
		cout << "Room::ctor2 for room no. " << room_id << endl;
	}
	~Room()
	{
		cout << "Room::dtor for room no. " << room_id << endl;
	}

	bool assignLCD(LCD *lptr)
	{
		if (lptr->rptr == nullptr)
		{
			cout << "Assigning LCD\n";
			lcd = lptr;
			lcd->rptr = this;
			return true;
		}
		else
		{
			cout << "LCD " << lptr->getId() << "already assigned to another room\n";
			return false;
		}
	}

	void removeLCD()
	{
		/*	cout << "Removing LCD\n";
			lcd->isAssigned = 0;
			lcd = nullptr;*/
	}
	void PrintLCDInfo()
	{
		if (lcd != nullptr)
		{
			cout << "I got LCD " << lcd->getId() << endl;
		}
		else
		{

			cout << "No LCD :(\n";
		}
	}
};
int Room::count = 0;

class Building
{
	int building_no;
	Room r1;
	Room r2;

public:
	Building() : building_no(0), r2(7), r1(5)
	{
		cout << "Building::ctor\n";
		// cout<< "Building has room no. "<<r1.getRoomNo()<<endl;
	}

	Building(Room &r) : r1(r)
	{
		cout << "Building::ctor2\n";
	}

	~Building()
	{
		cout << "Building::dtor\n";
		// cout << "Room no. " << r1.getRoomNo() << "also destroyed\n";
	}
};

int main()
{
	LCD lcd1(1);
	Building b1;
}