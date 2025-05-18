#include <iostream>
#include "SDL3/SDL.h"
#include <unistd.h>
#include "Core/game.hpp"
int main()
{
    chdir("/Users/jasonevans/Documents/EvansEngine");

    int windowWidth = 800;
    int windowHeight = 600;

    Game game;

    Uint32 previousTime = SDL_GetTicks();

    SDL_Window *window = SDL_CreateWindow("Evans Engine", windowWidth, windowHeight, 0);

    if (window == nullptr)
    {
        printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window,nullptr);
    if (renderer == nullptr)
    {
        printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    bool running = true;
    SDL_Event event;
    game.GameInit(renderer);
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }

        // Clear Screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // DeltaTime calculation
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (float) (currentTime - previousTime) / 1000.0f;
        previousTime = currentTime;

        // Rendering code goes here

        game.GameRender(renderer);
        game.GameUpdate(deltaTime,renderer);

        // Update screen
        SDL_RenderPresent(renderer);
    }


    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;


}