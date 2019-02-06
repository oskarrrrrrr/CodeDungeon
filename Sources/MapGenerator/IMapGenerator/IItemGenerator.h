#ifndef CODEDUNGEON_IITEMGENERATOR_H
#define CODEDUNGEON_IITEMGENERATOR_H

#include <list>

#include <MapGenerator/Item.h>


class IItemGenerator
{
    virtual std::list<Item> generate();
};


#endif //CODEDUNGEON_IITEMGENERATOR_H
