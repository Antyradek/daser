#include "time.h"
using namespace de;

Time::Time()
{
    //ctor
}

Time::~Time()
{
    //dtor
}

Time& Time::getInstance()
{
    static Time time;
    return time;
}

float Time::getTime() const
{
    return glfwGetTime();
}
