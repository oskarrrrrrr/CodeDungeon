cmake_minimum_required(VERSION 3.10)
project(${CMAKE_PROJECT_NAME}_Test)

add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${gmock_SOURCE_DIR}/include)
include_directories(./test_utils)
include_directories(../Sources)

aux_source_directory(./test_cases test_cases)
aux_source_directory(./test_utils test_utils)

add_executable(${PROJECT_NAME} ${test_cases} ${test_utils}
		MapGenerator/TestAction.cpp
		MapGenerator/TestPosition.cpp
)

target_link_libraries(${PROJECT_NAME}
        gtest_main
        gmock_main
        ${CMAKE_PROJECT_NAME}_Sources
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Testing")
set_property(TARGET gtest_main PROPERTY FOLDER "Testing/gtest")
set_property(TARGET gmock_main PROPERTY FOLDER "Testing/gmock")
set_property(TARGET gtest PROPERTY FOLDER "Testing/gtest")
set_property(TARGET gmock PROPERTY FOLDER "Testing/gmock")













