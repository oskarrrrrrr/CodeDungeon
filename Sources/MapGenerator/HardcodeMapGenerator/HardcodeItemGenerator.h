//
// Created by dawidbarzyk on 1/29/19.
//

#ifndef CODEDUNGEON_HARDCODEITEMGENERATOR_H
#define CODEDUNGEON_HARDCODEITEMGENERATOR_H

#include <MapGenerator/IMapGenerator/IItemGenerator.h>

class HardcodeItemGenerator : public IItemGenerator
{
    std::list<Item> generate() override;
};
#endif //CODEDUNGEON_HARDCODEITEMGENERATOR_H
