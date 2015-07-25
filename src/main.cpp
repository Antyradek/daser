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
    //Create actual window
    Window::getInstance();
    Renderer renderer;
    while(Window::getInstance().isRunning())
    {
        //UPDATE HERE
        renderer.render();

        //Swap buffers
        Window::getInstance().swapBuffers();

        //drain the event queue
        Window::getInstance().pollEvents();



    }
    Debug::log("Exiting game");

    Game::stop();

    return 0;
}
