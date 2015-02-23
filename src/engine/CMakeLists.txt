#Add exceptions
add_subdirectory(exceptions)

#Set sources for this library
set(ENGINE_SRCS game.cpp debug.cpp window.cpp)

#Compile directory as library
add_library(engine SHARED ${ENGINE_SRCS})

#Add exceptions library
target_link_libraries(engine engine_exceptions)
target_link_libraries(engine glfw)


