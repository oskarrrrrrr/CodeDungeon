#ifndef CODEDUNGEON_RANDOMMAPGENERATOR1_H
#define CODEDUNGEON_RANDOMMAPGENERATOR1_H

#include <MapGenerator/IMapGenerator/IMapGenerator.h>
#include <MapGenerator/BinaryTerrainGenerator/BinaryTerrainGenerator.h>
#include <MapGenerator/AgentMapGenerator/AgentItemGenerator.h>
#include <MapGenerator/AgentMapGenerator/AgentMonsterGenerator.h>


struct RandomMapGenerator1Tag {};
class RandomMapGenerator1 : public IMapGenerator
{
public:
    RandomMapGenerator1();
};

#endif // CODEDUNGEON_RANDOMMAPGENERATOR1_H
