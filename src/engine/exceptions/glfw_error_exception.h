#ifndef GLFW_ERROR_EXCEPTION_H
#define GLFW_ERROR_EXCEPTION_H
#include <string>

using namespace std;
namespace de
{
///Some exception triggered by GLFW error callback
class GLFWErrorException : exception
{
private:
    string info;
public:
    ///Create exception with additional info
    GLFWErrorException(string info);
    virtual ~GLFWErrorException();

    ///Text argumented to the callback
    const char* what() const noexcept;

protected:
};
}
#endif // GLFW_ERROR_EXCEPTION_H
