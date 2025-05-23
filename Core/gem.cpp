//
// Created by Jason Evans on 22/05/2025.
//

#include "gem.hpp"

Gem::Gem()
{
}
Gem::~Gem()
{

}


void Gem::DropGem(SDL_Renderer* renderer, int centerX, int centerY, int radius)
{
    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -radius; x <= radius; x++)
        {
            if ((x * x + y * y) <= (radius * radius))
            {
                SDL_RenderPoint(renderer, centerX + x, centerY + y);
            }
        }
    }

}
