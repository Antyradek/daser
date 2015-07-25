#ifndef TIME_H
#define TIME_H
#include "window.h"

namespace de
{
///Time to check events, the counter initialized during GLFW init
class Time
{
private:

    Time();

    virtual ~Time();

public:

    ///Get the Singleton instance
    static Time& getInstance();

    ///Get the amount of seconds from the start of the game
    float getTime() const;
};
}

#endif // TIME_H
