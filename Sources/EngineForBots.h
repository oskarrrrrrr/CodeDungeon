//
// Created by dawidbarzyk on 2/12/19.
//

#ifndef CODEDUNGEON_ENGINEFORBOTS_H
#define CODEDUNGEON_ENGINEFORBOTS_H

#include <chrono>
#include <memory>
#include <utility>

#include <MapGenerator/IMapGenerator/IMapGenerator.h>
#include <MapGenerator/Map.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/RandomGenerator.h>
#include <MapGenerator/MapGeneratorFactory.h>
#include <MapGenerator/BotPlayer.h>

#include "IEngine.h"

class EngineForBots : public IEngine
{
public:
    explicit EngineForBots(RandomGenerator& randGen, int numberOfIter)
            : mapGeneratorFactory_(std::make_unique<MapGeneratorFactory>()), randGen_(randGen), player_(std::make_shared<BotPlayer>()), numberOfIterations_(numberOfIter)
    {}

    void gameStart(MapGeneratorTag tag) override;

private:
    std::unique_ptr<MapGeneratorFactory> mapGeneratorFactory_;
    RandomGenerator& randGen_;
    PlayerShrdPtr player_;
    int numberOfIterations_;

    int maxFloors = 5;
};

#endif //CODEDUNGEON_ENGINEFORBOTS_H
