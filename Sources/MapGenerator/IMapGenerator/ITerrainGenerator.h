#ifndef CODEDUNGEON_ITERRAINGENERATOR_H
#define CODEDUNGEON_ITERRAINGENERATOR_H

#include <MapGenerator/RandomGenerator.h>
#include <MapGenerator/Terrain.h>

class ITerrainGenerator
{
public:
	ITerrainGenerator() = default;

	virtual Terrain generate(RandomGenerator &randGen) = 0;
};


#endif //CODEDUNGEON_ITERRAINGENERATOR_H
