#include "game.h"

using namespace de;

bool Game::isGood;

void Game::init() throw(GraphicsErrorException)
{
    if(!glfwInit())
    {
        throw GraphicsErrorException("Can't start GLFW");
    }
    isGood = true;
    glfwSetErrorCallback(glfwErrorCallback);
}

void Game::stop()
{
    glfwTerminate();
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
