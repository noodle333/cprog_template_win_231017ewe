#include "Session.h"
#include <SDL2/SDL.h>
#include "System.h"
#include "Component.h"
#include <iostream>

namespace CWing
{

    Session::Session()
    {
        std::cout << "SESSION";
    }

    void Session::add(Component *c)
    {
        components.push_back(c);
    }

    void Session::run()
    {
        bool quit = false;
        while (!quit)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    for (Component *c : components)
                        c->mouseDown(event);
                    break;
                case SDL_MOUSEBUTTONUP:
                    for (Component *c : components)
                        c->mouseUp(event);
                    break;
                case SDL_KEYDOWN:
                    for (Component *c : components)
                        c->keyDown(event);
                    break;
                case SDL_KEYUP:
                    for (Component *c : components)
                        c->keyUp(event);
                    break;
                }
            }
            SDL_SetRenderDrawColor(system.get_ren(), 255, 255, 255, 255);
            SDL_RenderClear(system.get_ren());
            for (Component *c : components)
                c->draw();
            SDL_RenderPresent(system.get_ren());
        }
    }

    Session::~Session()
    {
    }

    Session session;
}