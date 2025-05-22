//
// Created by Jason Evans on 19/05/2025.
//

#ifndef LOADTEXTURES_HPP
#define LOADTEXTURES_HPP

#include "SDL3/SDL.h"


class LoadTextures {

    public:
        LoadTextures();

    // Player Idle Textures
    SDL_Texture *playerSideIdleTexture;
    SDL_Texture *playerUpIdleTexture;
    SDL_Texture *playerDownIdleTexture;

    // Player Walk Textures
    SDL_Texture *playerSideWalkTexture;
    SDL_Texture *playerUpWalkTexture;
    SDL_Texture *playerDownWalkTexture;

    // Player Attack Textures
    SDL_Texture *playerAttackSideTexture;
    SDL_Texture *playerAttackUpTexture;
    SDL_Texture *playerAttackDownTexture;

    // Enemy Idle Textures
    SDL_Texture *zombieBaseIdleTexture;
    SDL_Texture *zombieBansheeIdleTexture;
    SDL_Texture *zombieOverweightIdleTexture;

    void LoadPlayerTextures(SDL_Renderer *renderer);
    void CheckForPlayerTextureLoad() const;
    void DestroyPlayerTextures();

    void LoadEnemyTextures(SDL_Renderer *renderer);
    void CheckForEnemyLoadTextures() const;
    void DestroyEnemyTextures();
};



#endif //LOADTEXTURES_HPP
