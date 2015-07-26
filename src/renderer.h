#ifndef RENDERER_H
#define RENDERER_H
#include "engine/window.h"
#include "engine/shader.h"
#include <fstream>
#include <vector>
#include <memory>

using namespace de;
///Static class to render because fuck you CMake
class Renderer
{
private:
    GLuint vertexbuffer;
    GLuint vertexArrayID;
    unique_ptr<Shader> mainShader;
public:
    Renderer();
    virtual ~Renderer();
    void render();
};

#endif // RENDERER_H
