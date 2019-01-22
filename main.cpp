#include <MapGenerator/IMapGenerator/ITerrainGenerator.h>
#include <MapGenerator/HardcodeMapGenerator/HardcodeTerrainGenerator.h>
#include <MapGenerator/Seed.h>

#include <curses.h>
#include <memory>
#include <iostream>

void initialize()
{
	initscr();

	cbreak();
	keypad(stdscr, TRUE);
	intrflush( stdscr, FALSE );
	noecho();
	timeout(0); // non-blocking read
}

void finalize()
{
	endwin();
}

int main()
{
	initialize();

	std::unique_ptr<ITerrainGenerator> terrain_generator(new HardcodeTerrainGenerator);
	std::unique_ptr<Seed> s(new Seed);
	Terrain terrain = terrain_generator.get()->generate(*(s.get()));

    waddstr( stdscr, const_cast<char*>(terrain.toString().c_str()) );

    wmove( stdscr, 22, 3 );
    waddstr( stdscr, "Press any key to exit" );
    timeout(-1); // make blocking again
    wgetch(stdscr);

    finalize();

    return 0;
}
