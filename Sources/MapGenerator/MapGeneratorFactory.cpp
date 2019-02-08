//
// Created by dawidbarzyk on 1/29/19.
//

#include "MapGeneratorFactory.h"

/*
std::unique_ptr<IMapGenerator> MapGeneratorFactory::createMapGenerator(HardcodeMapGeneratorTag)
{
    return std::make_unique<IMapGenerator>(HardcodeMapGenerator{});
}
*/

std::unique_ptr<IMapGenerator> MapGeneratorFactory::createMapGenerator(RandomMapGenerator1Tag)
{
    return std::make_unique<IMapGenerator>(RandomMapGenerator1Tag{});
}
