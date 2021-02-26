#include "Organism.h"

int Organism::getStr() { return this->strength; }
void Organism::setStr(int s) { this->strength = s; }
int Organism::getId() { return this->id; }
void Organism::setId(int i) { this->id = i; }
point Organism::getPos() { return this->position; }
int Organism::getX() { return this->position.x; }
int Organism::getY() { return this->position.y; }
void Organism::setPos(point p) { this->position = p; }
void Organism::setPos(int x, int y) { this->position.x = x, this->position.y = y; }
int Organism::getIni() { return this->initiative; }
void Organism::setIni(int i) { this->initiative = i; }
void Organism::setDead() { this->initiative = -1, this->position = { -10,-10 }; }
World& Organism::getWorld() { return this->world; }
Organism::Organism(World& w) : world(w), id(0), initiative(0), strength(0), position({ 0,0 }), age(0) { ; }
bool Organism::collision(Organism*) { return 0; }
void Organism::setAge(int age) { this->age = age; }
char Organism::draw() { return 0; }
void Organism::action() {}
void Organism::advanceAge() { this->age++; }
bool Organism::isAnimal() { return 0; }
int Organism::getAge() { return this->age; }
Organism* Organism::copy() { return NULL; }