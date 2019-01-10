#ifndef CODEDUNGEON_IMAPGENERATOR_H
#define CODEDUNGEON_IMAPGENERATOR_H

#include <MapGenerator/IMapGenerator/IItemGenerator.h>
#include <MapGenerator/IMapGenerator/IMonsterGenerator.h>
#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>

#include <MapGenerator/Map.h>
#include <MapGenerator/Seed.h>

class IMapGenerator
{
public:
	Map generate(Seed s);

private:
    IItemGenerator itemGenerator_;
    IMonsterGenerator monsterGenerator_;
    ITerrainGenerator terrainGenerator_;
};


#endif //CODEDUNGEON_IMAPGENERATOR_H
