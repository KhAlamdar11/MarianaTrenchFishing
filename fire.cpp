#include "fire.hpp"
#pragma once
Fire::Fire() : Unit()
{
    src[0] = {0, 200, 104, 200};
    src[1] = {104, 200, 104, 200};
    src[2] = {208, 200, 104, 200};
    src[3] = {312, 200, 104, 200};
    src[4] = {416, 200, 104, 200};
    src[5] = {520, 200, 104, 200};

    mover = {-400, 13, 125, 250};
    xdirection = 0;
    frame = 0;
}

void Fire::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, assets, &src[frame / 10], &mover); //This allows the Units to have flying animation
    frame++;
    if (frame == 60)
        frame = 0;
}

void Fire::moveFire(SDL_Rect DragonMover, int dir, int fr)
{
    xdirection = dir;
    if (dir == 1) //Dragon moving left
    {
        src[0] = {0, 0, 104, 200};
        src[1] = {104, 0, 104, 200};
        src[2] = {208, 0, 104, 200};
        src[3] = {312, 0, 104, 200};
        src[4] = {416, 0, 104, 200};
        src[5] = {520, 0, 104, 200};
        mover.x = DragonMover.x - 110;
    }
    else if (dir == 0) //Dragon moving right
    {
        src[0] = {0, 200, 104, 200};
        src[1] = {104, 200, 104, 200};
        src[2] = {208, 200, 104, 200};
        src[3] = {312, 200, 104, 200};
        src[4] = {416, 200, 104, 200};
        src[5] = {520, 200, 104, 200};
        mover.x = DragonMover.x + 430;
    }
    if (fr >= 0 && fr < 36)
        mover.h = DragonMover.y + 35;
    else
        mover.h = DragonMover.y + 71;
}

bool Fire::burnItAll(Boat *boat)
{
    bool retbool = false;
    if ((mover.x + 115) > boat->getMover().x  && mover.x < boat->getMover().x + 40)
        retbool = true;
    return retbool;
}
