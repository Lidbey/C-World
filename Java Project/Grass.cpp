#include "Grass.h"
char Grass::draw() { return '='; }
Organism* Grass::copy() {
	return new Grass(this->getX(), this->getY(), this->world);
}
Grass::Grass(int x, int y, World& wrld) : Plant(wrld)
{
	this->setPos(x, y);
	this->setStr(0);
	wrld.addOrganism(this);
}
void Grass::action() {
	Plant::action();
}
bool Grass::collision(Organism* b) {
	return Plant::collision(b);
}