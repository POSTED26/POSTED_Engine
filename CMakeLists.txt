cmake_minimum_required(VERSION 3.20)

project(POSTED_Engine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME POSTED_Engine)

# change to new format
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_INSTALL OFF CACHE BOOL "GLFW lib only")

add_subdirectory("external/GLFW")

add_custom_target(CopyResources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/Resources"
    "${CMAKE_BINARY_DIR}/Resources"
)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
	PRIVATE
		src/main.cpp
	PUBLIC
		"engine/Log.h" 
		"engine/Log.cpp" 
		"engine/PostedEngine.h"
		"engine/PostedEngine.cpp" 
		"Window/Window.h" 
		"Window/Window.cpp" 
		"Renderer/Renderer.h"
		"Renderer/Renderer.cpp"
		"Renderer/Shader.h"
		"Renderer/Shader.cpp"
		"Renderer/ShaderLibrary.h"
		"Renderer/ShaderLibrary.cpp"
		"Renderer/VertexBuffer.h"
		"Renderer/VertexBuffer.cpp"
		"Renderer/VertexLayout.h"
		"Renderer/VertexLayout.cpp"
		"Renderer/IndexBuffer.h"
		"Renderer/IndexBuffer.cpp"
		"Renderer/VertexArray.h"
		"Renderer/VertexArray.cpp"
		"Renderer/Texture.h"
		"Renderer/Texture.cpp"
		"external/GLAD/src/gl.c"
		"Math/Vec2.h"
		"Math/Vec2.cpp"
		"Math/Vec3.h"
		"Math/Vec3.cpp"
		"Math/Vec4.h"
		"Math/Vec4.cpp"
		"Math/Mat4.h"
		"Math/Mat4.cpp"
		"Renderer/Camera.h"
		"Renderer/Camera.cpp"
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		glfw
)

target_include_directories(${PROJECT_NAME}
	PRIVATE
		external/GLAD/include
)