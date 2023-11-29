#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>
#include "Component.h"
#include "System.h"

namespace CWing
{
    class Sprite : public Component
    {
    public:
        Sprite(int x, int y, int w, int h, SDL_Renderer *ren, const std::string &imagePath);
        static Sprite *CreateSprite(int x, int y, int w, int h, SDL_Renderer *ren, const std::string &imagePath);
        ~Sprite();

        void setPosition(int x, int y);
        void setSize(int w, int h);
        // void setRotation(double angle);
        void draw() const;
        std::string getType() const; // override?

    private:
        SDL_Texture *texture;
        SDL_Renderer *renderer;
        SDL_Rect destinationRect;
        // double rotation;

        SDL_Texture *loadTexture(const std::string &path);
    };
}

#endif