#ifndef IO_ERROR_EXCEPTION_H
#define IO_ERROR_EXCEPTION_H
#include <string>
#include <exception>

using namespace std;
namespace de
{
///Thrown when some I/O operation fails like file not exists etc...
class IOErrorException : public exception
{
private:
    ///Detailed info about exception
    string info;

public:
    ///With detailed info
    IOErrorException(string info);

    virtual ~IOErrorException();

    ///What exactly happened
    const char* what() const noexcept;

};
}
#endif // IO_ERROR_EXCEPTION_H
