//
// Created by dawidbarzyk on 1/29/19.
//

#ifndef CODEDUNGEON_HARDCODEMAPGENERATOR_H
#define CODEDUNGEON_HARDCODEMAPGENERATOR_H

#include <MapGenerator/IMapGenerator/IMapGenerator.h>
#include <MapGenerator/HardcodeMapGenerator/HardcodeTerrainGenerator.h>
#include <MapGenerator/HardcodeMapGenerator/HardcodeMonsterGenerator.h>
#include <MapGenerator/HardcodeMapGenerator/HardcodeItemGenerator.h>

struct HardcodeMapGeneratorTag {};
class HardcodeMapGenerator : public IMapGenerator
{
public:
    HardcodeMapGenerator();
};

#endif //CODEDUNGEON_HARDCODEMAPGENERATOR_H
