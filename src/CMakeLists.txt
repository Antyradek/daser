#Set version number and put changed file into binary folder
configure_file (config.h.in "${PROJECT_BINARY_DIR}/config.h")
#Add above file to search path
include_directories("${PROJECT_BINARY_DIR}")

#Add future
SET(CMAKE_CXX_FLAGS "-std=c++11")

#Build engine
add_subdirectory(engine)

set(MAIN_SRCS main.cpp input_listener.cpp)

add_executable(daser ${MAIN_SRCS})

#Add engine to build
target_link_libraries(daser engine)
