#include "Sheep.h"

char Sheep::draw() { return 'S'; }
Organism* Sheep::copy() { 
	return new Sheep(this->getX(), this->getY(), this->world); 
}
Sheep::Sheep(int x, int y, World& wrld) : Animal(wrld)
{
	this->setPos(x, y);
	this->setStr(4);
	this->setIni(4);
	wrld.addOrganism(this);
}
void Sheep::action() {
	Animal::action();
}
bool Sheep::collision(Organism* b) {
	return Animal::collision(b);
}
