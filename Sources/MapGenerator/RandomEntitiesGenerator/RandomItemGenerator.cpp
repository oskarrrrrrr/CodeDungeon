#include "RandomItemGenerator1.h"

std::list<Item> RandomItemGenerator::generate(RandomGenerator& randGen, const Map& map)
{
    std::list<Item> resultItems;

    resultItems.emplace_back(Position(2,4), 3, 3);
    resultItems.emplace_back(Position(10,5), 4, 4);
    resultItems.emplace_back(Position(7,26), 5, 5);

    return resultItems;
}
