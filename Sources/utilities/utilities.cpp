#include <utilities/utilities.h>

MapGeneratorTag chooseMapGeneratorTag(int argc, char *argv[])
{
    for(int i = 0; i < argc; ++i)
    {
        if(std::string(argv[i]) == "agent_generator")
            return AgentMapGeneratorTag{};
        if(std::string(argv[i]) == "binary_generator")
            return RandomMapGenerator1Tag{};
        if(std::string(argv[i]) == "hardcode_generator")
            return HardcodeMapGeneratorTag{};
    }

    return AgentMapGeneratorTag{};
}
