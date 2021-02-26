#pragma once
#include "Plant.h"
class Grass :
	public Plant
{
public:
	bool collision(Organism*) override;
	void action() override;
	char draw() override;
	Organism* copy() override;
	Grass(int,int,World&);
};

