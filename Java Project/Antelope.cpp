#include "Antelope.h"
#include <typeinfo>
char Antelope::draw() { return 'A'; }
Organism* Antelope::copy() {
	return new Antelope(this->getX(), this->getY(), this->world);
}
Antelope::Antelope(int x, int y, World& wrld) : Animal(wrld)
{
	this->setPos(x, y);
	this->setStr(4);
	this->setIni(4);
	wrld.addOrganism(this);
}
void Antelope::action() {
	while (this->initiative >= 0)
	{
		int side = rand() % 4;
		if (side == UP && this->position.y != 0 && this->position.y!=1)
		{
			Organism* x = this->world.checkPos(this->getX(), this->getY() - 2);
			if (x == NULL || this->collision(x))
				this->position.y-=2;
			return;
		}
		else if (side == LEFT && this->position.x != 0&&this->position.x!=1)
		{
			Organism* x = this->world.checkPos(this->getX() - 2, this->getY());
			if (x == NULL || this->collision(x))
				this->position.x-=2;
			return;
		}
		else if (side == DOWN && this->position.y != world.getY() - 1 && this->position.y !=world.getY()-2)
		{
			Organism* x = this->world.checkPos(this->getX(), this->getY() + 2);
			if (x == NULL || this->collision(x))
				this->position.y+=2;
			return;
		}
		else if (side == RIGHT && this->position.x != world.getX() - 1 && this->position.x != world.getX()-2)
		{
			Organism* x = this->world.checkPos(this->getX() + 2, this->getY());
			if (x == NULL || this->collision(x))
				this->position.x+=2;
			return;
		}
	}
}
bool Antelope::collision(Organism* b) {
	if (rand() % 2)
		return Animal::collision(b);
	else
	{
		std::string type = (typeid(*b).name());
		std::string typethis = (typeid(*this).name());
		std::string communication = typethis.substr(6, 100) + " with ID " + std::to_string(this->getId()) + " Managed to escape from "\
			+ type.substr(6, 100) + " ID: " + std::to_string(b->getId());
		world.addCommunicate(communication);
		while (this->initiative >= 0)
		{
			int side = rand() % 4;
			if (side == UP && this->position.y >2)
			{
				this->position.y--;
				return 0;
			}
			else if (side == LEFT && this->position.x > 2)
			{
				this->position.x--;
				return 0;
			}
			else if (side == DOWN && this->position.y < world.getY() - 3)
			{
				this->position.y++;
				return 0;
			}
			else if (side == RIGHT && this->position.x < world.getX() - 3)
			{
				this->position.x++;
				return 0;
			}
		}
		return 0;
	}
}