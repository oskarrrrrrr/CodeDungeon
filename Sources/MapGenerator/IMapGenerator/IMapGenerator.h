#ifndef CODEDUNGEON_IMAPGENERATOR_H
#define CODEDUNGEON_IMAPGENERATOR_H

#include <MapGenerator/IMapGenerator/IItemGenerator.h>
#include <MapGenerator/IMapGenerator/IMonsterGenerator.h>
#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>

class IMapGenerator
{

    IItemGenerator itemGenerator_;
    IMonsterGenerator monsterGenerator_;
    ITerrainGenerator terrainGenerator_;
};


#endif //CODEDUNGEON_IMAPGENERATOR_H
