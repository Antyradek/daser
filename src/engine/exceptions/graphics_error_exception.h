#ifndef GRAPHICS_ERROR_EXCEPTION_H
#define GRAPHICS_ERROR_EXCEPTION_H
#include <exception>
#include <string>

using namespace std;

namespace de
{
///Thrown when there is error starting graphics
class GraphicsErrorException : exception
{
private:
    ///Detailed info about exception
    string info;

public:
    ///Some exception with detailed info about what happened
    GraphicsErrorException(string info);
    virtual ~GraphicsErrorException();

    ///What exactly happened
    const char* what() const noexcept;
};
}
#endif // GRAPHICS_ERROR_EXCEPTION_H
