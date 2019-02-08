#ifndef CODEDUNGEON_IITEMGENERATOR_H
#define CODEDUNGEON_IITEMGENERATOR_H

#include <list>

#include <MapGenerator/Item.h>
#include <MapGenerator/RandomGenerator.h>
#include <MapGenerator/Map.h>


class IItemGenerator
{
public:
    virtual std::list<Item> generate(RandomGenerator& randGen, const Map& map) = 0;
};


#endif //CODEDUNGEON_IITEMGENERATOR_H
