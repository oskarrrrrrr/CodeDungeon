#ifndef CODEDUNGEON_AGENTTERRAINGENERATOR_H
#define CODEDUNGEON_AGENTTERRAINGENERATOR_H

#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>

class AgentTerrainGenerator : public ITerrainGenerator
{
public:
    AgentTerrainGenerator();

    Terrain generate(RandomGenerator &randGen) override;
};

#endif //CODEDUNGEON_AGENTTERRAINGENERATOR_H
