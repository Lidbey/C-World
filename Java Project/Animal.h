#pragma once
#include "Organism.h"

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

class Animal :
	public Organism
{
public:
	virtual bool collision(Organism*);
	virtual void action();
	virtual char draw();
	virtual Organism* copy();
	bool isAnimal();
	Animal(World&);
};

