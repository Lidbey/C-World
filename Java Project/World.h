#pragma once
#include "Organism.h"
#include <vector>
#include <string>
class Organism;
class Human;
class World
{
private:
	int maxId;
	int x;
	int y;
	std::vector<Organism*>organisms;
	char** plane;
	std::vector<std::string>communication;
	Human* h;
public:
	World(int, int);
	World();
	void makeTurn();
	void drawWorld();
	int getX();
	int getY();
	int getmaxId();
	void addOrganism(Organism*);
	void addCommunicate(std::string);
	Organism* checkPos(int, int);
	void erase(int);
	void savegame();
	void loadgame();
	void setHuman(Human*);
	Human* man();
	~World();
};

