#include <MapGenerator/BinaryTerrainGenerator/BinaryTerrainGenerator.h>

BinaryTerrainGenerator::BinaryTerrainGenerator() :
    ITerrainGenerator{}
{}

Terrain BinaryTerrainGenerator::generate(RandomGenerator randGen)
{
    Terrain t(30, 30);

    t.addRoom({1, 1}, 4, 5);
    t.addRoom({9, 3}, 7, 8);
    t.addCorridor({5, 4}, 4, false);

    t.addRoom({2, 20}, 8, 7);
    t.addRoom({1, 10}, 4, 7);
    t.addCorridor({3, 17}, 3, true);
    t.addRoom({15, 18}, 3, 7);
    t.addCorridor({10, 23}, 5, false);

    t.addCorridor({6, 4}, 12, true);
    t.addCorridor({6, 16}, 6, false);
    t.addCorridor({12, 16}, 8, true);

    t.setSpawn({2, 12});
    t.setStairs({13, 7});

    return t;
}
