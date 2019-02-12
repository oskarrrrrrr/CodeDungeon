#include "IMapGenerator.h"


Map IMapGenerator::generateMap(RandomGenerator& randGen, PlayerShrdPtr player)
{
    Map m = Map();

    auto terrain = terrainGenerator_->generate(randGen);
    m.addTerrain(terrain);

    player->setPosition(terrain.spawnLoc());
    m.addPlayer(player);

    auto items = itemGenerator_->generate(randGen, m);
    m.addItems(items);

    auto monsters = monsterGenerator_->generate(randGen, m);
    m.addMonsters(monsters);

    m.updateMaxStats();
    return m;
}
