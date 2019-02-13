#include <MapGenerator/RandomGenerator.h>

#include <Engine.h>

#include <utilities/seedGenerator.h>
#include <utilities/outputinit.h>
#include <utilities/EngineSelector.h>
#include <utilities/utilities.h>


int main(int argc, char *argv[])
{
  	int curs = initialize();

	RandomGenerator randGen{generateOrReadFromFileSeed(argc, argv)};

	std::unique_ptr<IEngine> engine = pickEngine(argc, argv, randGen);

	MapGeneratorTag tag = chooseMapGeneratorTag(argc, argv);

	engine->gameStart(tag);

    finalize(curs);

    return 0;
}
