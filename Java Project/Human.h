#pragma once
#include "Animal.h"
#define STOP 4
class Human :
	public Animal
{
private:
	int side;
	bool powerused;
	int remainingtours;
public:
	char draw();
	Organism* copy();
	Human(int, int, World&);
	void action();
	bool collision(Organism*);
	void usepower(); //magic potion
	void setSide(int);
};

