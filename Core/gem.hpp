//
// Created by Jason Evans on 22/05/2025.
//

#ifndef GEM_HPP
#define GEM_HPP

#include "SDL3/SDL.h"

class Gem {

public:
        Gem();
        ~Gem();

        void DropGem(SDL_Renderer *renderer, int centerX, int centerY, int radius);
};



#endif //GEM_HPP
