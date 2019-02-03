#include <MapGenerator/Map.h>


const std::list<Monster>& Map::monsters() const
{
    return monsters_;
}

const PlayerShrdPtr& Map::player() const
{
    return player_;
}



void Map::addPlayer(PlayerShrdPtr player)
{
    player_ = player;
}
