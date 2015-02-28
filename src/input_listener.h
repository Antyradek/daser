#ifndef INPUT_LISTENER_H
#define INPUT_LISTENER_H
#include "engine/input_keys.h"
#include "engine/game.h"
#include "engine/window.h"
using namespace de;

///Object on which key events are called
class InputListener : public InputKeys
{
    public:
        InputListener();
        virtual ~InputListener();

        void escPressed();
    protected:
    private:
};

#endif // INPUT_LISTENER_H
