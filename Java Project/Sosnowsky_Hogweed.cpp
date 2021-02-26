#include "Sosnowsky_Hogweed.h"
#include <typeinfo>
char Sosnowsky_Hogweed::draw() { return 'X'; }
Organism* Sosnowsky_Hogweed::copy() {
	return new Sosnowsky_Hogweed(this->getX(), this->getY(), this->world);
}
Sosnowsky_Hogweed::Sosnowsky_Hogweed(int x, int y, World& wrld) : Plant(wrld)
{
	this->setPos(x, y);
	this->setStr(99);
	wrld.addOrganism(this);
}
void Sosnowsky_Hogweed::action() {
	Organism* o;
	std::string type = "";
	std::string communication = "";
	for(int i=-1; i<2;i++)
		for (int j = -1; j < 2; j++)
		{
			if (j == 0 && i == 0)
				continue;
			o = this->world.checkPos(this->getX()+i, this->getY()+j);
			if (o == NULL || o->isAnimal()==0)
				continue;
			o->setDead();
			type = typeid(*o).name();
			communication = "Animal "\
				+ type.substr(6, 100) + " ID: " + std::to_string(o->getId()) + " Came too close to Sosnowsky Hogweed, it's painful";
			world.addCommunicate(communication);
		}
}
bool Sosnowsky_Hogweed::collision(Organism* b) {
	this->setDead();
	b->setDead();
	std::string type = (typeid(*b).name());
	std::string communication = "Animal "\
		+ type.substr(6, 100) + " ID: " + std::to_string(b->getId()) + " Came too close to Sosnowsky Hogweed, it's painful";
	world.addCommunicate(communication);
	return 0;
}