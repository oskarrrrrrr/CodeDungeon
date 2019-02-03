#include <MapGenerator/Entity.h>

int Entity::id_counter_ = 0;

int Entity::id() const
{
	return id_;
}

const Position& Entity::position() const
{
	return pos_;
}
