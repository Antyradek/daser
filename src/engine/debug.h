#ifndef DEBUG_H
#define DEBUG_H
#include <string>
#include <iostream>

using namespace std;
namespace de
{
    ///Logger to print all errors and warnings
class Debug
{
    public:
        ///Print text in red to stdout
        static void logError(string error);
    protected:
    private:
};
}
#endif // DEBUG_H
