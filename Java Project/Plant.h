#pragma once
#include "Organism.h"
class Plant :
	public Organism
{
public:
	virtual bool collision(Organism*);
	virtual void action();
	virtual char draw();
	virtual Organism* copy();
	bool isAnimal();
	Plant(World&);
};

