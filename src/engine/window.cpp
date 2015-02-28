#include "window.h"

using namespace de;

Window* Window::thisWindow = nullptr;

Window::Window(int width, int height, string title) throw(GraphicsErrorException)
{
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(window == nullptr)
    {
        //Error creating window
        throw GraphicsErrorException("Could not create window");
    }
    //Make the window current
    glfwMakeContextCurrent(window);
    Debug::log("Made new window current");
    glfwSetKeyCallback(window, glfwKeyCallback);
}

Window::~Window()
{
    glfwDestroyWindow(window);
}

bool Window::isRunning() const
{
    return !glfwWindowShouldClose(window);
}

void Window::forceClose()
{
    glfwSetWindowShouldClose(window, true);
}

Window& Window::getWindow(int width, int height, string title) throw(GraphicsErrorException)
{
    static Window window(width, height, title);
    thisWindow = &window;
    return window;
}

Window& Window::getWindow()
{
    return *thisWindow;
}

void Window::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    switch(key)
    {
    case GLFW_KEY_ESCAPE:
        if(action == GLFW_PRESS)
        {
            thisWindow->keysListener->escPressed();
        }
    }
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::setKeysListener(InputKeys& listener)
{
    keysListener = &listener;
}
