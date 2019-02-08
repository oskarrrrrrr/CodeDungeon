#ifndef CODEDUNGEON_MAP_H
#define CODEDUNGEON_MAP_H

#include <list>
#include <vector>
#include <memory>


#include <MapGenerator/Item.h>
#include <MapGenerator/Monster.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/Terrain.h>


class Map
{
public:
    Map() = default;

    const std::list<std::unique_ptr<Item>>& items() const;
    const std::list<Monster>& monsters() const;
    const PlayerShrdPtr& player() const;
    const Terrain& terrain() const;

    void addItems(const std::list<Item>& items);
    void addMonsters(const std::list<Monster>& monsters);
    void addPlayer(PlayerShrdPtr player);
    void addTerrain(const Terrain& terrain);

    auto getMonsterOnPosition(const Position& pos);
    auto getItemOnPosition(const Position& pos);

    void makeAction(const Creature& who, Action what);

private:
    void makeAction_(Creature& who, Action what);

    Terrain terrain_;
    std::list<Monster> monsters_;
    std::list<std::unique_ptr<Item>> items_;
    PlayerShrdPtr player_;
};


#endif //CODEDUNGEON_MAP_H
