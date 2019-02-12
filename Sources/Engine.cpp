#include <thread>

#include <Engine.h>
#include <PrintUtils.h>

#include <MapGenerator/Action.h>
#include <MapGenerator/HumanPlayer.h>

void Engine::gameStart()
{
    auto mapCreator = mapGeneratorFactory_->createMapGenerator(AgentMapGeneratorTag{});
    int floor = 0;
    for (; floor < maxFloors && player_->isAllive(); floor++)
    {
        Map map = mapCreator->generateMap(randGen_, player_);
        showGameState(map);
        bool nextFloor = false;
        while(player_->isAllive() && !nextFloor)
        {
            Action m = player_->genAction(map);

            map.makeAction(*(player_.get()), m);
            for (auto& mob : map.monsters())
            {
                Action m = mob.genAction(map);
                map.makeAction(mob, m);
            }

            showGameState(map);

            if(player_->position() == map.terrain().stairsLoc())
                nextFloor = true;
        }
    }

    showGameEnd(floor);
    bool heQuit = false;
    while(!heQuit)
    {
        heQuit = tryGettingBackspace();
    }
}


