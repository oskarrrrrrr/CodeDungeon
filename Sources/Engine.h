#ifndef CODEDUNGEON_ENGINE_H
#define CODEDUNGEON_ENGINE_H

#include <chrono>
#include <memory>
#include <utility>

#include <MapGenerator/IMapGenerator/IMapGenerator.h>
#include <MapGenerator/Map.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/RandomGenerator.h>
#include <MapGenerator/MapGeneratorFactory.h>
#include <MapGenerator/HumanPlayer.h>

#include "IEngine.h"

class Engine : public IEngine
{
public:
    explicit Engine(RandomGenerator& randGen)
    : mapGeneratorFactory_(std::make_unique<MapGeneratorFactory>()), randGen_(randGen), player_(std::make_shared<HumanPlayer>())
    {}

    void gameStart(MapGeneratorTag tag) override;

private:
    std::unique_ptr<MapGeneratorFactory> mapGeneratorFactory_;
    RandomGenerator& randGen_;
    PlayerShrdPtr player_;

    int maxFloors = 5;
};


#endif //CODEDUNGEON_ENGINE_H
