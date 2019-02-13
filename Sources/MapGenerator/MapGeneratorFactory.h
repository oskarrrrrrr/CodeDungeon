//
// Created by dawidbarzyk on 1/29/19.
//

#ifndef CODEDUNGEON_MAPGENERATORFACTORY_H
#define CODEDUNGEON_MAPGENERATORFACTORY_H

#include <memory>

#include <MapGenerator/IMapGenerator/IMapGenerator.h>

#include <MapGenerator/AgentMapGenerator/AgentMapGenerator.h>
#include <MapGenerator/HardcodeMapGenerator/HardcodeMapGenerator.h>
#include <MapGenerator/RandomMapGenerator1/RandomMapGenerator1.h>

using MapGeneratorTag = std::variant<HardcodeMapGeneratorTag, AgentMapGeneratorTag, RandomMapGenerator1Tag>;

class MapGeneratorFactory
{
public:
    std::unique_ptr<IMapGenerator> operator()(HardcodeMapGeneratorTag);
    std::unique_ptr<IMapGenerator> operator()(AgentMapGeneratorTag);
    std::unique_ptr<IMapGenerator> operator()(RandomMapGenerator1Tag);
};
#endif //CODEDUNGEON_MAPGENERATORFACTORY_H
