#include "input.h"

using namespace de;

Input::Input()
{

}

Input::~Input()
{

}

Input& Input::getInstance()
{
    static Input input;
    return input;
}

void Input::clearKeys()
{
    pressedKeys.clear();
}

void Input::addPressedKey(int key)
{
    pressedKeys.insert(key);
}

bool Input::isPressed(int key)
{
    return (pressedKeys.find(key) != pressedKeys.end());
}

