#include <MapGenerator/AgentMapGenerator/AgentTerrainGenerator.h>

AgentTerrainGenerator::AgentTerrainGenerator() :
    ITerrainGenerator{}
{}

Terrain AgentTerrainGenerator::generate(RandomGenerator randGen)
{
    Terrain t(4, 4);
    t.setSpawn({1, 1});
    t.setStairs({2, 2});
    return t;
}
