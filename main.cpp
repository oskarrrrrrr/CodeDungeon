#include <MapGenerator/RandomGenerator.h>

#include <Engine.h>

#include <utilities/seedGenerator.h>
#include <utilities/outputinit.h>


int main(int argc, char *argv[])
{
  	int curs = initialize();

	RandomGenerator randGen{createSeed(argc, argv)};

	Engine engine = Engine(randGen);

	engine.gameStart();

    finalize(curs);

    return 0;
}
