#ifndef RENDERER_H
#define RENDERER_H
#include "engine/window.h"

///Static class to render because fuck you CMake
class Renderer
{
private:
        Renderer();
        virtual ~Renderer();
    public:
        static void render();
};

#endif // RENDERER_H
