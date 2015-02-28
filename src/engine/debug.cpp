#include "debug.h"

using namespace de;
void Debug::logError(string error)
{
    cout << "\033[31m" << error << "\033[39m" << endl;
}

void Debug::log(string text)
{
    cout << text << endl;
}
