#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <iostream>

#include "defs.h"

class Bird
{
    private:
        float velocity;
        float acceleration;
        SDL_Rect pos;
        SDL_Texture *up;
        SDL_Texture *down;
        SDL_Texture *mid;
        SDL_Texture *currentRenderingTexture;
        SDL_Renderer *renderer;
        Mix_Chunk* point;
        int animationFrames;
    public:
        int score;
        int coll=45;

        Bird(SDL_Texture *up, SDL_Texture *mid, SDL_Texture *down, SDL_Renderer *renderer);
        void init();
        void render();
        void update(bool jump, float elapsedTime);
        void animation();
};
