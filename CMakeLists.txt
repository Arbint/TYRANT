cmake_minimum_required(VERSION 3.19.4)
project(FlappyBird)

file(GLOB_RECURSE FlappyBirdSrcList
	FlappyBird/src/*.h
	FlappyBird/src/*.cpp
)

add_executable(${PROJECT_NAME} ${FlappyBirdSrcList})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
add_subdirectory(TYRANT)
target_link_libraries(${PROJECT_NAME} TYRANT)
target_include_directories(${PROJECT_NAME} PUBLIC TYRANT/include)