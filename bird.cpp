#include "bird.h"
void Bird::init()
{
    point = Mix_LoadWAV("sound/point.wav");
    currentRenderingTexture = mid;
    animationFrames = 0;
    score = 0;

    velocity = 0.0f;
    acceleration = 0.0f;

    pos.x = WIDTH / 3 - 32;
    pos.y = HEIGHT / 2;
    pos.w = BIRD_WIDTH;
    pos.h = BIRD_HEIGHT;
}

Bird::Bird(SDL_Texture *up, SDL_Texture *mid, SDL_Texture *down, SDL_Renderer *renderer) : up(up), mid(mid), down(down), renderer(renderer)
{
    init();
}

void Bird::update(bool jump, float elapsedTime)
{      
    elapsedTime *= 5;
    if(jump)
    {
        acceleration = 10.0f;
        velocity = -0.7 * GRAVITY;
    }
    else
    {
        acceleration += 0.5 * GRAVITY * elapsedTime;
    }

    if(acceleration >= GRAVITY)
        acceleration = GRAVITY;

    velocity += acceleration * elapsedTime;
    pos.y += velocity * elapsedTime;
}

bool Bird::collisionDetector(Pipe* pipe) {
    bool collided = false;

    if (pos.x + pos.w > pipe->top_dst.x && pos.x < pipe->top_dst.x + PIPE_WIDTH) {
        if (pos.y < pipe->top_dst.y + pipe->top_dst.h || pos.y + pos.h > pipe->bottom_dst.y) {
            if (coll) {
                    coll--; 
                    if(coll==14){
                     Mix_PlayChannel(-1, point, 0);
            }
            }
            else {
                collided = true;
                }
        }
    }

    if (!pipe->passed && pos.x >= pipe->top_dst.x) {
        pipe->passed = true;
        // score ++;
    }

    if (pos.y + pos.h > HEIGHT - GROUND_HEIGHT) { 
        pos.y = 0;
    } else if (pos.y < 0) { 
        pos.y = HEIGHT - GROUND_HEIGHT - pos.h;
    }

    return collided;
}

void Bird::render()
{
    animation();    

    if(velocity == 0)
        SDL_RenderCopy(renderer, mid, NULL, &pos);
    else if(velocity < 50)
        SDL_RenderCopyEx(renderer, currentRenderingTexture, NULL, &pos, -30.0, NULL, SDL_FLIP_NONE);
    else if(velocity >= 50 && velocity < 200)
        SDL_RenderCopyEx(renderer, currentRenderingTexture, NULL, &pos, 30.0, NULL, SDL_FLIP_NONE);
    else if(velocity >= 200)
        SDL_RenderCopyEx(renderer, mid, NULL, &pos, 90.0, NULL, SDL_FLIP_NONE);

}

void Bird::animation()
{
    animationFrames++;

    if(animationFrames == 5)
        currentRenderingTexture = down;
    else if(animationFrames == 15)
        currentRenderingTexture = mid;
    else if(animationFrames == 20)
    {
        animationFrames = 0;
        currentRenderingTexture = up;
    }
}
 
