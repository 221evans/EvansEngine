//
// Created by Jason Evans on 17/05/2025.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Entities/player.hpp"
#include "Entities/enemy.hpp"
#include "SDL3/SDL.h"
#include "../Core/gem.hpp"
#include "SDL3_image/SDL_image.h"


class Game {

    public:
        Game();
        ~Game();

    Player player;
    Enemy enemy;
    Gem gem;

    // Variables
    SDL_Texture *texture;

    // Functions
    void GameInit(SDL_Renderer *renderer);
    void GameRender(SDL_Renderer *renderer);
    void GameUpdate(float deltaTime, SDL_Renderer *renderer);

    private:



};



#endif //GAME_HPP
