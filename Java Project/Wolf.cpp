#include "Wolf.h"
char Wolf::draw() { return 'W'; }
Organism* Wolf::copy() {
	return new Wolf(this->getX(), this->getY(), this->world);
}
Wolf::Wolf(int x, int y, World& wrld) : Animal(wrld)
{
	this->setPos(x, y);
	this->setStr(9);
	this->setIni(5);
	wrld.addOrganism(this);
}
void Wolf::action() {
	Animal::action();
}
bool Wolf::collision(Organism* b) {
	return Animal::collision(b);
}