#include "shader.h"

using namespace de;
/// Initialize and register shader pairs. Vertex and Fragment shaders.
Shader::Shader(const string& vertFilename, const string& fragFilename)  throw(IOErrorException)
{
    ifstream vertStream(vertFilename, ifstream::in);
    ifstream fragStream(fragFilename, ifstream::in);
    if(!vertStream.good())
    {
        throw IOErrorException("Could not open " + vertFilename);
    }
    if(!fragStream.good())
    {
        throw IOErrorException("Could not open " + fragFilename);
    }
    stringstream vertSS;
    stringstream fragSS;
    vertSS << vertStream.rdbuf();
    fragSS << fragStream.rdbuf();
    vertStream.close();
    fragStream.close();

    //compile
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    string vertSrc = vertSS.str();
    string fragSrc = fragSS.str();
    const char* vertSrcPtr = vertSrc.c_str();
    const char* fragSrcPtr = fragSrc.c_str();
    glShaderSource(vertShader, 1, &vertSrcPtr, nullptr);
    glShaderSource(fragShader, 1, &fragSrcPtr, nullptr);
    glCompileShader(vertShader);
    glCompileShader(fragShader);

    programId = glCreateProgram();
    glAttachShader(programId, vertShader);
    glAttachShader(programId, fragShader);
    glLinkProgram(programId);
}

Shader::~Shader()
{
    //dtor
}

const GLuint Shader::getData() const
{
    return programId;
}
