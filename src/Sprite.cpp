#include "Sprite.h"
#include <iostream>
#include "System.h"
#include "Component.h"
#include <SDL2/SDL_image.h>
#include <string>

namespace CWing
{
    Sprite::Sprite(int x, int y, int w, int h, SDL_Renderer *ren, const std::string &imagePath) : Component(x, y, w, h), renderer(ren)
    {
        texture = loadTexture(imagePath);
        if (texture)
        {
            SDL_QueryTexture(texture, NULL, NULL, &destinationRect.w, &destinationRect.h); // can be replaced with &destRect.w if you want images real size
            setPosition(0, 0);
        }
        else
        {
            // error
        }
    }
    Sprite *Sprite::CreateSprite(int x, int y, int w, int h, SDL_Renderer *ren, const std::string &imagePath)
    {
        return new Sprite(x, y, w, h, ren, imagePath);
    }

    Sprite::~Sprite()
    {
        if (texture)
        {
            SDL_DestroyTexture(texture);
        }
    }

    void Sprite::setPosition(int x, int y)
    {
        destinationRect.x = x;
        destinationRect.y = y;
    }

    void Sprite::setSize(int w, int h)
    {
        destinationRect.w = w;
        destinationRect.h = h;
    }

    // void Sprite::setRotation(double angle) {};
    void Sprite::draw() const
    {
        if (texture && renderer)
        {
            SDL_RenderCopyEx(renderer, texture, NULL, &destinationRect, 0, NULL, SDL_FLIP_NONE); // set rotation to 0 cause we wont need it (probably)
        }
    }

    SDL_Texture *Sprite::loadTexture(const std::string &path)
    {
        SDL_Surface *surface = IMG_Load(path.c_str());
        if (!surface)
        {
            // error
            return nullptr;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!texture)
        {
            // error;
        }
        return texture;
    }
}
