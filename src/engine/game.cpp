#include "game.h"

using namespace de;

bool Game::isGood;
bool Game::isRunning = false;

void Game::init() throw(GraphicsErrorException)
{
    if(isRunning) return;
    if(!glfwInit())
    {
        throw GraphicsErrorException("Can't start GLFW");
    }
    isGood = true;
    glfwSetErrorCallback(glfwErrorCallback);
    isRunning = true;
}

void Game::stop()
{
    if(!isRunning) return;
    glfwTerminate();
    isRunning = false;
}

void Game::glfwErrorCallback(int errorCode, const char* desc)
{
    isGood = false;
    Debug::logError("GLFW Error: " + to_string(errorCode) + desc);
}

bool Game::checkCorrectness()
{
    return isGood;
}
