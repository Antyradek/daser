#ifndef DEBUG_H
#define DEBUG_H
#include <string>
#include <iostream>

using namespace std;
namespace de
{
///Logger to print all errors and warnings to the console. Uses ANSI ESCAPE CODES, so please use less dumb terminal
class Debug
{
public:

    ///Print text in red to stdout
    static void logError(string error);

    ///Print text to stdout
    static void log(string info);
};
}
#endif // DEBUG_H
