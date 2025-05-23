//
// Created by Jason Evans on 17/05/2025.
//

#include "game.hpp"

#include <iostream>
#include <__ostream/basic_ostream.h>

Game::Game()
{
    texture = nullptr;
}


void Game::GameInit(SDL_Renderer *renderer)
{

    texture = IMG_LoadTexture(renderer,"Resources/Background/BackgroundImage.png");
    player.PlayerInit(renderer);
    enemy.Init(renderer);
}


void Game::GameRender(SDL_Renderer *renderer)
{
    int gemX = 260;
    int gemY = 260;
    SDL_RenderTexture(renderer, texture, nullptr, nullptr);

    // Temporary for now
    SDL_SetRenderDrawColor(renderer, 173, 216, 230, 1); // Light blue
    gem.DropGem(renderer, gemX, gemY, 2);

    if (texture == nullptr)
    {
        std::cout << "Background Texture is null" << std::endl;
    }
}

void Game::GameUpdate(float deltaTime, SDL_Renderer *renderer)
{
    player.PlayerUpdate(deltaTime,renderer);
    enemy.Update(renderer,deltaTime);
}

Game::~Game()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}
