#ifndef CODEDUNGEON_CREATURE_H
#define CODEDUNGEON_CREATURE_H

class Map;

#include <MapGenerator/Action.h>

class Creature
{
public:
	Action genAction(Map& map);

};

#endif //CODEDUNGEON_CREATURE_H
