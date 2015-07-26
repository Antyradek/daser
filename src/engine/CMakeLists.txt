#Add exceptions
add_subdirectory(exceptions)

#Set sources for this library
set(ENGINE_SRCS game.cpp debug.cpp window.cpp input.cpp time.cpp shader.cpp)

#Make sure we can build engine
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

#Compile directory as library
add_library(engine SHARED ${ENGINE_SRCS})

include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(engine ${GLFW_LIBRARIES})
target_link_libraries(engine engine_exceptions)
target_link_libraries(engine GLEW)
target_link_libraries(engine GL)



