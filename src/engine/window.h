#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>
#include <string>
#include "exceptions/graphics_error_exception.h"
#include "debug.h"
#include "input_keys.h"

using namespace std;

namespace de
{
///GLFW Window as a singleton
class Window
{
private:
    ///This singletone window
    static Window* thisWindow;

    ///Window structure
    GLFWwindow* window;

    ///Object to send events to
    InputKeys* keysListener;

    ///Create Window with that size and frame title
    Window(int width, int height, string title) throw(GraphicsErrorException);

    ///Unregusters window from LWGL
    virtual ~Window();

    ///Let the copy constructor be private
    Window(const Window&) = delete;

    ///Let this be private too
    Window& operator=(const Window&) = delete;

    ///Callback for keys usage
    static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
public:
    ///Gets the window instance
    static Window& getWindow(int width, int height, string title) throw(GraphicsErrorException);

    ///Get the current window, it must have been initialized before
    static Window& getWindow();

    ///Is the window running, or user wants it closed? Returns false, when told to close.
    bool isRunning() const;

    ///Force the window to close as if pressed X
    void forceClose();

    ///Executes given listener for every event there was
    void pollEvents();

    ///Set keys listener
    void setKeysListener(InputKeys& listener);

};
}
#endif // WINDOW_H
