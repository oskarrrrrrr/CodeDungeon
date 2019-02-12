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

	maxHealth_ += itemPtr->healthBuff();
	actualHealth_ += itemPtr->healthBuff();
	actualHealth_ = std::min(actualHealth_ + itemPtr->healing(), maxHealth_);
	attack_ += itemPtr->attackBuff();

	hunger_ = std::max(hunger_ - itemPtr->food(), 0);
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

Action Player::genAction(const Map& map) const
{
    return Wait{};
}

std::string Player::getStringOfItem(size_t i)
{
	return items_[i] ? items_[i]->getString() : "NULL";
}

void Player::increaseHunger()
{
	if(hunger_ < maxHunger_) hunger_++;
	else actualHealth_--;
}

void Player::reset()
{
    hunger_ = 0;
    maxHunger_ = 200;
    attack_ = 5;
    actualHealth_ = 40;
    maxHealth_ = 40;
    pos_ = {-1,-1};
}