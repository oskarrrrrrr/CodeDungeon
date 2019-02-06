#ifndef CODEDUNGEON_ITEM_H
#define CODEDUNGEON_ITEM_H

#include <MapGenerator/Entity.h>

class Item : public Entity
{
public:
    Item(Position pos, int attack, int health)
    : Entity(pos), attackBuff(attack), healthBuff(health)
    {}

    int attackBuff;
    int healthBuff;

    const static char field = 'I';
};

#endif //CODEDUNGEON_ITEM_H
