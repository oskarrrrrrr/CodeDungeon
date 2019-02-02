#ifndef CODEDUNGEON_PLAYER_H
#define CODEDUNGEON_PLAYER_H

#include <memory>

#include <MapGenerator/Action.h>
#include <MapGenerator/Creature.h>

class Player : public Creature
{
public:
    Player()
    : Creature({-1, -1}, 40, 5) //example values
    {}

    Action genAction(Map& map);
};

using PlayerShrdPtr = std::shared_ptr<Player>;
#endif //CODEDUNGEON_PLAYER_H
