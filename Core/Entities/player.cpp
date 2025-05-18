//
// Created by Jason Evans on 18/05/2025.
//

#include "player.hpp"

#include <iostream>
#include <__ostream/basic_ostream.h>

#include "SDL3_image/SDL_image.h"


Player::Player()
{
    // Idle Textures
    playerSideIdleTexture = nullptr;
    playerUpIdleTexture = nullptr;
    playerDownIdleTexture = nullptr;
    // Walk Textures
    playerSideWalkTexture = nullptr;
    playerUpWalkTexture = nullptr;
    playerDownWalkTexture = nullptr;

    // Rectangles
    destRect = (SDL_FRect) {250, 250, 64, 64};
    srcRect = (SDL_FRect) {0, 0, 64, 64};


    isWalking = false;
    isRunning = false;
    isDead = false;
    isFacingLeft = false;
    playerHealth = 100;
    playerSpeed = 100;
}


void Player::PlayerInit(SDL_Renderer* renderer)
{
    // Idle
    playerSideIdleTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Idle/Idle-Side-Sheet.png");
    playerUpIdleTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Idle/Idle-Up-Sheet.png");
    playerDownIdleTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Idle/Idle-Down-Sheet.png");
    // Walk
    playerSideWalkTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Walk/Walk-Side-Sheet.png");
    playerUpWalkTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Walk/Walk-Up-Sheet.png");
    playerDownWalkTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Walk/Walk-Down-Sheet.png");


    CheckForTextureLoad();
}



void Player::CheckForTextureLoad() const
{
    if (playerSideIdleTexture == nullptr)
    {
        std::cout << "Player Side Idle Texture is null" << std::endl;
    }

    if (playerUpIdleTexture == nullptr)
    {
        std::cout << "Player Up Idle Texture is null" << std::endl;
    }
    if (playerDownIdleTexture == nullptr)
    {
        std::cout << "Player Down Idle Texture is null" << std::endl;
    }

    if (playerSideWalkTexture == nullptr)
    {
        std::cout << "Player Side Walk Texture is null" << std::endl;
    }
    if (playerUpWalkTexture == nullptr)
    {
        std::cout << "Player Up Walk Texture is null" << std::endl;
    }
    if (playerDownWalkTexture == nullptr)
    {
        std::cout << "Player Down Walk Texture is null" << std::endl;
    }
}

void Player::PlayerRender(SDL_Renderer* renderer) const
{

    double angle = 0.0;
    SDL_FPoint center = {srcRect.w / 2.0f, srcRect.h / 2.0f};


    SDL_FlipMode flipMode = SDL_FLIP_NONE;

    SDL_Texture* currentTexture = nullptr;

    currentTexture = playerSideIdleTexture;

    if (isFacingLeft)
    {
        flipMode = SDL_FLIP_HORIZONTAL;
    }

    SDL_RenderTextureRotated(renderer,currentTexture,&srcRect,&destRect,angle,&center,flipMode);
}

void Player::PlayerUpdate(float deltaTime, SDL_Renderer *renderer)
{
    const bool* keyboardState = SDL_GetKeyboardState(nullptr);
    if (keyboardState[SDL_SCANCODE_W])
    {
        destRect.y -= playerSpeed * deltaTime; // Move Up

    }
    if (keyboardState[SDL_SCANCODE_S])
    {
        destRect.y += playerSpeed * deltaTime; // Move Down

    }
    if (keyboardState[SDL_SCANCODE_A])
    {
        destRect.x -= playerSpeed * deltaTime; // Move Left
        isFacingLeft = true;
    }
    if (keyboardState[SDL_SCANCODE_D])
    {
        destRect.x += playerSpeed * deltaTime; // Move Right
        isFacingLeft = false;
    }

    PlayerRender(renderer);
}


Player::~Player()
{
    if (playerSideIdleTexture != nullptr)
    {
        SDL_DestroyTexture(playerSideIdleTexture);
        playerSideIdleTexture = nullptr;
    }

    if (playerUpIdleTexture != nullptr)
    {
        SDL_DestroyTexture(playerUpIdleTexture);
        playerUpIdleTexture = nullptr;
    }
    if (playerDownIdleTexture != nullptr)
    {
        SDL_DestroyTexture(playerDownIdleTexture);
        playerDownIdleTexture = nullptr;
    }
    if (playerSideWalkTexture != nullptr)
    {
        SDL_DestroyTexture(playerSideWalkTexture);
        playerSideWalkTexture = nullptr;
    }
    if (playerUpWalkTexture != nullptr)
    {
        SDL_DestroyTexture(playerUpWalkTexture);
        playerUpWalkTexture = nullptr;
    }
    if (playerDownWalkTexture != nullptr)
    {
        SDL_DestroyTexture(playerDownWalkTexture);
        playerDownWalkTexture = nullptr;
    }
}
