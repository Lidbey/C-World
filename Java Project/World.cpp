#include "AllHeaders.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
World::World(int x, int y) :x(x),y(y), h(NULL), maxId(0){
	this->plane = new char* [x];
	for (int i = 0; i < x; ++i)
		this->plane[i] = new char[y];
}
World::World() : x(20), y(20), h(NULL),maxId(0) {
	this->plane = new char* [20];
	for (int i = 0; i < 20; ++i)
		this->plane[i] = new char[20];
}
void World::makeTurn() {
	communication.clear();
	for (std::vector<Organism*>::size_type i = 0; i != organisms.size(); i++) {
		organisms[i]->action(), organisms[i]->advanceAge();
	}
}
void World::drawWorld() {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			this->plane[i][j] = '-';
	for (std::vector<Organism*>::size_type i = 0; i != organisms.size(); i++) {
		if (organisms[i]->getIni() >=0 && organisms[i]->getX()>=0 &&organisms[i]->getY()>=0)
			this->plane[organisms[i]->getX()][organisms[i]->getY()] = organisms[i]->draw();
	}
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			std::cout << this->plane[j][i];
		if (i == 0)
		{
			std::cout << "        Author:";
		}
		else if (i == 1)
		{
			std::cout << "        Wojciech Wicki";
		}
		else if (i == 2)
		{
			std::cout << "        ID: 180432";
		}
		std::cout << std::endl;
	}
	for (std::vector<std::string>::size_type i = 0; i != communication.size(); i++) {
		std::cout<<communication[i]<<std::endl;
	}/*
	for (std::vector<Organism*>::size_type i = 0; i < organisms.size();) {
		if (organisms[i]->getIni() == -1) delete organisms[i], organisms.erase(organisms.begin()+i);
		else i++;
	}*/
}

int World::getY() {
	return this->y;
}
int World::getX() {
	return this->x;
}
void World::addOrganism(Organism* x) {
	x->setId(this->maxId);
	this->maxId++;
	for (auto i = organisms.begin(); i != organisms.end(); i++) {
		if ((*i)->getIni() < x->getIni())
		{
			organisms.insert(i, 1, x);
			return;
		}
	}
	this->organisms.push_back(x);
}
void World::addCommunicate(std::string s)
{
	communication.push_back(s);
}
int World::getmaxId()
{
	return this->maxId;
}
Organism* World::checkPos(int x, int y)
{
	for (auto i = organisms.begin(); i != organisms.end(); i++) {
		if ((*i)->getX() == x && (*i)->getY() == y)
		{
			return *i;
		}
	}
	return NULL;
}
void World::erase(int id)
{
	for (auto i = organisms.begin(); i != organisms.end(); i++) {
		if ((*i)->getId()==id)
		{
			this->organisms.erase(i);
			delete (*i);
			return;
		}
	}
}

void World::setHuman(Human* x)
{
	this->h = x;
}

Human* World::man()
{
	return this->h;
}

void World::savegame() {
	std::ofstream output;
	output.open("savedstate.txt");
	if (!output)
	{	
	std::cout << "Can't save game state!";
	return;
	}
	output << this->x << ' ' << this->y << ' ' << this->maxId <<"\n";
	for (auto i = organisms.begin(); i != organisms.end(); i++) {
		if((*i)->getIni()!=-1)
			output << (*i)->getX() << ' ' << (*i)->getY() << ' ' << (*i)->getStr() <<' '<< (*i)->getAge() << ' ' << (*i)->getId() << ' ' << (*i)->draw() <<std::endl;
	}
	output.close();
}

void World::loadgame() {
	std::ifstream input;
	input.open("savedstate.txt");
	if (!input)
	{
		std::cout << "Can't load game state!";
		return;
	}
	//clearing this world
	for (int i = 0; i < x; ++i)
		delete this->plane[i];
	delete this->plane;
	organisms.clear();
	communication.clear();
	//
	input >> this->x >> this->y >> this->maxId;
	this->plane = new char* [this->x];
	for (int i = 0; i < x; ++i)
		this->plane[i] = new char[this->y];
	int ax;
	int ay;
	int astr;
	int aage;
	int aid;
	char alet;
	while (input >> ax >> ay >> astr >> aage >> aid >> alet) {
		if (alet == 'A')//antelope
		{
			Antelope* organ = new Antelope(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
		else if (alet == 'F')//fox
		{
			Fox* organ = new Fox(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
		else if (alet == 'H')//human
		{
			Human* organ = new Human(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
			this->setHuman(organ);
		}
		else if (alet == 'S')//sheep
		{
			Sheep* organ = new Sheep(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
		else if (alet == 'T')//turtle
		{
			Turtle* organ = new Turtle(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
		else if (alet == 'W')//wolf
		{
			Wolf* organ = new Wolf(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
		else if (alet == '>')//belladona
		{
			Belladona* organ = new Belladona(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
		else if (alet == '=')
		{//grass
			Grass* organ = new Grass(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
		else if (alet == '*')//guarana
		{
			Guarana* organ = new Guarana(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
		else if (alet == 'X')//sosnowsky hogweed
		{	
			Sosnowsky_Hogweed* organ = new Sosnowsky_Hogweed(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
		else if (alet == '+')
		{//sow thistle
			Sow_Thistle* organ = new Sow_Thistle(ax, ay, *this);
			organ->setStr(astr), organ->setId(aid), organ->setAge(aage);
			this->addOrganism(organ);
		}
	}
	system("CLS");
	this->drawWorld();
	input.close();
}



World::~World() {
	for (int i = 0; i < x; ++i)
		delete this->plane[i];
	delete this->plane;
}

