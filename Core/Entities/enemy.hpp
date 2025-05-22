//
// Created by Jason Evans on 22/05/2025.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "SDL3_image/SDL_image.h"
#include "SDL3/SDL.h""
#include "../loadTextures.hpp"

class Enemy {

public:

    Enemy();
    ~Enemy();

    LoadTextures textures;

    // Rectangles
    SDL_FRect destRect{};
    SDL_FRect srcRect{};

    int enemyPosX;
    int enemyPosY;

    void Update(SDL_Renderer *renderer, float deltaTime);
    void Init(SDL_Renderer *renderer);

private:
    void EnemyRender(SDL_Renderer *renderer);


};



#endif //ENEMY_HPP
