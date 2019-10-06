cmake_minimum_required(VERSION 2.6)
project(NIKITAGE)

add_executable(game
	src/game/main.cpp
)


target_link_libraries(game
	SDL2 glew32 opengl32
)