#include <iostream>
#include <string>
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
	Window window(512, 512, gameName);

	Game::stop();
    return 0;
}
