//
// Created by dawidbarzyk on 1/29/19.
//

#include "MapGeneratorFactory.h"

#include <MapGenerator/HardcodeMapGenerator/HardcodeTerrainGenerator.h>

std::unique_ptr<IMapGenerator> MapGeneratorFactory::createMapGenerator(HardcodeMapGeneratorTag)
{
    return std::make_unique<IMapGenerator>(HardcodeMapGenerator{});
}

std::unique_ptr<IMapGenerator> MapGeneratorFactory::createMapGenerator(AgentMapGeneratorTag)
{
    return std::make_unique<IMapGenerator>(AgentMapGenerator{});
}
