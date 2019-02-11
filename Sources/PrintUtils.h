#ifndef CODEDUNGEON_PRINTUTILS_H
#define CODEDUNGEON_PRINTUTILS_H

#include <MapGenerator/Map.h>

void showGameState(const Map& map);
void showGameEnd(int floor);
bool tryGettingBackspace();

#endif //CODEDUNGEON_PRINTUTILS_H
