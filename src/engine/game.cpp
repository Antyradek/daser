#include "game.h"

using namespace de;

Game::Game() throw(GraphicsErrorException)
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

Game::~Game()
{
    if(!isRunning) return;
    glfwTerminate();
    isRunning = false;
}

void Game::glfwErrorCallback(int errorCode, const char* desc)
{
    getInstance().isGood = false;
    Debug::logError("GLFW Error: " + to_string(errorCode) + desc);
}

bool Game::checkCorrectness()
{
    return isGood;
}

Game& Game::getInstance() throw(GraphicsErrorException)
{
    static Game newGame;
    return newGame;
}
