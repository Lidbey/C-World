#include "Animal.h"
#include <cstdlib>
#include <typeinfo>

Animal::Animal(World& w) :Organism(w) { ; }

char Animal::draw() { return 0; }
Organism* Animal::copy() { return NULL; }
bool Animal::isAnimal() { return 1; }

void Animal::action() {
	while (this->initiative>=0)
	{
		int side = rand() % 4;
		if (side == UP && this->position.y != 0)
		{
			Organism* x = this->world.checkPos(this->getX(), this->getY()-1);
			if(x==NULL || this->collision(x))
				this->position.y--;
			return;
		}
		else if (side == LEFT && this->position.x != 0)
		{
			Organism* x = this->world.checkPos(this->getX()-1, this->getY());
			if (x == NULL || this->collision(x))
				this->position.x--;
			return;
		}
		else if (side == DOWN && this->position.y != world.getY() - 1)
		{
			Organism* x = this->world.checkPos(this->getX(), this->getY() + 1);
			if (x == NULL || this->collision(x))
				this->position.y++;
			return;
		}
		else if (side == RIGHT && this->position.x != world.getX() - 1)
		{
			Organism* x = this->world.checkPos(this->getX()+1, this->getY());
			if (x == NULL || this->collision(x))
				this->position.x++;
			return;
		}
	}
}
bool Animal::collision(Organism* b) {
	if (typeid(*this) == typeid(*b)) //&& b->getId()<world.getmaxId())
	{
		if (b->getAge() > 10 && this->age > 10)
		{
			Organism* x = b->copy();
			//this->world.addOrganism(x);
			std::string type = (typeid(*b).name());
			std::string communication = type.substr(6, 100) + "s with IDs: " + std::to_string(b->getId())+", "+std::to_string(this->id)+" Copulated, creating small "\
				+type.substr(6,100)+" with ID: "+std::to_string(x->getId());
			world.addCommunicate(communication);
		}
		return 0;
	}
	else if (this->strength > b->getStr())
	{
		return !b->collision(this);
	}
	else if(this->strength<b->getStr())
	{
		this->setDead();
		std::string type = (typeid(*b).name());
		std::string typethis = (typeid(*this).name());
		std::string communication = typethis.substr(6, 100) + " with ID " + std::to_string(this->getId()) + " Died to "\
			+ type.substr(6, 100) + " ID: " + std::to_string(b->getId());
		world.addCommunicate(communication);
		return 0;
	}
	return 0;
}