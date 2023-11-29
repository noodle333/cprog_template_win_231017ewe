#ifndef SESSION_H
#define SESSION_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "Component.h"

namespace CWing
{
    class Session
    {
    public:
        Session();
        void add(Component *c);
        void run();
        ~Session();

    private:
        std::vector<Component *> components;
    };
    extern Session session;
}

#endif