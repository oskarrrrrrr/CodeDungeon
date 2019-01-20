#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>
#include <MapGenerator/HardcodeMapGenerator/HardcodeTerrainGenerator.h>
#include <MapGenerator/Seed.h>

#include <memory>
#include <iostream>

int main()
{
	std::unique_ptr<ITerrainGenerator> terrain_generator(new HardcodeTerrainGenerator);
	std::unique_ptr<Seed> s(new Seed);
	Terrain terrain = terrain_generator.get()->generate(*(s.get()));
	std::cout << terrain.toString();
  return 0;
}
