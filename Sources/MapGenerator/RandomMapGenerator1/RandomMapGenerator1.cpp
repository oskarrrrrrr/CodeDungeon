#include <memory>

#include "RandomMapGenerator1.h"

RandomMapGenerator1::RandomMapGenerator1() :
    IMapGenerator(
        std::make_unique<AgentItemGenerator>(),
        std::make_unique<AgentMonsterGenerator>(),
        std::make_unique<BinaryTerrainGenerator>())
{
}
