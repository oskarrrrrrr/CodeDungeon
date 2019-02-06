#include "IMapGenerator.h"


Map IMapGenerator::generateMap(Seed& s, PlayerShrdPtr player)
{
    Map m = Map();

    auto terrain = terrainGenerator_->generate(s);
    m.addTerrain(terrain);

    // auto items = itemGenerator_->generate(s, m);
    // m.addItems(items);

    // auto monsters = monsterGenerator_->generate(s, m);
    // m.addMonsters(monsters);

    player->setPosition(terrain.spawnLoc());
    m.addPlayer(player);

    return m;
}
