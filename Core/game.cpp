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
}


void Game::GameRender(SDL_Renderer *renderer)
{
    SDL_RenderTexture(renderer, texture, nullptr, nullptr);


    if (texture == nullptr)
    {
        std::cout << "Background Texture is null" << std::endl;
    }
}

void Game::GameUpdate(float deltaTime, SDL_Renderer *renderer)
{
    player.PlayerUpdate(deltaTime,renderer);
}

Game::~Game()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}
