#ifndef CODEDUNGEON_ITEM_H
#define CODEDUNGEON_ITEM_H

#include <string>

#include <MapGenerator/Entity.h>

class Item : public Entity
{
public:
    Item(Position pos, int healingStat, int attack, int health)
    : Entity(pos), healing(healingStat), attackBuff(attack), healthBuff(health), type("    ")
    {
        if (attackBuff > 0 || healthBuff > 0)
            type[0] = 'B';
        if (healing > 0)
            type[1] = 'P';
    }

    int healing;
    int attackBuff;
    int healthBuff;

    const static char field = 'I';

    std::string getString();

private:
    std::string type;
};

#endif //CODEDUNGEON_ITEM_H
