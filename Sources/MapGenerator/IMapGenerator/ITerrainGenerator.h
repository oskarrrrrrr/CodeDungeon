#ifndef CODEDUNGEON_ITERRAINGENERATOR_H
#define CODEDUNGEON_ITERRAINGENERATOR_H

#include <MapGenerator/Seed.h>
#include <MapGenerator/Terrain.h>

class ITerrainGenerator
{
public:
	ITerrainGenerator() = default;

	virtual Terrain generate(Seed s) = 0;
};


#endif //CODEDUNGEON_ITERRAINGENERATOR_H
