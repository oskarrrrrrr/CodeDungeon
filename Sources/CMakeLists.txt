cmake_minimum_required(VERSION 3.10)
project(${CMAKE_PROJECT_NAME}_Sources)
include_directories(.)

file(GLOB ${PROJECT_NAME}src_files  *.cpp *.h)
add_library(${PROJECT_NAME} ${${PROJECT_NAME}src_files}
        MapGenerator/IMapGenerator/IItemGenerator.cpp
        MapGenerator/IMapGenerator/IMapGenerator.cpp
        MapGenerator/IMapGenerator/IMonsterGenerator.cpp
        MapGenerator/IMapGenerator/ITerrainGenerator.cpp

        MapGenerator/HardcodeMapGenerator/HardcodeTerrainGenerator.cpp

        MapGenerator/Action.cpp
        MapGenerator/Creature.cpp
        MapGenerator/Entity.cpp
        MapGenerator/HumanPlayer.cpp
        MapGenerator/Item.cpp
        MapGenerator/Map.cpp
        MapGenerator/Monster.cpp
        MapGenerator/Player.cpp
        MapGenerator/Position.cpp
        MapGenerator/RandomGenerator.cpp
        MapGenerator/Terrain.cpp

        Engine.cpp
        PrintUtils.cpp

        MapGenerator/RandomMapGenerator1/RandomMapGenerator1.cpp
        MapGenerator/BinaryTerrainGenerator/BinaryTerrainGenerator.cpp
        MapGenerator/BinaryTerrainGenerator/BSP.cpp
        MapGenerator/RandomEntitiesGenerator/RandomItemGenerator.cpp
        MapGenerator/RandomEntitiesGenerator/RandomMonsterGenerator.cpp

        MapGenerator/MapGeneratorFactory.h MapGenerator/MapGeneratorFactory.cpp MapGenerator/HardcodeMapGenerator/HardcodeMapGenerator.h MapGenerator/HardcodeMapGenerator/HardcodeMapGenerator.cpp MapGenerator/HardcodeMapGenerator/HardcodeMonsterGenerator.h MapGenerator/HardcodeMapGenerator/HardcodeMonsterGenerator.cpp MapGenerator/HardcodeMapGenerator/HardcodeItemGenerator.h MapGenerator/HardcodeMapGenerator/HardcodeItemGenerator.cpp)
