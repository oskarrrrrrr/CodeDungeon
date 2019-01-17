#ifndef CODEDUNGEON_HARDCODETERRAINGENERATOR_H
#define CODEDUNGEON_HARDCODETERRAINGENERATOR_H

#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>

class HardcodeTerrainGenerator : public ITerrainGenerator
{
public:
	Terrain generate(Seed s);
};


#endif //CODEDUNGEON_HARDCODETERRAINGENERATOR_H
