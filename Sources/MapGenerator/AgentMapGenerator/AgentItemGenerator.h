#ifndef CODEDUNGEON_AGENTITEMGENERATOR_H
#define CODEDUNGEON_AGENTITEMGENERATOR_H

#include <MapGenerator/IMapGenerator/IItemGenerator.h>

class AgentItemGenerator : public IItemGenerator
{
public:
    std::list<Item> generate(RandomGenerator& randGen, const Map& map) override;
};

#endif //CODEDUNGEON_AGENTITEMGENERATOR_H
