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


    playerPosX = 250;
    playerPosY = 250;

    // Rectangles
    destRect = (SDL_FRect) {playerPosX, playerPosY, 64, 64};
    srcRect = (SDL_FRect) {0, 0, 64, 64};


    isIdle = true;
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

void Player::PlayerRender(SDL_Renderer* renderer, SDL_Texture *currentTexture)
{

    double angle = 0.0;
    SDL_FPoint center = {srcRect.w / 2.0f, srcRect.h / 2.0f};
    SDL_FlipMode flipMode = SDL_FLIP_NONE;

    if (isFacingLeft)
    {
        flipMode = SDL_FLIP_HORIZONTAL;
    }

    SDL_RenderTextureRotated(renderer,currentTexture,&srcRect,&destRect,angle,&center,flipMode);
}

void Player::PlayerUpdate(float deltaTime, SDL_Renderer *renderer)
{
    // Reset movement flags
    bool movingUp = false;
    bool movingDown = false;
    bool movingSide = false;
    
    // Reset animation states
    isWalking = false;
    isIdle = true;

    // Check keyboard input and update movement
    const bool* keyboardState = SDL_GetKeyboardState(nullptr);
    if (keyboardState[SDL_SCANCODE_W])
    {
        destRect.y -= playerSpeed * deltaTime; // Move Up
        isWalking = true;
        isIdle = false;
        movingUp = true;
    }
    if (keyboardState[SDL_SCANCODE_S])
    {
        destRect.y += playerSpeed * deltaTime; // Move Down
        isWalking = true;
        isIdle = false;
        movingDown = true;
    }
    if (keyboardState[SDL_SCANCODE_A])
    {
        destRect.x -= playerSpeed * deltaTime; // Move Left
        isFacingLeft = true;
        isWalking = true;
        isIdle = false;
        movingSide = true;
    }
    if (keyboardState[SDL_SCANCODE_D])
    {
        destRect.x += playerSpeed * deltaTime; // Move Right
        isFacingLeft = false;
        isWalking = true;
        isIdle = false;
        movingSide = true;
    }

    // Update animation
    animation.PlayerHandleWalk(isWalking, isIdle, deltaTime);
    
    // Update source rectangle for animation frame
    srcRect.x = static_cast<float>(animation.currentFrame) * 64;

    // Select the appropriate texture based on player state and movement direction
    SDL_Texture *currentTexture = nullptr;

    if (isWalking) {
        // Walking textures
        if (movingUp && !movingDown && !movingSide) {
            currentTexture = playerUpWalkTexture;
        } else if (movingDown && !movingUp && !movingSide) {
            currentTexture = playerDownWalkTexture;
        } else {
            currentTexture = playerSideWalkTexture;
        }
    } else {
        // Idle
        currentTexture = playerSideIdleTexture;
    }

    // If no texture was selected use default
    if (currentTexture == nullptr) {
        currentTexture = playerSideIdleTexture;
    }

    // Render the player with the selected texture
    PlayerRender(renderer, currentTexture);
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