#include <MapGenerator/RandomGenerator.h>

#include <Engine.h>

#include <utilities/seedGenerator.h>
#include <utilities/outputinit.h>
#include <utilities/EngineSelector.h>


int main(int argc, char *argv[])
{
  	int curs = initialize();

	RandomGenerator randGen{createSeed(argc, argv)};

	std::unique_ptr<IEngine> engine = pickEngine(argc, argv, randGen);

	engine->gameStart();

    finalize(curs);

    return 0;
}
