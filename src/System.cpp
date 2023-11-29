#include "System.h"
#include <SDL2/SDL.h>

namespace CWing
{
    System::System()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow("CPROG", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, 600, 400, 0);
        renderer = SDL_CreateRenderer(window, -1, 0);
        // TTF_Init();
    }

    System::~System()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    SDL_Renderer *System::get_ren() const
    {
        return renderer;
    }

    TTF_Font *System::get_font() const
    {
        return font;
    }

    System sys;

}
