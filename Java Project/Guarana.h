#pragma once
#include "Plant.h"
class Guarana :
	public Plant
{
public:
	bool collision(Organism*) override;
	void action() override;
	char draw() override;
	Organism* copy() override;
	Guarana(int, int, World&);
};

