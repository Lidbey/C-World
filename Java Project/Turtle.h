#pragma once
#include "Animal.h"
class Turtle :
	public Animal
{
private:
	bool TurtleAttack;
public:
	char draw();
	Organism* copy();
	Turtle(int, int, World&);
	void action();
	bool collision(Organism*);
};

