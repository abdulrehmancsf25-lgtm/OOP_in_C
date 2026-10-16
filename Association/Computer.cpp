#include "Computer.h"


Computer::Computer() {
	model = ' ';
	employee = NULL;
}
Computer :: Computer(string model, Employee* e) :model(model), employee(e) {}
