#include "Turtle.h"
#include <typeinfo>
char Turtle::draw() { return 'T'; }
Organism* Turtle::copy() {
	return new Turtle(this->getX(), this->getY(), this->world);
}
Turtle::Turtle(int x, int y, World& wrld) : Animal(wrld)
{
	this->TurtleAttack = 0;
	this->setPos(x, y);
	this->setStr(2);
	this->setIni(1);
	wrld.addOrganism(this);
}
void Turtle::action() {
	if (rand() % 4 == 0) {

		this->TurtleAttack = 1;
		Animal::action();
		this->TurtleAttack = 0;
	}
	else
		return;
}
bool Turtle::collision(Organism* b) {
	if (typeid(*this) == typeid(*b))
	{
		if (b->getAge() > 10 && this->age > 10)
		{
			Organism* x = b->copy();
			//this->world.addOrganism(x);
			std::string type = (typeid(*b).name());
			std::string communication = type.substr(6, 100) + "s with IDs: " + std::to_string(b->getId()) + ", " + std::to_string(this->id) + " Copulated, creating small "\
				+ type.substr(6, 100) + " with ID: " + std::to_string(x->getId());
			world.addCommunicate(communication);
		}
		this->TurtleAttack = 0;
		return 0;
	}
	else if (this->strength > b->getStr())
	{
		this->TurtleAttack = 0;
		return !b->collision(this);
	}
	else if (this->strength < b->getStr())
	{
		if (this->TurtleAttack == 1 || b->getStr() >= 5)
		{
			this->setDead();
			std::string type = (typeid(*b).name());
			std::string typethis = (typeid(*this).name());
			std::string communication = typethis.substr(6, 100) + " with ID " + std::to_string(this->getId()) + " Attacked and Died to "\
				+ type.substr(6, 100) + " ID: " + std::to_string(b->getId());
			world.addCommunicate(communication);
			this->TurtleAttack = 0;
			return 0;
		}
		else
		{
			std::string type = (typeid(*b).name());
			std::string typethis = (typeid(*this).name());
			std::string communication = typethis.substr(6, 100) + " with ID " + std::to_string(this->getId()) + " Stopped attack of "\
				+ type.substr(6, 100) + " ID: " + std::to_string(b->getId());
			world.addCommunicate(communication);
			this->TurtleAttack = 0;
			return 1;
		}
	}
	this->TurtleAttack = 0;
	return 0;
}