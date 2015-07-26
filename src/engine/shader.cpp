#include "shader.h"

using namespace de;
/// Initialize and register shader pairs. Vertex and Fragment shaders.
Shader::Shader(const string& vertFilename, const string& fragFilename)  throw(IOErrorException, GraphicsErrorException)
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

    //check
    //TODO Make a more detailed messages in future
    GLint status;
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE)
    {
        string msg;
        GLint infoLogLength;
        glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &infoLogLength);
        char strInfoLog[infoLogLength + 1];
        glGetShaderInfoLog(vertShader, infoLogLength, nullptr, strInfoLog);
        msg += strInfoLog;
        Debug::logError("Compilation error " + msg);
        throw GraphicsErrorException("Error in " + vertFilename + " compilaton: " + msg);
    }
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE)
    {
        string msg;
        GLint infoLogLength;
        glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &infoLogLength);
        char strInfoLog[infoLogLength + 1];
        glGetShaderInfoLog(fragShader, infoLogLength, nullptr, strInfoLog);
        msg += strInfoLog;
        Debug::logError("Compilation error " + msg);
        throw GraphicsErrorException("Error in " + fragFilename + " compilaton: " + msg);
    }

    programId = glCreateProgram();
    glAttachShader(programId, vertShader);
    glAttachShader(programId, fragShader);
    glLinkProgram(programId);
    glDetachShader(programId, vertShader);
    glDetachShader(programId, fragShader);

    glGetProgramiv(programId, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        string msg;
        GLint infoLogLength;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
        char strInfoLog[infoLogLength + 1];
        glGetProgramInfoLog(programId, infoLogLength, nullptr, strInfoLog);
        msg += strInfoLog;
        glDeleteProgram(programId);
        Debug::logError("Shader linking error " + msg);
        throw GraphicsErrorException("Error linking: " + msg);
    }
}

Shader::~Shader()
{
    //dtor
}

const GLuint Shader::getData() const
{
    return programId;
}
