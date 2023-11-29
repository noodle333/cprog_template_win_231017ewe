#include <SDL2/SDL.h>
#include "Session.h"
#include "Component.h"
#include <string>
#include "Label.h"
#include "Button.h"
#include "Sprite.h"

#include <iostream>

using namespace std;
using namespace CWing;

int value = 0;

class TestButton : public Button
{
public:
    TestButton(Label *label) : Button(100, 100, 150, 70, "Test"), label(label) {}
    void perform(Button *source)
    {
        Sprite *s = Sprite::CreateSprite(500, 500, 50, 50, sys.get_ren(), constants::gResPath + "images/bg.jpg");
        s->setSize(100, 100);
        s->setPosition(500, 500);
        session.add(s);
    }

private:
    Label *label;
};

int main(int argc, char **argv)
{
    std::cout << "main";

    Label *label = Label::getInstance(270, 100, 100, 70, "0");
    session.add(label);
    Button *b = new TestButton(label);
    session.add(b);
    session.run();

    return 0;
}