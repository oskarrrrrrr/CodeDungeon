#ifndef CODEDUNGEON_MONSTER_H
#define CODEDUNGEON_MONSTER_H

#include <MapGenerator/Creature.h>

class Monster : public Creature
{
public:
    Monster(Position pos, int health, int attack)
    : Creature(pos, health, attack)
    {}

    Action genAction(Map& map) const;
};


#endif //CODEDUNGEON_MONSTER_H
