#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <GLFW/glfw3.h>
#include "exceptions/graphics_error_exception.h"
#include "exceptions/glfw_error_exception.h"
#include "debug.h"

using namespace std;

namespace de
{

class Game
{
private:
    ///Called when something in GLFW fails. Sets object to failed state and prints error.
    static void glfwErrorCallback(int errorCode, const char* desc);

    ///Were there any errors?
    static bool isGood;

    ///Is the game still running?
    static bool isRunning;

public:
    ///Initialize engine and show window with parameters
    static void init() throw(GraphicsErrorException);

    ///Turn off program
    static void stop();

    ///Were there any errors?
    static bool checkCorrectness();
protected:

};
}

#endif // GAME_H
