//
// Created by Jason Evans on 17/05/2025.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"


class Game {

    public:
        Game();
        ~Game();

    // Variables
    SDL_Texture *texture;

    // Methods
    void GameInit(SDL_Renderer *renderer);
    void GameRender(SDL_Renderer *renderer);
    void GameUpdate(float deltaTime);

    private:



};



#endif //GAME_HPP
