//
// Created by Jason Evans on 18/05/2025.
//

#include "animation.hpp"

Animation::Animation()
{
    currentFrame = 0;
    frameSpeed = 6;
    totalFrames = 4;
    frameTimer = 0.0f;
    frameCount = 0;
}



void Animation::PlayerHandleWalk(bool isWalking, bool isIdle, float deltaTime)
{
   if (isWalking)
   {
       frameTimer += deltaTime;

       if (frameTimer >= (1.0f / frameSpeed))
       {
           frameTimer = 0.0f;
           currentFrame++;
           if (currentFrame >= totalFrames)
           {
               currentFrame = 0;
           }
       }
   }
else if (isIdle)
    {
        PlayerHandleIdle(deltaTime);
    }




}

void Animation::PlayerHandleIdle(float deltaTime)
{
    frameTimer += deltaTime;

    float idleFrameSpeed = frameSpeed / 1.5f;

    if (frameTimer >= (1.0f / idleFrameSpeed))
    {
        frameTimer = 0.0f;
        currentFrame++;
        if (currentFrame >= totalFrames)
        {
            currentFrame = 0;
        }
    }
}

Animation::~Animation()
{

}
