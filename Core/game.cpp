//
// Created by Jason Evans on 17/05/2025.
//

#include "game.hpp"

#include <iostream>
#include <__ostream/basic_ostream.h>

Game::Game()
{

}


void Game::GameInit(SDL_Renderer *renderer)
{
    texture = nullptr;
    texture = IMG_LoadTexture(renderer,"Resources/Background/BackgroundImage.png");
}


void Game::GameRender(SDL_Renderer *renderer)
{
    if (texture == nullptr)
    {
        std::cout << "Background Texture is null" << std::endl;
    }

    SDL_RenderTexture(renderer, texture, nullptr, nullptr);
}

void Game::GameUpdate(float deltaTime)
{
}

Game::~Game()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}
