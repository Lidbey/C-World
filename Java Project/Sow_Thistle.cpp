#include "Sow_Thistle.h"
char Sow_Thistle::draw() { return '+'; }
Organism* Sow_Thistle::copy() {
	return new Sow_Thistle(this->getX(), this->getY(), this->world);
}
Sow_Thistle::Sow_Thistle(int x, int y, World& wrld) : Plant(wrld)
{
	this->setPos(x, y);
	this->setStr(0);
	wrld.addOrganism(this);
}
void Sow_Thistle::action() {
	Plant::action();
	Plant::action();
	Plant::action();
}
bool Sow_Thistle::collision(Organism* b) {
	return Plant::collision(b);
}