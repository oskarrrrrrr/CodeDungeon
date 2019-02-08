#include <MapGenerator/Player.h>
#include <algorithm>

void Player::setPosition(Position pos)
{
	pos_ = pos;
}

void Player::useItem(int item)
{
	auto itemIt = std::find_if(std::begin(items_), std::end(items_),
		[&item](const std::unique_ptr<Item> &itemPtr) { return itemPtr ? itemPtr->id() == item : false; });

	if(itemIt == std::end(items_))
	{
		throw std::logic_error("Wrong item to use.");
	}
	auto &itemPtr = *itemIt;
	maxHealth_ += itemPtr->healthBuff;
	actualHealth_ += itemPtr->healthBuff;
	attack_ += itemPtr->attackBuff;

	itemIt->reset();
}

bool Player::canPickItem()
{
    return std::find_if(std::begin(items_), std::end(items_), [](const std::unique_ptr<Item>& slot){ return !slot;}) != std::end(items_);
}

void Player::pickItem(std::unique_ptr<Item> item)
{
	auto freeSlot = std::find_if(std::begin(items_), std::end(items_), [](const std::unique_ptr<Item>& slot){ return !slot;});
	*freeSlot = std::move(item);
}

Action Player::genAction(Map& map) const
{}