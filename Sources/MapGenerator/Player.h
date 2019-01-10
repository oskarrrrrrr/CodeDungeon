#ifndef CODEDUNGEON_PLAYER_H
#define CODEDUNGEON_PLAYER_H

#include <MapGenerator/Creature.h>
#include <MapGenerator/Move.h>

class Player : public Creature
{
public:
	bool isAllive();

private:
	int health;
};


#endif //CODEDUNGEON_PLAYER_H
