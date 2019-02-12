cmake_minimum_required(VERSION 3.2)
project(CodeDungeon)
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu++17)
    add_definitions(-D_stricmp=stricmp)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17 -pg")
set_property( GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB src_files  *.cpp *.h)

set(testDataPath ${CMAKE_CURRENT_SOURCE_DIR}/Tests)
message(Test data path:  ${testDataPath})
add_definitions( -DTEST_DATA_PATH="${testDataPath}")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_subdirectory(Tests)
add_subdirectory(Sources)
include_directories(Sources)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_Sources)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CURSES_LIBRARIES})
