#ifndef CODEDUNGEON_CREATURE_H
#define CODEDUNGEON_CREATURE_H

class Map;

#include <MapGenerator/Action.h>
#include <MapGenerator/Entity.h>

class Creature : public Entity
{
public:
    Creature(Position pos, int health, int attack)
    : Entity(pos),
      maxHealth_(health),
      actualHealth_(health),
      attack_(attack)
    {}

    bool isAllive();

    virtual Action genAction(Map& map) = 0;

private:
    int maxHealth_;
    int actualHealth_;
    int attack_;
};

#endif //CODEDUNGEON_CREATURE_H
