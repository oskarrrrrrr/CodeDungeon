//
// Created by dawidbarzyk on 1/29/19.
//

#ifndef CODEDUNGEON_MAPGENERATORFACTORY_H
#define CODEDUNGEON_MAPGENERATORFACTORY_H

#include <MapGenerator/IMapGenerator/IMapGenerator.h>

#include <memory>
#include <MapGenerator/HardcodeMapGenerator/HardcodeMapGenerator.h>
#include <MapGenerator/RandomMapGenerator1/RandomMapGenerator1.h>


class MapGeneratorFactory
{
public:
//    std::unique_ptr<IMapGenerator> createMapGenerator(HardcodeMapGeneratorTag);
    std::unique_ptr<IMapGenerator> createMapGenerator(RandomMapGenerator1Tag);
};
#endif //CODEDUNGEON_MAPGENERATORFACTORY_H
