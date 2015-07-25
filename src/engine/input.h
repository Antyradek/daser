#ifndef INPUT_H
#define INPUT_H
#include <unordered_set>
#include "window.h"

using namespace std;
namespace de
{
///Class should give information about key events from current window
class Input
{
private:

    Input();

    virtual ~Input();

    ///Set to store just pressed keys
    unordered_set<int> pressedKeys;

    ///Clear data of stored keys
    void clearKeys();

    ///Store newly pressed key
    void addPressedKey(int key);

    ///Let's put a Window into friendzone, so that it will tell us, what has been pressed
    friend class Window;

public:

    ///Singleton instance
    static Input& getInstance();

    ///Was the key pressed during this frame?
    bool isPressed(int key) const;
};
}

#endif // INPUT_H
