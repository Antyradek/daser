#include <iostream>
#include <string>
#include "config.h"
#include "engine/game.h"
#include "renderer.h"

using namespace std;
using namespace de;
//using namespace glm;

int main()
{
    string gameName = "DASER " + to_string(VERSION_MAJOR) + "." + to_string(VERSION_MINOR) + "." + to_string(VERSION_PATCH);
    Game::init();
    Window::setTitle(gameName);
    Renderer renderer;
    while(Window::getInstance().isRunning())
    {
        //Swap buffers
        Window::getInstance().swapBuffers();

        //drain the event queue
        Window::getInstance().pollEvents();

        //UPDATE HERE
        renderer.render();

    }
    Debug::log("Exiting game");

    Game::stop();

    return 0;
}
