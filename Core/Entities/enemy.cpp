//
// Created by Jason Evans on 22/05/2025.
//

#include "enemy.hpp"

Enemy::Enemy()
{
    enemyPosX = 400;
    enemyPosY = 250;
    srcRect = (SDL_FRect) {0, 0, 64, 64};
    destRect = (SDL_FRect) {0, 0, 64, 64};
}


void Enemy::Update(SDL_Renderer *renderer, float deltaTime)
{
    EnemyRender(renderer);
}

void Enemy::Init(SDL_Renderer* renderer)
{
    textures.LoadEnemyTextures(renderer);
}

void Enemy::EnemyRender(SDL_Renderer* renderer)
{
    SDL_RenderTexture(renderer,textures.zombieBaseIdleTexture,&srcRect,&destRect);
}



Enemy::~Enemy()
{
    textures.DestroyEnemyTextures();
}