//
// Created by Jason Evans on 18/05/2025.
//

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "SDL3_image/SDL_image.h"


class Animation {

public:
        Animation();
        ~Animation();
    int currentFrame;
    int frameSpeed;
    int frameCount;
    int totalFrames;
    bool isAttacking;
    float frameTimer;

    void PlayerHandleWalk(bool isWalking, bool isIdle, float deltaTime);
    void PlayerHandleIdle(float deltaTime);
    void PlayerHandleAttack(bool isAttacking, float deltaTime);
};



#endif //ANIMATION_HPP
