#pragma once
#include "Animal.h"
class Sheep :
	public Animal
{
public:
	char draw();
	Organism* copy();
	Sheep(int,int, World&);
	void action();
	bool collision(Organism*);
};

