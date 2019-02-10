#include <memory>

#include <MapGenerator/AgentMapGenerator/AgentMapGenerator.h>

AgentMapGenerator::AgentMapGenerator() :
    IMapGenerator(
        std::make_unique<AgentItemGenerator>(),
        std::make_unique<AgentMonsterGenerator>(),
        std::make_unique<AgentTerrainGenerator>())
{
}

