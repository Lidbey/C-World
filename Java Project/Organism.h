#pragma once
#include "World.h"
typedef struct {
	int x;
	int y;
}point;
class World;
class Organism
{
protected:
	int age;
	int id;
	point position;
	int strength;
	int initiative;
	World& world;
public:
	virtual bool isAnimal();
	virtual bool collision(Organism*);
	virtual char draw();
	virtual void action();
	virtual Organism* copy();
	Organism(World&);
	int getStr();
	void setStr(int);
	int getId();
	void setId(int);
	point getPos();
	int getX();
	int getY();
	void setPos(point);
	void setPos(int, int);
	int getIni();
	void setIni(int);
	void setDead();
	void advanceAge();
	int getAge();
	void setAge(int);
	World& getWorld();
};