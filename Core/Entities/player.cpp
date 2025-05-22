//
// Created by Jason Evans on 18/05/2025.
//

#include "player.hpp"

Player::Player()
{
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
  textures.LoadPlayerTextures(renderer);
}



void Player::CheckForTextureLoad() const
{
    textures.CheckForPlayerTextureLoad();
}


void Player::PlayerRender(SDL_Renderer* renderer, SDL_Texture *currentTexture) const
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

    // Track players last direction for idle animation
    static bool lastMovingUp = false;
    static bool lastMovingDown = false;


    // Update last direction if the player is moving
    if (isWalking)
    {
        lastMovingUp = movingUp && !movingDown && !movingSide;
        lastMovingDown = movingDown && !movingUp && !movingSide;
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
            currentTexture = textures.playerUpWalkTexture;
        } else if (movingDown && !movingUp && !movingSide) {
            currentTexture = textures.playerDownWalkTexture;
        } else {
            currentTexture = textures.playerSideWalkTexture;
        }
    } else {
        // Idle
        if (lastMovingUp)
        {
            currentTexture = textures.playerUpIdleTexture;
        }
        else if (lastMovingDown)
        {
            currentTexture = textures.playerDownIdleTexture;
        }
        else
        {
            currentTexture = textures.playerSideIdleTexture;
        }

    }

    // If no texture was selected use default
    if (currentTexture == nullptr) {
        currentTexture = textures.playerSideIdleTexture;
    }

    // Render the player with the selected texture
    PlayerRender(renderer, currentTexture);
}


Player::~Player()
{
    textures.DestroyPlayerTextures();
}