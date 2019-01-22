#include <chrono>
#include <thread>

#include <Engine.h>

#include <MapGenerator/Action.h>
#include <MapGenerator/HumanPlayer.h>

void Engine::gameInit(Seed seed)
{
    player_ = std::make_unique<HumanPlayer>();
    seed_ = seed;
}

void Engine::gameStart()
{
    for (int floor = 0; floor < maxFloors; floor++)
    {
        Map map = gen_->generate(seed_);
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

//            TODO show
            std::this_thread::sleep_until(beginTime + std::chrono::milliseconds(roundTime));
        }
    }
//    TODO show end screen?
}
