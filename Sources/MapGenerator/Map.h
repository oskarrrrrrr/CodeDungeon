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

	std::list<Monster>& monsters();

	void makeAction(Creature& who, Action what);

	void addTerrain(const Terrain& terrain);
private:
    Terrain terrain_;
    std::list<Monster> monsters_;
    std::list<Item> items_;
};


#endif //CODEDUNGEON_MAP_H
