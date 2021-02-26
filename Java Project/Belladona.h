#pragma once
#include "Plant.h"
class Belladona :
	public Plant
{
public:
	bool collision(Organism*) override;
	void action() override;
	char draw() override;
	Organism* copy() override;
	Belladona(int, int, World&);
};

