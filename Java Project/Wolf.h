#pragma once
#include "Animal.h"
class Wolf :
	public Animal
{
public:
	char draw();
	Organism* copy();
	Wolf(int, int, World&);
	void action();
	bool collision(Organism*);
};

