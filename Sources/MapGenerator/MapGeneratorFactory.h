//
// Created by dawidbarzyk on 1/29/19.
//

#ifndef CODEDUNGEON_MAPGENERATORFACTORY_H
#define CODEDUNGEON_MAPGENERATORFACTORY_H

#include <memory>

#include <MapGenerator/IMapGenerator/IMapGenerator.h>

#include <MapGenerator/AgentMapGenerator/AgentMapGenerator.h>
#include <MapGenerator/HardcodeMapGenerator/HardcodeMapGenerator.h>


class MapGeneratorFactory
{
public:
    std::unique_ptr<IMapGenerator> createMapGenerator(HardcodeMapGeneratorTag);
    std::unique_ptr<IMapGenerator> createMapGenerator(AgentMapGeneratorTag);
};
#endif //CODEDUNGEON_MAPGENERATORFACTORY_H
