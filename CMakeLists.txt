cmake_minimum_required(VERSION 2.6)
project(NIKITAGE)

include_directories(src)

add_library(engine
	src/engine/Core.cpp
	src/engine/Core.h
	src/engine/Component.cpp
	src/engine/Component.h
	src/engine/Entity.cpp
	src/engine/Entity.h
	src/engine/Environment.cpp
	src/engine/Environment.h
	src/engine/Keyboard.cpp
	src/engine/Keyboard.h
)

add_executable(game
	src/game/main.cpp
)


target_link_libraries(game
	SDL2 glew32 opengl32
)

target_link_libraries(game engine)