#ifndef CODEDUNGEON_MAP_H
#define CODEDUNGEON_MAP_H

#include <list>


#include <MapGenerator/Item.h>
#include <MapGenerator/Monster.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/Terrain.h>


class Map
{
public:
    Map() = default;

    const std::list<Monster>& monsters() const;
    const PlayerShrdPtr& player() const;

    void makeAction(const Creature& who, Action what);

    void addTerrain(const Terrain& terrain);
    void addPlayer(PlayerShrdPtr player);

private:
    Terrain terrain_;
    std::list<Monster> monsters_;
    std::list<Item> items_;
    PlayerShrdPtr player_;
};


#endif //CODEDUNGEON_MAP_H
