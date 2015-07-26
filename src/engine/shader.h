#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <fstream>
#include <sstream>
#include "exceptions/io_error_exception.h"
#include "exceptions/graphics_error_exception.h"
#include "game.h"

using namespace std;
namespace de
{
/// Shader program
class Shader
{
private:

    ///The shader as data
    GLuint programId;

public:

    ///Create shader with filename
    Shader(const string& vertFilename, const string& fragFilename) throw(IOErrorException, GraphicsErrorException);

    virtual ~Shader();

    ///Get shader data
    const GLuint getData() const;
};
}

#endif // SHADER_H
