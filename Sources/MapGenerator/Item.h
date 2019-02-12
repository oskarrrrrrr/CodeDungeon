#ifndef CODEDUNGEON_ITEM_H
#define CODEDUNGEON_ITEM_H

#include <string>

#include <MapGenerator/Entity.h>

class Item : public Entity
{
public:
    Item() = delete;
    Item(Position pos, int healingStat, int attack, int health)
    : Entity(pos), healing_(healingStat), attackBuff_(attack), healthBuff_(health), food_(100), type_("    ")
    {
        if (attackBuff_ > 0)
            type_[0] = 'A';
        if (healthBuff_ > 0)
            type_[1] = 'H';
        if (healing_ > 0)
            type_[2] = 'P';
        if (food_ > 0)
            type_[3] = 'F';
    }

    int healing()
    { return healing_; }

    int attackBuff()
    { return attackBuff_; }

    int healthBuff()
    { return healthBuff_; }

    int food()
    { return food_; }

    const static char field = 'I';

    std::string getString();

private:
    int healing_;

    int attackBuff_;
    int healthBuff_;
    int food_;
    std::string type_;
};

#endif //CODEDUNGEON_ITEM_H
