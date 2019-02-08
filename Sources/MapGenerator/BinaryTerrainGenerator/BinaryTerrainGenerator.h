#ifndef CODEDUNGEON_BINARYTERRAINGENERATOR_H
#define CODEDUNGEON_BINARYTERRAINGENERATOR_H

#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>

class BinaryTerrainGenerator : public ITerrainGenerator
{
public:
    BinaryTerrainGenerator();

	Terrain generate(RandomGenerator randGen) override;
};


#endif // CODEDUNGEON_BINARYTERRAINGENERATOR_H
