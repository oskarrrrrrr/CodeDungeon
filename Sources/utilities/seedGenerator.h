//
// Created by dawidbarzyk on 2/11/19.
//

#ifndef CODEDUNGEON_SEEDGENERATOR_H
#define CODEDUNGEON_SEEDGENERATOR_H

#include <curses.h>
#include <memory>
#include <iostream>
#include <fstream>
#include <random>

namespace {

uint64_t readSeedFromFile()
{
    uint64_t seedFromFile;
    std::ifstream fileWithSeed("seed_storage");
    bool tmp {fileWithSeed >> seedFromFile};
    fileWithSeed.close();
    if(tmp)
    {
        return seedFromFile;
    }
    return 0;

}

void storeSeedToFile(const int64_t& seed)
{
    std::ofstream fileWithSeed("seed_storage", std::ofstream::trunc);
    fileWithSeed << seed;
    fileWithSeed.close();
}
}  // namespace

uint64_t createSeed(int argc, char *argv[])
{
    uint64_t seed = uint64_t(std::random_device{}()) << 32 | uint64_t(std::random_device{}());
    for(int i = 0; i < argc; i++)
    {
        std::string argument(argv[i]);
        if(argument == "old_seed")
        {
            uint64_t tmp = readSeedFromFile();
            if(tmp) seed = tmp;
        }
    }

    storeSeedToFile(seed);
    return seed;
}

#endif //CODEDUNGEON_SEEDGENERATOR_H
