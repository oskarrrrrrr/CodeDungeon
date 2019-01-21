#ifndef CODEDUNGEON_ITEM_H
#define CODEDUNGEON_ITEM_H

#include <MapGenerator/Entity.h>

class Item : public Entity
{
    Item(Position pos)
    : Entity(pos)
    {}
};

#endif //CODEDUNGEON_ITEM_H
