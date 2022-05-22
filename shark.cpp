#include "shark.hpp"
#include <cstdlib>
shark::shark(SDL_Texture *tex) : Fishes()
{
    src[0] = {560, 0, 200, 80};
    src[1] = {760, 0, 200, 80};
    src[2] = {975, 0, 205, 80};

    src[3] = {560, 80, 200, 80};
    src[4] = {760, 80, 200, 80};

    src[5] = {560, 160, 200, 80};
    src[6] = {760, 160, 200, 80};

    src[7] = src[5];
    src[8] = src[0];
    mover = {-200, 250, 200, 80};
    assets = tex;
    life = 3;
    direction = 0;
    dead = 0;
    frame = 0;
    time = 1;
    aggro = false;
    state = false;
}
shark::~shark()
{
    cout << "shark destroyed" << endl;
}
void shark::Swim(bool kick)
{
    state = kick;
    if (direction == 0 && getMover().x >= 600)
    {
        if (kick == false)
        {
            direction = 1;
            //Right to Left
            src[0] = {792, 248, 170, 80};
            src[1] = {1018, 248, 167, 77};
            src[2] = {1239, 243, 130, 84};

            src[3] = {563, 330, 103, 76};
            src[4] = {663, 333, 93, 75};

            src[5] = {762, 329, 92, 79};
            src[6] = {852, 327, 109, 82};

            src[7] = {959, 330, 127, 76};
            src[8] = {1085, 329, 154, 82};
        }
    }
    else if (direction == 1 && frame == 0)
    {
        direction = 2;
        //Left
        src[0] = {1167, 411, 200, 80};
        src[1] = {970, 408, 200, 80};
        src[2] = {747, 418, 200, 80};

        src[3] = {1168, 491, 200, 80};
        src[4] = {966, 494, 200, 80};

        src[5] = {1167, 578, 200, 80};
        src[6] = {962, 579, 200, 80};

        src[7] = src[5];
        src[8] = src[0];
    }
    else if (direction == 2 && getMover().x <= 2)
    {
        if (kick == false)
        {
            direction = 3;
            //Left to right
            src[0] = {962, 662, 169, 78};
            src[1] = {748, 661, 154, 77};
            src[2] = {550, 660, 139, 70};

            src[3] = {1263, 745, 97, 74};
            src[4] = {1172, 744, 84, 76};

            src[5] = {1071, 745, 97, 73};
            src[6] = {964, 737, 107, 82};

            src[7] = {841, 738, 125, 82};
            src[8] = {686, 737, 155, 83};
        }
    }
    else if (direction == 3 && frame == 0)
    {
        direction = 0;
        //Right
        src[0] = {560, 0, 200, 80};
        src[1] = {760, 0, 200, 80};
        src[2] = {975, 0, 205, 80};

        src[3] = {560, 80, 200, 80};
        src[4] = {760, 80, 200, 80};

        src[5] = {560, 160, 200, 80};
        src[6] = {760, 160, 200, 80};

        src[7] = src[5];
        src[8] = src[0];
    }

    if ((direction == 0 || (direction == 1 && frame < 45) || (direction == 3 && frame > 45)) && mover.x < 1100)
        setMover(getMover().x + 2, getMover().y, getMover().w, getMover().h);
    else if ((direction == 2 || (direction == 1 && frame >= 45) || (direction == 3 && frame <= 45)) && mover.x > -300)
        setMover(getMover().x - 2, getMover().y, getMover().w, getMover().h);
}

