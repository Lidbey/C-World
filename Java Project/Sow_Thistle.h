#pragma once
#include "Plant.h"
class Sow_Thistle :
	public Plant
{
public:
	bool collision(Organism*) override;
	void action() override;
	char draw() override;
	Organism* copy() override;
	Sow_Thistle(int, int, World&);
};

