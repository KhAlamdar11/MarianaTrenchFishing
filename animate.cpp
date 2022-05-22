#include "animate.hpp"
#include <iostream>
#include <limits>
using namespace std;
#pragma once

Anime::Anime(int a, SDL_Texture *tex) // This class is for boosters
{
    LT = 0;
    interval = 0;
    if (a == 1)
    {
        TTL = 54;
        src[0] = {80, 1120, 70, 70};
        src[1] = {80, 1120, 70, 70};
        src[2] = {1370, 90, 70, 70};
        src[3] = {1370, 90, 70, 70};
        src[4] = {80, 340, 90, 90};
        src[5] = {80, 340, 90, 90};
        src[6] = {330, 340, 100, 100};
        src[7] = {330, 340, 100, 100};
        src[8] = {580, 330, 110, 110};
        src[9] = {580, 330, 110, 110};
        src[10] = {830, 320, 120, 120};
        src[11] = {830, 320, 120, 120};
        src[12] = {1080, 310, 140, 140};
        src[13] = {1080, 310, 140, 140};
        src[14] = {1330, 310, 140, 140};
        src[15] = {1330, 310, 140, 140};
        src[16] = {50, 570, 160, 160};
        src[17] = {50, 570, 160, 160};
        mover = {350, 280, 100, 70};
        assets = tex;
    }
    if (a == 2)
    {
        TTL = -1; //This means that the item have infinite time to live
        src[0] = {0, 0, 65, 80};
        src[1] = {110, 0, 70, 80};
        src[2] = {230, 0, 70, 80};
        src[3] = {340, 0, 70, 80};
        src[4] = {460, 0, 55, 80};
        src[5] = {0, 120, 60, 86};
        src[6] = {105, 120, 70, 86};
        src[7] = {220, 120, 70, 86};
        src[8] = {340, 120, 70, 86};
        src[9] = {460, 120, 56, 86};
        mover = {350, 280, 100, 70};
        assets = tex;
    }
    if (a == 3) // Move faster Boost
    {
        version = 3;
        cout << "Created a Boost" << endl;
        TTL = 900;
        src[0] = {749, 136, 125, 139};
        mover = {(rand() % 480) + 120, (rand() % 460) + 120, 50, 50};
        assets = tex;
    }
    if (a == 4) // Fish Frenzy Boost
    {
        version = 4;
        cout << "Fish Frenzy" << endl;
        TTL = 900;
        src[0] = {250, 195, 130, 105};
        mover = {(rand() % 480) + 120, (rand() % 460) + 120, 50, 50};
        assets = tex;
    }
    if (a == 5) // Time Freeze
    {
        version = 5;
        cout << "Time Stop" << endl;
        TTL = 900;
        src[0] = {875, 340, 175, 120};
        mover = {(rand() % 480) + 120, (rand() % 460) + 120, 50, 50};
        assets = tex;
    }
}

void Anime::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, assets, &src[frame], &mover); //This allows the Units to have flying animation
    if (interval == 3)
    {
        frame++;
        interval = 0;
    }
    LT++;
    interval++;
    if (frame == 17)
        frame = 0;
}
void Anime::draw_frame(SDL_Renderer *renderer)
{
    LT++;
    SDL_RenderCopy(renderer, assets, &src[frame], &mover);
}

bool Anime::check_life()
{
    if (LT == TTL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
Anime::~Anime()
{
    cout << "Animation was destroyed" << endl;
}
int Anime::get_version()
{
    return version;
}