void shark::draw(SDL_Renderer *renderer, bool kick)
{
    if (life <= 0)
        dead = 1;
    if (mover.y >= 550)
        dead = 2;
    if (dead == 0)
    {
        setMover(getMover().x, getMover().y, src[frame / 9].w, src[frame / 9].h);
        SDL_RenderCopy(renderer, assets, &src[frame / 9], &mover); //This allows the Units to have flying animation
        frame++;
        if (frame == 81)
            frame = 0;
        Swim(kick);
    }
    else if (dead == 1)
    {
        mover.y += 1;
        SDL_RenderCopy(renderer, assets, &src[5], &mover);
    }
}
bool shark::attack(Boat *boat)
{
    bool retbool = false;
    //Base of boat, {edge left x,edge right x, base y}
    int boatDims[3] = {boat->getMover().x + 25, boat->getMover().x + 98, boat->getMover().y + 83};
    int sharkFace[2];
    sharkFace[0] = 0;
    if (direction == 0)
    {
        sharkFace[0] = mover.x + mover.w;
        sharkFace[1] = mover.y + (mover.h) / 2; // x,y of shark's mouth
        if (sharkFace[0] > boatDims[0] - 10 && sharkFace[0] < (boatDims[1] - 62) && sharkFace[1] < (boatDims[2] + 20))
        {
            retbool = true;
        }
    }
    else if (direction == 2)
    {
        sharkFace[0] = mover.x;
        sharkFace[1] = mover.y + (mover.h) / 2; // x,y of shark's mouth
        if (sharkFace[0] > (boatDims[0] - 10) && sharkFace[0] < (boatDims[1] + 10) && sharkFace[1] < (boatDims[2] + 5))
        {
            retbool = true;
        }
    }
    if (time % 1001 == 0 && mover.y == 250)
        aggro = true;
    time += 2;

    if ((time % 15501 >= 15000 && aggro == false) || state == true)
    {
        Fall(boat);
    }
    else if (aggro == true && state == false)
    {
        Rise(boat); //crash site.
    }

    return retbool;
}

void shark::Rise(Boat *boat)
{
    double y = boat->getMover().y - mover.y;
    double x = 0;
    if (direction == 0)
        x = boat->getMover().x - mover.x - 50;
    else if (direction == 2)
        x = boat->getMover().x - mover.x;

    if ((direction == 0 && x > 0) && abs(x) > 1.2 * abs(y) && abs(x) < 2 * abs(y))
    {
        setMover(mover.x + ((x + 800) / 1000), mover.y - ((750 - y) / 1000), mover.w, mover.h);
    }
    else if (direction == 2 && x < 0 && abs(x) > 1.2 * abs(y) && abs(x) < 2 * abs(y))
    {
        setMover(mover.x + (x / 1000), mover.y - ((750 - y) / 1000), mover.w, mover.h);
    }
    if (mover.y < 60)
    {
        time++;
        aggro = false;
    }
}
void shark::Fall(Boat *boat)
{
    if (mover.y < 250)
    {
        double x = boat->getMover().x - mover.x;
        double y = boat->getMover().y - mover.y;
        setMover(mover.x + (x / 1000), mover.y + 1, mover.w, mover.h);
    }
}

bool shark::sharkHit(Hook *hook)
{
    int hookDims[2] = {hook->getMover().x, hook->getMover().y};
    int sharkFace[2];
    bool retbool = false;
    sharkFace[0] = 0;
    if (dead != 1)
    {
        if (direction == 0)
        {
            sharkFace[0] = mover.x + mover.w;
            sharkFace[1] = mover.y + (mover.h) / 2; // x,y of shark's mouth
            if ((hookDims[0] > sharkFace[0] - 50) && (hookDims[1] < sharkFace[0]) && (hookDims[1] < mover.y + mover.h) && (hookDims[1] > mover.y) && (hookDims[0] < sharkFace[0] + 50))
            {
                retbool = true;
            }
        }
        else if (direction == 2)
        {
            sharkFace[0] = mover.x;
            sharkFace[1] = mover.y + (mover.h) / 2; // x,y of shark's mouth
            if ((hookDims[0] > sharkFace[0] - 50) && (hookDims[1] < sharkFace[0]) && (hookDims[1] < mover.y + mover.h) && (hookDims[1] > mover.y) && (hookDims[0] < sharkFace[0] + 50))
            {
                retbool = true;
            }
        }
    }
    return retbool;
}