#include "Human.h"
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
char Human::draw() { return 'H'; }
Organism* Human::copy() {
	return new Human(this->getX(), this->getY(), this->world);
}
Human::Human(int x, int y, World& wrld) : Animal(wrld)
{
	this->side = 4;
	this->powerused = 0;
	this->remainingtours = -1;
	this->setPos(x, y);
	this->setStr(5);
	this->setIni(4);
	wrld.addOrganism(this);
}
void Human::action() {
	if (this->initiative >= 0)
	{
		if(remainingtours==5)
			world.addCommunicate("Human used his MAGICAL POTION!!!");
		if (side == UP && this->position.y != 0)
		{
			this->side = STOP;
			Organism* x = this->world.checkPos(this->getX(), this->getY() - 1);
			if (x == NULL || this->collision(x))
				this->position.y--;
			return;
		}
		else if (side == LEFT && this->position.x != 0)
		{
			this->side = STOP;
			Organism* x = this->world.checkPos(this->getX() - 1, this->getY());
			if (x == NULL || this->collision(x))
				this->position.x--;
			return;
		}
		else if (side == DOWN && this->position.y != world.getY() - 1)
		{
			this->side = STOP;
			Organism* x = this->world.checkPos(this->getX(), this->getY() + 1);
			if (x == NULL || this->collision(x))
				this->position.y++;
			return;
		}
		else if (side == RIGHT && this->position.x != world.getX() - 1)
		{
			this->side = STOP;
			Organism* x = this->world.checkPos(this->getX() + 1, this->getY());
			if (x == NULL || this->collision(x))
				this->position.x++;
			return;
		}
	}
	if (remainingtours > 0)
	{
		this->strength--;
		this->remainingtours--;
	}
	else if (remainingtours > -5)
		this->remainingtours--;
	else if (remainingtours == -5)
		this->powerused = 0;
}
bool Human::collision(Organism* b) {
	return Animal::collision(b);
}
void Human::usepower() {
	if (this->powerused != 1)
	{
		this->powerused = 1;
		this->remainingtours = 5;
		this->strength += 5;
	}
}
void Human::setSide(int side)
{
	this->side = side;
}