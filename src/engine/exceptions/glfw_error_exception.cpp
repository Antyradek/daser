#include "glfw_error_exception.h"
using namespace de;

GLFWErrorException::GLFWErrorException(string info)
{
    this->info = info;
}

GLFWErrorException::~GLFWErrorException()
{
    //dtor
}

const char* GLFWErrorException::what() const noexcept
{
    return info.c_str();
}
