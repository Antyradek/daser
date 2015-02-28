#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include "config.h"
#include "engine/game.h"
#include "engine/window.h"
#include "input_listener.h"

using namespace std;
using namespace de;

int main()
{

	cout << "DASER " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << endl;
	string gameName = "DASER " + to_string(VERSION_MAJOR) + "." + to_string(VERSION_MINOR) + "." + to_string(VERSION_PATCH);
	Game::init();
    InputListener inputListener;
	Window& window = Window::getWindow(512, 512, gameName);
	window.setKeysListener(inputListener);
	while(window.isRunning())
    {
        //drain the event queue
        window.pollEvents();
    }
    Debug::log("Exiting game");

	Game::stop();

    return 0;
}
