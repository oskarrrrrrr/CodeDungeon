#ifndef CODEDUNGEON_IMAPGENERATOR_H
#define CODEDUNGEON_IMAPGENERATOR_H

#include <MapGenerator/IMapGenerator/IItemGenerator.h>
#include <MapGenerator/IMapGenerator/IMonsterGenerator.h>
#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>

#include <MapGenerator/Map.h>
#include <MapGenerator/Seed.h>

#include <memory>


class IMapGenerator
{
public:
	Map generate(Seed& s);

private:
  std::unique_ptr<IItemGenerator> itemGenerator_;
  std::unique_ptr<IMonsterGenerator> monsterGenerator_;
  std::unique_ptr<ITerrainGenerator> terrainGenerator_;
};


#endif //CODEDUNGEON_IMAPGENERATOR_H
