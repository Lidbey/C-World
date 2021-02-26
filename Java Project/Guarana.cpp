#include "Guarana.h"
#include <typeinfo>
char Guarana::draw() { return '*'; }
Organism* Guarana::copy() {
	return new Guarana(this->getX(), this->getY(), this->world);
}
Guarana::Guarana(int x, int y, World& wrld) : Plant(wrld)
{
	this->setPos(x, y);
	this->setStr(0);
	wrld.addOrganism(this);
}
void Guarana::action() {
	Plant::action();
}
bool Guarana::collision(Organism* b) {
	if (this->strength > b->getStr())
	{
		return !b->collision(this);
	}
	else if (this->strength < b->getStr())
	{
		this->setDead();
		b->setStr(b->getStr() + 3);
		std::string type = (typeid(*b).name());
		std::string communication = "Animal "\
			+ type.substr(6, 100) + " ID: " + std::to_string(b->getId()) + " Ate guarana! It is now much more powerful";
		world.addCommunicate(communication);
		return 0;
	}
	return 0;
}