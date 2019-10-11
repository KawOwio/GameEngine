cmake_minimum_required(VERSION 2.6)
project(NIKITAGE)

include_directories(src)

add_library(engine
	src/engine/Core.cpp
)

add_executable(game
	src/game/main.cpp
)


target_link_libraries(game
	SDL2 glew32 opengl32
)

target_link_libraries(game engine)