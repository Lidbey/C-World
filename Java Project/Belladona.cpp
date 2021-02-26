#include "Belladona.h"
#include <typeinfo>
char Belladona::draw() { return '>'; }
Organism* Belladona::copy() {
	return new Belladona(this->getX(), this->getY(), this->world);
}
Belladona::Belladona(int x, int y, World& wrld) : Plant(wrld)
{
	this->setPos(x, y);
	this->setStr(99);
	wrld.addOrganism(this);
}
void Belladona::action() {
	Plant::action();
}
bool Belladona::collision(Organism* b) {
	this->setDead();
	b->setDead();
	std::string type = (typeid(*b).name());
	std::string communication = "Animal "\
		+ type.substr(6, 100) + " ID: " + std::to_string(b->getId()) + " Ate Belladona, it results in slow death.";
	world.addCommunicate(communication);
	return 0;
}