cmake_minimum_required(VERSION 3.10)
project(${CMAKE_PROJECT_NAME}_Sources)
include_directories(.)

file(GLOB ${PROJECT_NAME}src_files  *.cpp *.h)
add_library(${PROJECT_NAME} ${${PROJECT_NAME}src_files}
        MapGenerator/IMapGenerator/IItemGenerator.cpp
        MapGenerator/IMapGenerator/IMapGenerator.cpp
        MapGenerator/IMapGenerator/IMonsterGenerator.cpp
        MapGenerator/IMapGenerator/ITerrainGenerator.cpp

        MapGenerator/Item.cpp
        MapGenerator/Map.cpp
        MapGenerator/Monster.cpp
        MapGenerator/Terrain.cpp
)

