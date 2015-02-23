#include "graphics_error_exception.h"
using namespace de;

GraphicsErrorException::GraphicsErrorException(string info)
{
    this->info = info;
}

GraphicsErrorException::~GraphicsErrorException()
{
    //dtor
}

const char* GraphicsErrorException::what() const noexcept
{
    return info.c_str();
}

