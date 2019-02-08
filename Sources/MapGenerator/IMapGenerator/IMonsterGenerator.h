#ifndef CODEDUNGEON_IMONSTERGENERATOR_H
#define CODEDUNGEON_IMONSTERGENERATOR_H

#include <list>

#include <MapGenerator/Monster.h>
#include <MapGenerator/RandomGenerator.h>

class IMonsterGenerator
{
public:
    virtual std::list<Monster> generate(RandomGenerator& randGen, const Map& map) = 0;
};


#endif //CODEDUNGEON_IMONSTERGENERATOR_H
