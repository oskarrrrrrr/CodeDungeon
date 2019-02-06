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
	pos_ += move;
}

void Creature::useItem(const Item &item)
{}
