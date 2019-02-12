//
// Created by dawidbarzyk on 2/12/19.
//

#ifndef CODEDUNGEON_ENGINESELECTOR_H
#define CODEDUNGEON_ENGINESELECTOR_H

#include <IEngine.h>
#include <memory>
#include <MapGenerator/RandomGenerator.h>

std::unique_ptr<IEngine> pickEngine(int argc, char *argv[], RandomGenerator& randGen);

#endif //CODEDUNGEON_ENGINESELECTOR_H
