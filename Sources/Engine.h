#ifndef CODEDUNGEON_ENGINE_H
#define CODEDUNGEON_ENGINE_H

#include <chrono>

#include <MapGenerator/IMapGenerator/IMapGenerator.h>

#include <MapGenerator/Map.h>
#include <MapGenerator/Seed.h>

class Engine
{
public:
    Engine(IMapGenerator& gen)
    : gen_(gen)
    {}

    void gameInit(Seed seed);
    void gameStart();

private:
    IMapGenerator gen_;
    Seed seed_;
    Player player_;

    int roundTime = 20;
    int maxFloors = 5;
};


#endif //CODEDUNGEON_ENGINE_H
