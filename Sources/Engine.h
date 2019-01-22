#ifndef CODEDUNGEON_ENGINE_H
#define CODEDUNGEON_ENGINE_H

#include <chrono>

#include <MapGenerator/IMapGenerator/IMapGenerator.h>

#include <MapGenerator/Map.h>
#include <MapGenerator/Player.h>
#include <MapGenerator/Seed.h>

#include <memory>
#include <utility>

class Engine
{
public:
    Engine(std::unique_ptr<IMapGenerator>& gen)
    : gen_(std::move(gen))
    {}

    void gameInit(Seed seed);
    void gameStart();

private:
    std::unique_ptr<IMapGenerator> gen_;
    Seed seed_;
    std::unique_ptr<Player> player_;

    int roundTime = 100;
    int maxFloors = 5;
};


#endif //CODEDUNGEON_ENGINE_H
