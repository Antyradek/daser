#ifndef INPUT_KEYS_H
#define INPUT_KEYS_H

///Interface to call input events on a game
namespace de
{
class InputKeys
{
public:
    ///This is called, when ESC is pressed
    virtual void escPressed() = 0;

};
}
#endif // INPUT_KEYS_H
