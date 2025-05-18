//
// Created by Jason Evans on 18/05/2025.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "SDL3/SDL.h"


class Player {

public:
    Player();
    ~Player();




    // Idle Textures
    SDL_Texture *playerSideIdleTexture;
    SDL_Texture *playerUpIdleTexture;
    SDL_Texture *playerDownIdleTexture;

    // Walk Textures
    SDL_Texture *playerSideWalkTexture;
    SDL_Texture *playerUpWalkTexture;
    SDL_Texture *playerDownWalkTexture;

    // Rectangles

    SDL_FRect destRect;
    SDL_FRect srcRect;

    // Variables
    bool isWalking;
    bool isRunning;
    bool isDead;
    bool isFacingLeft;
    int playerHealth;
    float playerSpeed;

    // Functions
    void PlayerInit(SDL_Renderer *renderer);
    void CheckForTextureLoad() const;
    void PlayerRender(SDL_Renderer *renderer) const;
    void PlayerUpdate(float deltaTime, SDL_Renderer *renderer);


private:

};



#endif //PLAYER_HPP
