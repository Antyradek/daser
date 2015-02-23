#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>
#include <string>
#include "exceptions/graphics_error_exception.h"

using namespace std;

namespace de
{
    ///GLFW Window
class Window
{
private:
    GLFWwindow* window;
    public:
        ///Create Window with that size and frame title
        Window(int width, int height, string title) throw(GraphicsErrorException);
        virtual ~Window();
    protected:
};
}
#endif // WINDOW_H
