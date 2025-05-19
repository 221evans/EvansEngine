//
// Created by Jason Evans on 19/05/2025.
//

#include "loadTextures.hpp"
#include "SDL3_image/SDL_image.h"
#include "iostream"

LoadTextures::LoadTextures()
{
    // Idle
    playerSideIdleTexture = nullptr;
    playerUpIdleTexture = nullptr;
    playerDownIdleTexture = nullptr;
    // Walk
    playerSideWalkTexture = nullptr;
    playerUpWalkTexture = nullptr;
    playerDownWalkTexture = nullptr;
    // Attack
    playerAttackSideTexture = nullptr;
    playerAttackUpTexture = nullptr;
    playerAttackDownTexture = nullptr;
}

void LoadTextures::LoadPlayerTextures(SDL_Renderer* renderer)
{
    // Idle
    playerSideIdleTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Idle/Idle-Side-Sheet.png");
    playerUpIdleTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Idle/Idle-Up-Sheet.png");
    playerDownIdleTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Idle/Idle-Down-Sheet.png");
    // Walk
    playerSideWalkTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Walk/Walk-Side-Sheet.png");
    playerUpWalkTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Walk/Walk-Up-Sheet.png");
    playerDownWalkTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Walk/Walk-Down-Sheet.png");
    // Attack
    playerAttackSideTexture = IMG_LoadTexture(renderer,"Resources/Hunter/Attack/Slice-Side-Sheet.png");
    playerAttackUpTexture = IMG_LoadTexture(renderer, "Resources/Hunter/Attack/Slice-Up-Sheet.png");
    playerAttackDownTexture = IMG_LoadTexture(renderer, "Resources/Hunter/Attack/Slice-Down-Sheet.png");
}

void LoadTextures::CheckForTextureLoad() const
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
    if (playerAttackSideTexture == nullptr)
    {
        std::cout << "Player Attack side texture is null" << std::endl;
    }
    if (playerAttackUpTexture == nullptr)
    {
        std::cout << "Player Attack up texture is null" << std::endl;
    }
    if (playerAttackDownTexture == nullptr)
    {
        std::cout << "Player Attack up texture is null" << std::endl;
    }
}

void LoadTextures::DestroyPlayerTextures()
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
    if (playerAttackSideTexture != nullptr)
    {
        SDL_DestroyTexture(playerAttackSideTexture);
        playerAttackSideTexture = nullptr;
    }
    if (playerAttackUpTexture != nullptr)
    {
        SDL_DestroyTexture(playerAttackUpTexture);
        playerAttackUpTexture = nullptr;
    }
    if (playerAttackDownTexture != nullptr)
    {
        SDL_DestroyTexture(playerAttackDownTexture);
        playerAttackDownTexture = nullptr;
    }
}


