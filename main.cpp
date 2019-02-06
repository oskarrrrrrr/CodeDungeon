#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>
#include <MapGenerator/HardcodeMapGenerator/HardcodeTerrainGenerator.h>
#include <MapGenerator/Seed.h>
#include <MapGenerator/HumanPlayer.h>

#include <Engine.h>

#include <curses.h>
#include <memory>
#include <iostream>

int initialize()
{
	initscr();

	cbreak();
	keypad(stdscr, TRUE);
	intrflush(stdscr, FALSE);
	noecho();

    timeout(0); // non-blocking read

    curs_set(0);
}

void finalize(int curs)
{
    if (curs >= 0)
        curs_set(curs);
	endwin();
}

int main()
{
	int curs = initialize();

	Engine engine = Engine();
	engine.gameInit(Seed{});
	engine.gameStart();

    finalize(curs);

    return 0;
}
