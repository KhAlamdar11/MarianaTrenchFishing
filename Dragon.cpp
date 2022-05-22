#include "Dragon.hpp"
#pragma once
Dragon::Dragon(SDL_Texture *tex, SDL_Texture *fire) : Fishes()
{
    src[1] = {0, 468, 512, 161};
    src[0] = {512, 468, 505, 161};

    src[3] = {0, 629, 512, 161};
    src[2] = {512, 629, 505, 161};

    src[5] = {0, 790, 512, 161};
    src[4] = {512, 790, 505, 161};
    mover = {-500, 80, 450, 142};
    assets = tex;
    life = 0;
    xdirection = 0;
    ydirection = rand() % 2;
    frame = 0;
    fishReleased = false;
    DragonFire.setAssets(fire);
}
Dragon::~Dragon()
{
    cout << "Dragon destroyed" << endl;
}
void Dragon::Swim()
{
    if (xdirection == 0 && mover.x >= 1250)
    {
        ydirection = rand() % 2;
        xdirection = 1;
        //Right to Left
        src[0] = {0, 0, 512, 161};
        src[1] = {512, 0, 512, 161};
        src[2] = {0, 161, 512, 161};
        src[3] = {512, 161, 512, 161};
        src[4] = {0, 322, 512, 161};
        src[5] = {512, 322, 512, 161};
        mover.y = (rand() % 286) + 123;
    }
    else if (xdirection == 1 && mover.x <= -550)
    {
        xdirection = 0;
        ydirection = rand() % 2;
        //Left
        src[1] = {0, 468, 512, 161};
        src[0] = {512, 468, 505, 161};

        src[3] = {0, 629, 512, 161};
        src[2] = {512, 629, 505, 161};

        src[5] = {0, 790, 512, 161};
        src[4] = {512, 790, 505, 161};
        mover.y = (rand() % 286) + 123;
    }
    else if (xdirection == 0)
    {
        mover.x += 3;
    }
    else if (xdirection == 1)
    {
        mover.x -= 3;
    }
    if (mover.y <= 124)
    {
        ydirection = 1; //down now
    }
    else if (mover.y >= 409)
    {
        ydirection = 0; //down now
    }
    if (ydirection == 0)
        mover.y -= 1;
    else
        mover.y += 1;
    DragonFire.moveFire(mover, xdirection, frame);
}

void Dragon::draw(SDL_Renderer *renderer, int xcor)
{
    if (fishReleased == false)
    {
        SDL_RenderCopy(renderer, assets, &src[frame / 12], &mover); //This allows the Units to have flying animation
        frame++;
        if (frame == 72)
            frame = 0;
        Swim();
        DragonFire.draw(renderer);
    }
    else
    {
        mover.y = 400;
        if (xdirection == 0)
        {
            mover.x = xcor - 450;
        }
        else if (xdirection == 1)
        {
            mover.x = xcor + 140;
        }
        SDL_RenderCopy(renderer, assets, &src[frame / 20], &mover); //This allows the Units to have flying animation
        frame++;
        if (frame == 120)
            frame = 0;
        DragonFire.setMover(-400, DragonFire.getMover().y, DragonFire.getMover().w, DragonFire.getMover().h);
    }
}

bool Dragon::burnBoat(Boat *boat)
{
    return DragonFire.burnItAll(boat);
}
void Dragon::fishThrown(bool b)
{
    fishReleased = b;
}