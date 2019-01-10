#ifndef CODEDUNGEON_CREATURE_H
#define CODEDUNGEON_CREATURE_H

class Map;

#include <MapGenerator/Move.h>

class Creature
{
public:
	Move genMove(Map& map);

};

#endif //CODEDUNGEON_CREATURE_H
