#include <MapGenerator/BinaryTerrainGenerator/BinaryTerrainGenerator.h>
#include <MapGenerator/BinaryTerrainGenerator/BSP.h>

const int TERRAIN_HEIGHT = 40;
const int TERRAIN_WIDTH = 150;

BinaryTerrainGenerator::BinaryTerrainGenerator() :
    ITerrainGenerator{}
{}

Terrain BinaryTerrainGenerator::generate(RandomGenerator& randGen)
{
    BSP bsp_tree({0,0}, {TERRAIN_HEIGHT-1, TERRAIN_WIDTH - 1});
    bsp_tree.split(randGen);

    Terrain t(TERRAIN_HEIGHT, TERRAIN_WIDTH);

    bsp_tree.draw_rooms(t);
    bsp_tree.add_corridors(t);
    bsp_tree.add_spawn(t, randGen);
    bsp_tree.add_stairs(t, randGen);

    return t;
}
