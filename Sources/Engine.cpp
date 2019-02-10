#include <thread>

#include <Engine.h>
#include <PrintUtils.h>

#include <MapGenerator/Action.h>
#include <MapGenerator/HumanPlayer.h>


void Engine::gameInit(RandomGenerator randGen)
{
    player_ = std::make_shared<HumanPlayer>();
    randGen_ = randGen;
}

void Engine::gameStart()
{
    auto mapCreator = mapGeneratorFactory_->createMapGenerator(HardcodeMapGeneratorTag{});
    for (int floor = 0; floor < maxFloors; floor++)
    {
        Map map = mapCreator->generateMap(randGen_, player_);
        bool nextFloor = false;
        while(player_->isAllive() && !nextFloor)
        {
            auto beginTime = std::chrono::high_resolution_clock::now();
            Action m = player_->genAction(map);

//            TODO if (m == goNextFloor)
//            {
//                nextFloor = true;
//                continue;
//            }

            map.makeAction(*(player_.get()), m);
            for (auto& mob : map.monsters())
            {
                Action m = mob.genAction(map);
                map.makeAction(mob, m);
            }

            showGameState(map);

            if(player_->position() == map.terrain().stairsLoc())
                nextFloor = true;
            std::this_thread::sleep_until(beginTime + std::chrono::milliseconds(roundTime));
        }
    }
//    TODO show end screen?
}
