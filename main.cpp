#include <curses.h>
#include <memory>
#include <iostream>

#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>
#include <MapGenerator/RandomGenerator.h>
#include <MapGenerator/HumanPlayer.h>

#include <Engine.h>

#include <utilities/seedGenerator.h>

int initialize()
{
	initscr();

	cbreak();
 	keypad(stdscr, TRUE);
	intrflush(stdscr, FALSE);
	noecho();

    timeout(-1); // non-blocking read

    return curs_set(0);
}

void finalize(int curs)
{
    if (curs >= 0)
        curs_set(curs);
	endwin();
}



int main(int argc, char *argv[])
{
  	int curs = initialize();

	RandomGenerator randGen{createSeed(argc, argv)};

	Engine engine = Engine(randGen);

	engine.gameStart();

    finalize(curs);

    return 0;
}
