#Set version number and put changed file into binary folder
configure_file (config.h.in "${PROJECT_BINARY_DIR}/config.h")
#Add above file to search path
include_directories("${PROJECT_BINARY_DIR}")

#Add future
SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

set(MAIN_SRCS main.cpp)

#Build engine
add_subdirectory(engine)

#Make sure we can build the project
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

#We need to use GL in external library. I have no idea why, but using them in main.cpp creates linker misses.
add_library(renderer SHARED renderer.cpp)
target_link_libraries(renderer ${GLFW_LIBRARIES})
target_link_libraries(renderer GLEW)

add_executable(daser ${MAIN_SRCS})

#Add engine and rendering functions
target_link_libraries(daser engine)
target_link_libraries(daser renderer)

