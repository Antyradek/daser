#include "renderer.h"

using namespace de;
Renderer::Renderer()
{
    //ctor
}

Renderer::~Renderer()
{
    //dtor
}

void Renderer::render()
{
    
    float ratio;
    ratio = Window::getInstance().getGlWidth() / (float) Window::getInstance().getGlHeight();
    glViewport(0, 0, Window::getInstance().getGlWidth(), Window::getInstance().getGlHeight());
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
}
