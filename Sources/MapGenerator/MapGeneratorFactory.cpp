//
// Created by dawidbarzyk on 1/29/19.
//

#include "MapGeneratorFactory.h"

std::unique_ptr<IMapGenerator> MapGeneratorFactory::operator()(HardcodeMapGeneratorTag)
{
    return std::make_unique<IMapGenerator>(HardcodeMapGenerator{});
}

std::unique_ptr<IMapGenerator> MapGeneratorFactory::operator()(RandomMapGenerator1Tag)
{
    return std::make_unique<IMapGenerator>(RandomMapGenerator1{});
}

std::unique_ptr<IMapGenerator> MapGeneratorFactory::operator()(AgentMapGeneratorTag)
{
    return std::make_unique<IMapGenerator>(AgentMapGenerator{});
}
