cmake_minimum_required(VERSION 3.20)

project(POSTED_Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME POSTED_Engine)


add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
	PRIVATE
		src/main.cpp
	PUBLIC
		"engine/Log.h" 
		"engine/Log.cpp" 
		"engine/PostedEngine.h"
		"engine/PostedEngine.cpp")