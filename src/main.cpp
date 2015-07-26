#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "config.h"
#include "engine/game.h"
#include "engine/window.h"
#include "engine/shader.h"
#include "renderer.h"

using namespace std;
using namespace de;
//using namespace glm;

int main()
{
    string gameName = "DASER " + to_string(VERSION_MAJOR) + "." + to_string(VERSION_MINOR) + "." + to_string(VERSION_PATCH);
    Game::getInstance();
    Window::setTitle(gameName);
    Window::getInstance();

    //Renderer renderer;
    //Shader mainShader("src/shaders/rand.vert", "src/shaders/rand.frag");
    Renderer renderer;

    while(Window::getInstance().isRunning())
    {
        Window::getInstance().pollEvents();

        renderer.render();

        Window::getInstance().swapBuffers();
    }
    return 0;
}
