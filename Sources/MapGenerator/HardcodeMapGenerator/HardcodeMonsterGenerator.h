//
// Created by dawidbarzyk on 1/29/19.
//

#ifndef CODEDUNGEON_HARDCODEMONSTERGENERATOR_H
#define CODEDUNGEON_HARDCODEMONSTERGENERATOR_H

#include <MapGenerator/IMapGenerator/IMonsterGenerator.h>

class HardcodeMonsterGenerator : public IMonsterGenerator
{
public:
  std::list<Monster> generate(Seed& seed, const Map& map);
};
#endif //CODEDUNGEON_HARDCODEMONSTERGENERATOR_H
