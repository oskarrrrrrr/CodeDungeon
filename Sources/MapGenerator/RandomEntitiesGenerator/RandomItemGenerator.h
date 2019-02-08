#ifndef CODEDUNGEON_RANDOMITEMGENERATOR1_H
#define CODEDUNGEON_RANDOMITEMGENERATOR1_H

#include <MapGenerator/IMapGenerator/IItemGenerator.h>

class RandomItemGenerator : public IItemGenerator
{
public:
    std::list<Item> generate(RandomGenerator& randGen, const Map& map) override;
};
#endif // CODEDUNGEON_RANDOMITEMGENERATOR1_H
