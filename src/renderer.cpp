#include "renderer.h"

using namespace de;
Renderer::Renderer() : mainShader(new Shader("src/shaders/rand.vert", "src/shaders/rand.frag"))
{
    //We can't use rvalue reference (Shader&& mainShader), because that makes a reference to temporary variable which is destroyed after constructor
    //VAOs
    vertexArrayID = 0;
    vertexbuffer = 0;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

    GLfloat vertices[] =
    {
        0.0f, 0.8f, 0.0f,
        -0.8f,-0.8f, 0.0f,
         0.8f,-0.8f, 0.0f,
    };

    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(glGetAttribLocation(mainShader->getData(), "vert"));

    glVertexAttribPointer(glGetAttribLocation(mainShader->getData(), "vert"), 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Renderer::~Renderer()
{
    //delete(mainShader);
}

void Renderer::render()
{
    glClearColor(0.5,0.5,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(mainShader->getData());
    glBindVertexArray(vertexArrayID);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(0);
    glBindVertexArray(0);

    /*
    // Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders( "rand.vert", "rand.frag" );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(programID);


    /*
        float ratio;
        ratio = Window::getInstance().getGlWidth() / (float) Window::getInstance().getGlHeight();
        glViewport(0, 0, Window::getInstance().getGlWidth(), Window::getInstance().getGlHeight());

        glClear(GL_COLOR_BUFFER_BIT); //czyści tło

        glMatrixMode(GL_PROJECTION); //przełącza maierze
        glLoadIdentity(); //załaduj macierz jednostkową
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f); //ustaw sześcian widoku

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 1.f, 0.f);

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.3f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        */

}
