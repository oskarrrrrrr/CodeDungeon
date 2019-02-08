#include <MapGenerator/Creature.h>

bool Creature::isAllive() const
{
	return actualHealth_ > 0;
}

int Creature::maxHealth() const
{
	return maxHealth_;
}

int Creature::actualHealth() const
{
	return actualHealth_;
}

int Creature::attack() const
{
	return attack_;
}


void Creature::makeMove(const Move& move)
{
	pos_ += move.dir;
}

void Creature::getHit(int dmg)
{
	actualHealth_ -= dmg;
}

void Creature::useItem(int item) {}

void Creature::pickItem(std::unique_ptr<Item> item) {}

bool Creature::canPickItem() {}
