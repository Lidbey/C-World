#include "Plant.h"
#include <typeinfo>

bool Plant::collision(Organism* b) {
	if (this->strength > b->getStr())
	{
		return !b->collision(this);
	}
	else if (this->strength < b->getStr())
	{
		this->setDead();
		return 0;
	}
	return 0;
}
void Plant::action() {
	if (rand() % 15==0 && this->initiative>=0)
	{
		int tempx = (rand() % 3) - 1;
		if (this->getX() == 0 && tempx==-1)
			tempx = rand()%2;
		else if (this->getX() == world.getX() - 1 && tempx==1)
			tempx = rand()%2-1;
		int tempy = (rand() % 3) - 1;
		if (this->getY() == 0 && tempy==-1)
			tempy = rand()%2;
		else if (this->getY() == world.getY() - 1 && tempy==1)
			tempy = rand()%2-1;
		Organism* org = this->world.checkPos(this->getX()+tempx, this->getY()+tempy);
		if (org == NULL)
		{
			org = this->copy();
			org->setPos({ this->getX()+tempx,this->getY()+tempy });
			//world.addOrganism(org);
		}
		return;
	}
}
bool Plant::isAnimal() { return 0; }
char Plant::draw() { return 0; }
Organism* Plant::copy() { return NULL; }
Plant::Plant(World& w) :Organism(w) { this->setIni(0); }