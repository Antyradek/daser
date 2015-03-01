#include "window.h"

using namespace de;

int Window::width = DEFAULT_WIDTH;
int Window::height = DEFAULT_HEIGHT;
string Window::title = DEFAULT_TITLE;

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
    glfwSetKeyCallback(window, glfwKeyCallback);
    Debug::log("Created new " + title + " window");
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

Window& Window::getInstance() throw(GraphicsErrorException)
{
    static Window newWindow(width, height, title) ;
    return newWindow;
}

void Window::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        Input::getInstance().addPressedKey(key);
    }
}

void Window::pollEvents()
{
    Input::getInstance().clearKeys();
    glfwPollEvents();
}

void Window::setDimensions(int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;
}

void Window::setTitle(string newTitle)
{
    title = newTitle;
}
