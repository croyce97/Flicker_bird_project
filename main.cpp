#include "game.h"
#include "defs.h"
#undef main

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    Game game("Flappy bird made by 22028200", WIDTH, HEIGHT);

    game.Start();

    return 0;
}
