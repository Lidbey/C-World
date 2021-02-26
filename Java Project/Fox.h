#pragma once
#include "Animal.h"
class Fox :
	public Animal
{
public:
	char draw();
	Organism* copy();
	Fox(int, int, World&);
	void action();
	bool collision(Organism*);
};

