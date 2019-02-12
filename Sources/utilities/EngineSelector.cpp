//
// Created by dawidbarzyk on 2/12/19.
//

#include <EngineForBots.h>
#include <Engine.h>
#include "EngineSelector.h"

std::unique_ptr<IEngine> pickEngine(int argc, char *argv[], RandomGenerator& randGen)
{
    for(int i = 0; i < argc; ++i)
    {
        if(std::string(argv[i]) == "run_bots")
        {
            if(i >= argc - 1)
            {
                throw std::logic_error("Please add number of bots that should play the game after flag `run_bots`");
            }

            return std::make_unique<EngineForBots>(randGen, atoi(argv[i + 1]));
        }
    }
    return std::make_unique<Engine>(randGen);
}