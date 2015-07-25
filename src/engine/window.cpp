#include "window.h"

using namespace de;

int Window::width = DEFAULT_WIDTH;
int Window::height = DEFAULT_HEIGHT;
string Window::title = DEFAULT_TITLE;

Window::Window(int width, int height, string title) throw(GraphicsErrorException)
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(window == nullptr)
    {
        //Error creating window
        throw GraphicsErrorException("Could not create window");
    }
    //Make the window current
    glfwMakeContextCurrent(window);
    //Enable experimental
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        throw GraphicsErrorException("Failed to start GLEW");
    }
    //Set fuction to receive key events
    glfwSetKeyCallback(window, glfwKeyCallback);
    //Get the size of OpenGL area
    glfwGetFramebufferSize(window, &glWidth, &glHeight);
    //Set this to prevent wasted frames and screen tearing
    glfwSwapInterval(SWAP_INTERVAL);
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

void Window::setTitle(const string& newTitle)
{
    title = newTitle;
}

void Window::swapBuffers()
{
    glfwSwapBuffers(window);
}

int Window::getGlWidth() const
{
    return glWidth;
}

int Window::getGlHeight() const
{
    return glHeight;
}
