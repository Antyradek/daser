#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "exceptions/graphics_error_exception.h"
#include "exceptions/glfw_error_exception.h"
#include "debug.h"
#include "window.h"
#include "time.h"

using namespace std;

namespace de
{

///The main game. This needs to be initialized at the beginning and stopped at the end
class Game
{
private:

    ///Called when something in GLFW fails. Sets object to failed state and prints error.
    static void glfwErrorCallback(int errorCode, const char* desc);

    ///Were there any errors?
    bool isGood;

    ///Is the game still running?
    bool isRunning;

    ///Initialize engine and show window with parameters
    Game() throw(GraphicsErrorException);

    ///Turn off program
    virtual ~Game();

    ///Let the copy constructor be private
    Game(const Game&) = delete;

    ///Let this be private too
    Game& operator=(const Game&) = delete;

public:

    ///Were there any errors?
    bool checkCorrectness();

    ///Get the current window, it must have been initialized before
    static Game& getInstance() throw(GraphicsErrorException);
};
}

#endif // GAME_H
