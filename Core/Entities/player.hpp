//
// Created by Jason Evans on 18/05/2025.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "SDL3/SDL.h"
#include "Animation/animation.hpp"

class Player {

public:
    Player();
    ~Player();

    Animation animation;

    // Idle Textures
    SDL_Texture *playerSideIdleTexture;
    SDL_Texture *playerUpIdleTexture;
    SDL_Texture *playerDownIdleTexture;

    // Walk Textures
    SDL_Texture *playerSideWalkTexture;
    SDL_Texture *playerUpWalkTexture;
    SDL_Texture *playerDownWalkTexture;

    // Rectangles

    SDL_FRect destRect{};
    SDL_FRect srcRect{};

    // Variables
    bool isWalking;
    bool isRunning;
    bool isDead;
    bool isFacingLeft;
    bool isIdle;
    int playerHealth;
    float playerSpeed;
    float playerPosX;
    float playerPosY;




    // Functions
    void PlayerInit(SDL_Renderer *renderer);
    void CheckForTextureLoad() const;
    void PlayerUpdate(float deltaTime, SDL_Renderer *renderer);


private:
    void PlayerRender(SDL_Renderer *renderer, SDL_Texture *currentTexture);

};



#endif //PLAYER_HPP
