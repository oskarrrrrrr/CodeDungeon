//
// Created by dawidbarzyk on 1/29/19.
//

#include "HardcodeMonsterGenerator.h"

#include <iostream>

std::list<Monster> HardcodeMonsterGenerator::generate(Seed& seed, const Map& map)
{
  std::list<Monster> resultMonsters;

  resultMonsters.emplace_back(Position(4,4), 10, 2);
  resultMonsters.emplace_back(Position(9,4), 15, 1);
  resultMonsters.emplace_back(Position(3,20), 5, 4);

  return resultMonsters;
}
