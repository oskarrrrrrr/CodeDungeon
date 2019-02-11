#ifndef CODEDUNGEON_ENGINE_H
#define CODEDUNGEON_ENGINE_H

#include <chrono>

#include <MapGenerator/IMapGenerator/IMapGenerator.h>

#include <MapGenerator/Map.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/RandomGenerator.h>
#include <MapGenerator/MapGeneratorFactory.h>

#include <memory>
#include <utility>
#include <MapGenerator/HumanPlayer.h>
class Engine
{
public:
    Engine(RandomGenerator randGen)
    : mapGeneratorFactory_(std::make_unique<MapGeneratorFactory>()), randGen_(randGen), player_(std::make_shared<HumanPlayer>())
    {}

    void gameStart();

private:
    std::unique_ptr<MapGeneratorFactory> mapGeneratorFactory_;
    RandomGenerator randGen_;
    PlayerShrdPtr player_;

    int maxFloors = 5;
};


#endif //CODEDUNGEON_ENGINE_H
