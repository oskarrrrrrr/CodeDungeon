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
	std::list<Monster>& monsters();
	Player& player();

	void makeMove(Move m);

private:
    Terrain terrain_;
    std::list<Monster> monsters_;
    std::list<Item> items_;
    Player player_;
};


#endif //CODEDUNGEON_MAP_H
