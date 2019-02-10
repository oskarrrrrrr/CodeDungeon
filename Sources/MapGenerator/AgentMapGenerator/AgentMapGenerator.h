#ifndef CODEDUNGEON_AGENTMAPGENERATOR_H
#define CODEDUNGEON_AGENTMAPGENERATOR_H

#include <MapGenerator/IMapGenerator/IMapGenerator.h>

#include <MapGenerator/AgentMapGenerator/AgentItemGenerator.h>
#include <MapGenerator/AgentMapGenerator/AgentMonsterGenerator.h>
#include <MapGenerator/AgentMapGenerator/AgentTerrainGenerator.h>

struct AgentMapGeneratorTag {};
class AgentMapGenerator : public IMapGenerator
{
public:
    AgentMapGenerator();
};

#endif //CODEDUNGEON_AGENTMAPGENERATOR_H
