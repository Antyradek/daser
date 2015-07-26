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
    Game::getInstance();
    Window::setTitle(gameName);
    //Create actual window
    Window::getInstance();
    Renderer renderer;
    while(Window::getInstance().isRunning())
    {
        //drain the event queue
        Window::getInstance().pollEvents();

        //UPDATE HERE
        renderer.render();

          //Swap buffers
        Window::getInstance().swapBuffers();

    }
    Debug::log("Exiting game");
    return 0;
}
