#ifndef CODEDUNGEON_ENGINE_H
#define CODEDUNGEON_ENGINE_H

#include <chrono>

#include <MapGenerator/IMapGenerator/IMapGenerator.h>

#include <MapGenerator/Map.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/Seed.h>
#include <MapGenerator/MapGeneratorFactory.h>

#include <memory>
#include <utility>

class Engine
{
public:
    Engine() = default;

    void gameInit(Seed seed);
    void gameStart();

private:
    std::unique_ptr<MapGeneratorFactory> mapGeneratorFactory_;
    Seed seed_;
    PlayerShrdPtr player_;

    int roundTime = 100;
    int maxFloors = 5;
};


#endif //CODEDUNGEON_ENGINE_H
