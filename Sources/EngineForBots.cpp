//
// Created by dawidbarzyk on 2/12/19.
//


#include <thread>
#include <future>
#include <curses.h>

#include "EngineForBots.h"
#include <PrintUtils.h>
#include <utilities/seedGenerator.h>


void askForAction(std::promise<Action> * action, Map * map, std::shared_ptr<Player> player)
{
    action->set_value(player->genAction(*map));
}

void EngineForBots::gameStart(MapGeneratorTag tag)
{
    for (int i = 0; i < numberOfIterations_; i++)
    {
        uint64_t seed = createSeed();
        randGen_ = RandomGenerator{seed};
        player_->reset();

        auto mapCreator = std::visit(*mapGeneratorFactory_, tag);
        // auto mapCreator = mapGeneratorFactory_->createMapGenerator(tag);
        int floor = 0;
        for (; floor < maxFloors && player_->isAllive(); floor++)
        {
            Map map = mapCreator->generateMap(randGen_, player_);
            bool nextFloor = false;
            while(player_->isAllive() && !nextFloor)
            {
                std::promise<Action> m;
                std::future<Action> futureAction = m.get_future();
                std::thread t(askForAction, &m, &map, player_);

                std::future_status st = futureAction.wait_for(std::chrono::milliseconds(10));

                if(st == std::future_status::ready)
                {
                    t.join();
                    map.makeAction(*(player_.get()), futureAction.get());
                }
                else
                {
                    throw std::logic_error("Bot didn't respond in time");
                }

                for (auto& mob : map.monsters())
                {
                    Action action = mob.genAction(map);
                    map.makeAction(mob, action);
                }

                if(player_->position() == map.terrain().stairsLoc())
                    nextFloor = true;

                player_->increaseHunger();
            }
        }
        mvwprintw(stdscr, i, 0, "%d bot on map with seed %llu survived %d floors.", i, seed, floor);
        wrefresh(stdscr);
    }

    mvwaddstr(stdscr, numberOfIterations_, 0, "PRESS BACKSPACE TO QUIT");
    bool heQuit = false;
    while(!heQuit)
    {
        heQuit = tryGettingBackspace();
    }

}