#include <memory>

#include "RandomMapGenerator1.h"

RandomMapGenerator1::RandomMapGenerator1() :
    IMapGenerator(
        std::make_unique<RandomItemGenerator>(),
        std::make_unique<RandomMonsterGenerator>(),
        std::make_unique<BinaryTerrainGenerator>())
{
}
