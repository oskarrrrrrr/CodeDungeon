#ifndef CODEDUNGEON_MONSTER_H
#define CODEDUNGEON_MONSTER_H

#include <MapGenerator/Creature.h>

class Monster : public Creature
{
public:
    Action genAction(Map& map);
};


#endif //CODEDUNGEON_MONSTER_H
