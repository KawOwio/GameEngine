cmake_minimum_required(VERSION 2.6)
project(NIKITAGE)

include_directories(src)

add_library(rend
	src/rend/Exception.cpp
	src/rend/Context.cpp
	src/rend/Texture.cpp
	src/rend/RenderTexture.cpp
	src/rend/Shader.cpp
	src/rend/Buffer.cpp
	src/rend/Mesh.cpp
	src/rend/Util.cpp
)

if(MSVC)
	target_link_libraries(rend glew32 opengl32)
else()
	target_link_libraries(rend GLEW GL)
endif()

add_library(engine
	src/engine/Camera.cpp
	src/engine/Camera.h
	src/engine/Component.cpp
	src/engine/Component.h
	src/engine/Core.cpp
	src/engine/Core.h
	src/engine/Entity.cpp
	src/engine/Entity.h
	src/engine/Environment.cpp
	src/engine/Environment.h
	src/engine/Geppy.h
	src/engine/Keyboard.cpp
	src/engine/Keyboard.h
	src/engine/Material.cpp
	src/engine/Material.h
	src/engine/Mesh.cpp
	src/engine/Mesh.h
	src/engine/Renderer.cpp
	src/engine/Renderer.h
	src/engine/Resource.h
	src/engine/Resources.cpp
	src/engine/Resources.h
	src/engine/Transform.cpp
	src/engine/Transform.h
	src/engine/Texture.cpp
	src/engine/Texture.h
	src/engine/BoxCollider.cpp
	src/engine/BoxCollider.h
	src/engine/StaticModelCollider.cpp
	src/engine/StaticModelCollider.h
	src/engine/Gui.h
	src/engine/Gui.cpp
	src/engine/Player.h
	src/engine/Player.cpp
)

target_link_libraries(engine SDL2 rend)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game engine)