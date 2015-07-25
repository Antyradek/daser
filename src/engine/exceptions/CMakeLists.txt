#Set sources for this library
set(ENGINE_EXCEPTIONS_SRCS graphics_error_exception.cpp glfw_error_exception.cpp io_error_exception.cpp)

#Compile directory as library
add_library(engine_exceptions SHARED ${ENGINE_EXCEPTIONS_SRCS})
