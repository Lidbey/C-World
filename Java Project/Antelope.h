#pragma once
#include "Animal.h"
class Antelope :
	public Animal
{
public:
	char draw();
	Organism* copy();
	Antelope(int, int, World&);
	void action();
	bool collision(Organism*);
};

