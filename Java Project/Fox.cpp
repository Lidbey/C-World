#include "Fox.h"

char Fox::draw() { return 'F'; }
Organism* Fox::copy() {
	return new Fox(this->getX(), this->getY(), this->world);
}
Fox::Fox(int x, int y, World& wrld) : Animal(wrld)
{
	this->setPos(x, y);
	this->setStr(3);
	this->setIni(7);
	wrld.addOrganism(this);
}
void Fox::action() {
	while (this->initiative >= 0)
	{
		int side = rand() % 4;
		if (side == UP && this->position.y != 0 && \
			(this->world.checkPos(this->getX(),this->getY()-1)==NULL || this->world.checkPos(this->getX(),this->getY()-1)->getStr()<=this->strength))
		{
			Organism* x = this->world.checkPos(this->getX(), this->getY() - 1);
			if (x == NULL || this->collision(x))
				this->position.y--;
			return;
		}
		else if (side == LEFT && this->position.x != 0 && \
			(this->world.checkPos(this->getX()-1, this->getY()) == NULL || this->world.checkPos(this->getX()-1, this->getY())->getStr() <= this->strength))
		{
			Organism* x = this->world.checkPos(this->getX() - 1, this->getY());
			if (x == NULL || this->collision(x))
				this->position.x--;
			return;
		}
		else if (side == DOWN && this->position.y != world.getY() - 1 && \
			(this->world.checkPos(this->getX(), this->getY() + 1) == NULL || this->world.checkPos(this->getX(), this->getY() + 1)->getStr() <= this->strength))
		{
			Organism* x = this->world.checkPos(this->getX(), this->getY() + 1);
			if (x == NULL || this->collision(x))
				this->position.y++;
			return;
		}
		else if (side == RIGHT && this->position.x != world.getX() - 1 && \
			(this->world.checkPos(this->getX()+1, this->getY()) == NULL || this->world.checkPos(this->getX()+1, this->getY())->getStr() <= this->strength))
		{
			Organism* x = this->world.checkPos(this->getX() + 1, this->getY());
			if (x == NULL || this->collision(x))
				this->position.x++;
			return;
		}
	}
}
bool Fox::collision(Organism* b){
	return Animal::collision(b);
}