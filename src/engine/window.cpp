#include "window.h"

using namespace de;
Window::Window(int width, int height, string title) throw(GraphicsErrorException)
{
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(window == nullptr)
    {
        //Error creating window
        throw GraphicsErrorException("Could not create window");
    }
}

Window::~Window()
{
    glfwDestroyWindow(window);
}
