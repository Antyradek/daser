#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include "config.h"
#include "engine/game.h"
#include "engine/window.h"

using namespace std;
using namespace de;

int main()
{

	cout << "DASER " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << endl;
	string gameName = "DASER " + to_string(VERSION_MAJOR) + "." + to_string(VERSION_MINOR) + "." + to_string(VERSION_PATCH);
	Game::init();
	while(Window::getInstance().isRunning())
    {
        //drain the event queue
        Window::getInstance().pollEvents();
        if(Input::getInstance().isPressed(GLFW_KEY_SPACE))
        {
            //or .isPressed(32);
            Debug::log("Mashed SPACE");
        }
        if(Input::getInstance().isPressed(GLFW_KEY_ESCAPE))
        {
            Window::getInstance().forceClose();
            //we can also put break here, but this one is less harsh
        }
    }
    Debug::log("Exiting game");

	Game::stop();

    return 0;
}
