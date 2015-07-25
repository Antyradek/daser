#include "io_error_exception.h"

using namespace de;
IOErrorException::IOErrorException(string info)
{
    this->info = info;
}

IOErrorException::~IOErrorException()
{
    //dtor
}

const char* IOErrorException::what() const noexcept
{
    return info.c_str();
}
