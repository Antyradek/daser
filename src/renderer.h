#ifndef RENDERER_H
#define RENDERER_H
#include "engine/window.h"
#include <fstream>
#include <vector>

///Static class to render because fuck you CMake
class Renderer
{
private:
    GLuint vertexbuffer;
    GLuint vertexArrayID;
public:
    Renderer();
    virtual ~Renderer();
    void render();
};

#endif // RENDERER_H
