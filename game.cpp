#include "game.h"

Game::Game(const char *title, int width, int height)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    loadTextures();

    bird = new Bird(tex_playerDown, tex_playerMid, tex_playerUp, renderer);

    isRunning = true;
    gameover = false;

    ground1 = -WIDTH / 2;
    ground2 = WIDTH  / 2;

    srand(time(NULL));
}

void Game::init()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    die = Mix_LoadWAV("sound/die.wav");
    hit = Mix_LoadWAV("sound/hit.wav");
    swooshing = Mix_LoadWAV("sound/swooshing.wav");
    wing = Mix_LoadWAV("sound/wing.wav");

    if (die == NULL || hit == NULL || swooshing == NULL || wing == NULL) {
        printf("Failed to load sounds! SDL_mixer Error: %s\n", Mix_GetError());
    }

    bird->init();

    while(!pipes.empty()) {
        delete pipes.front();
        pipes.pop_front();
    }

    Pipe* firstPipe = new Pipe(WIDTH * 2 + PIPE_DISTANCE, rand() % 302 + 150);
    Pipe* secondPipe = new Pipe(firstPipe->bottom_dst.x + PIPE_DISTANCE, rand() % 302 + 150);
    Pipe* thirdPipe = new Pipe(secondPipe->bottom_dst.x + PIPE_DISTANCE, rand() % 302 + 150);

    pipes.push_back(firstPipe);
    pipes.push_back(secondPipe);
    pipes.push_back(thirdPipe);

    gameStarted = false;
    gameover = false;

    render();
}

void Game::Start()
{    
    // initialize everything before the game starts
    init();
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    SDL_RenderClear(renderer);
    //background
    if((bird->score >= 10 && bird->score <= 20) || (bird->score >= 30 && bird->score <= 40) || (bird->score >= 50 && bird->score <= 60)){
        SDL_RenderCopy(renderer, tex_backgroundN, NULL, NULL);
    } else {
        SDL_RenderCopy(renderer, tex_backgroundD, NULL, NULL);
    }

    //pipes
    for(Pipe* pipe : pipes)
    {
        pipe->render(renderer, tex_pipe);
    }

    //ground
    SDL_Rect dstrect4 =  (SDL_Rect) {ground1, HEIGHT - GROUND_HEIGHT, WIDTH, GROUND_HEIGHT};
    SDL_RenderCopy(renderer, tex_ground, NULL, &dstrect4);
    SDL_Rect dstrect5 =  (SDL_Rect) {ground2, HEIGHT - GROUND_HEIGHT, WIDTH, GROUND_HEIGHT};
    SDL_RenderCopy(renderer, tex_ground, NULL, &dstrect5);

    bird->render();

    SDL_Rect dstrect1 = (SDL_Rect) {(WIDTH - 200) / 2, HEIGHT / 3, 200, 50};
    SDL_RenderCopy(renderer, tex_getreddy, NULL, &dstrect1);

    
    SDL_Rect textRect = {WIDTH / 3 - 50 , HEIGHT / 3 + 50, 300, 50};
    SDL_RenderCopy(renderer, tex_guild, NULL, &textRect);

    SDL_RenderPresent(renderer);

    auto t1 = std::chrono::system_clock::now();
    auto t2 = t1;
    // main game loop
    while(isRunning)
    {
    t1 = t2;
    t2 = std::chrono::system_clock::now();
    
    std::chrono::duration<float> dt = t2 - t1;

    bool jump = false;
    while(SDL_PollEvent(&event))
    {  
        if(event.type == SDL_QUIT)
            isRunning = false;

        if((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) || (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT))
        {
            jump = gameStarted = true;
            if((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) || (event.button.button == SDL_BUTTON_LEFT))
            {
                Mix_PlayChannel(-1, wing, 0);
                Mix_PlayChannel(-1, swooshing, 0);
            }
        }
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && event.button.x >= 10 && event.button.x <= 45 && event.button.y >= 10 && event.button.y <= 45)
            pausedButtonClicked = true;
    }

    if(frameDelay > dt.count())
        SDL_Delay(frameDelay - dt.count());
    
    if(gameStarted && !gamePaused)
    {
        update(jump, dt.count(), gameover);
        if(gameover)
            gameOver();
    }

    if(pausedButtonClicked == true ){
        gamePaused = !gamePaused; // Chuyển trạng thái gamePaused
        pausedButtonClicked = false;}
}

    Close();
}
