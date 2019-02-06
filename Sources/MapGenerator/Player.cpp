#include <MapGenerator/Player.h>

void Player::setPosition(Position pos)
{
	pos_ = pos;
}

void Player::useItem(const Item &item)
{
	maxHealth_ += item.healthBuff;
	actualHealth_ += item.healthBuff;
	attack_ += item.attackBuff;
}