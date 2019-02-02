//
// Created by dawidbarzyk on 1/29/19.
//

#include <memory>

#include "HardcodeMapGenerator.h"

HardcodeMapGenerator::HardcodeMapGenerator() :
    IMapGenerator(
        std::make_unique<HardcodeItemGenerator>(),
        std::make_unique<HardcodeMonsterGenerator>(),
        std::make_unique<HardcodeTerrainGenerator>())
{
}

