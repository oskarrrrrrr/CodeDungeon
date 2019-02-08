#ifndef CODEDUNGEON_HARDCODETERRAINGENERATOR_H
#define CODEDUNGEON_HARDCODETERRAINGENERATOR_H

#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>

class HardcodeTerrainGenerator : public ITerrainGenerator
{
public:
    HardcodeTerrainGenerator();

	Terrain generate(RandomGenerator randGen) override;
};


#endif //CODEDUNGEON_HARDCODETERRAINGENERATOR_H
