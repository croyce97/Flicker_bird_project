#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <list>
#include <chrono>
#include <random>
#include <time.h>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

#include "bird.h"
#include "pipe.h"
#include "defs.h"

typedef std::chrono::system_clock::time_point time_point;

class Game
{
    public:
        SDL_Texture *tex_backgroundD;
        SDL_Texture *tex_backgroundN;
        SDL_Texture *tex_ground;
        SDL_Texture *tex_playerUp;
        SDL_Texture *tex_playerMid;
        SDL_Texture *tex_playerDown;
        SDL_Texture *tex_pipe;
        SDL_Texture *tex_numbers[10];
        SDL_Texture* tex_gameover;
        SDL_Texture* tex_getreddy;
        SDL_Texture* tex_guild;
        SDL_Texture* tex_score;
        SDL_Texture* tex_pause;
        SDL_Texture* tex_resume;
        SDL_Texture* tex_vang;
        SDL_Texture* tex_bac;
        SDL_Texture* tex_dong;
        SDL_Texture* tex_dung;


        TTF_Font* font;

        Mix_Chunk* die;
        Mix_Chunk* hit;
        Mix_Chunk* swooshing;
        Mix_Chunk* wing;


        bool isRunning;
        bool gamePaused;
        bool pausedButtonClicked;

        Game(const char *title, int _width, int _height);
        
        void Start();
        void Close();
        void update(bool jump, float elapsedTime, bool &gameover);
        void handleEvent(SDL_Event& event, bool& pausedButtonClicked, bool& gamePaused);
        void render();
        void gameOver();
        void init();
    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
        

        SDL_Event event;

        Bird *bird;

        std::list<Pipe*> pipes;

        int ground1, ground2;
        int highScore; 
        bool gameStarted, gameover;

        void loadTextures();
};
