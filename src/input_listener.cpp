#include "input_listener.h"
using namespace de;

InputListener::InputListener()
{
    //ctor
}

InputListener::~InputListener()
{
    //dtor
}

void InputListener::escPressed()
{
    Window::getWindow().forceClose();
}
