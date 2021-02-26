#pragma once
#include "Plant.h"
class Sosnowsky_Hogweed :
	public Plant
{
public:
	bool collision(Organism*) override;
	void action() override;
	char draw() override;
	Organism* copy() override;
	Sosnowsky_Hogweed(int, int, World&);
};

