#ifndef WINDOW_H
#define WINDOW_H
#define DEFAULT_WIDTH 512
#define DEFAULT_HEIGHT 512
#define DEFAULT_TITLE "DASER"
#define SWAP_INTERVAL 1
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "exceptions/graphics_error_exception.h"
#include "debug.h"
#include "input.h"

using namespace std;

namespace de
{
///GLFW Window as a Meyers singleton. Gives window with default parameters. You can set them before first call.
class Window
{
private:
    ///Window structure
    GLFWwindow* window;

    ///Width of window
    static int width;

    ///Height of window
    static int height;

    ///Title of window
    static string title;

    ///OpenGL area width
    int glWidth;

    ///OpenGL area height
    int glHeight;

    ///Create Window with that size and frame title
    Window(int width, int height, string title) throw(GraphicsErrorException);

    ///Unregisters window from LWGL
    virtual ~Window();

    ///Let the copy constructor be private
    Window(const Window&) = delete;

    ///Let this be private too
    Window& operator=(const Window&) = delete;

    ///Callback for keys usage
    static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

public:

    ///Set the new dimensions for the window
    static void setDimensions(int newWidth, int newHeight);

    ///Set the new title for the window
    static void setTitle(string newTitle);

    ///Get the current window, it must have been initialized before
    static Window& getInstance() throw(GraphicsErrorException);

    ///Is the window running, or user wants it closed? Returns false, when told to close.
    bool isRunning() const;

    ///Force the window to close as if pressed X
    void forceClose();

    ///Executes given listener for every event there was
    void pollEvents();

    ///Swap rendering buffers
    void swapBuffers();

    ///Get the render area width
    int getGlWidth();

    ///Get the render area height
    int getGlHeight();

};
}
#endif // WINDOW_H
