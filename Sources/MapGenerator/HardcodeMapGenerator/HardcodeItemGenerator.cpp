//
// Created by dawidbarzyk on 1/29/19.
//

#include "HardcodeItemGenerator.h"

std::list<Item> HardcodeItemGenerator::generate()
{
    std::list<Item> resultItems;

    resultItems.emplace_back(Position(2,3), 2, 3);
    resultItems.emplace_back(Position(10,4), 1, 4);
    resultItems.emplace_back(Position(7,25), 4, 0);

    return resultItems;
}