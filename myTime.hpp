#include "SDL.h"
#include "unit.hpp"
#include <string>
#pragma once

class myTime : public Unit
{
    int startTime, currentTime, lastTime;   //time track
    SDL_Rect mover[4];       // 3 digits to display & 1 dot
    SDL_Rect src[10];       // 0-9 digits for display

    public:
    myTime(SDL_Texture *);
    ~myTime();
    void start(int);        //start time
    int getTime();          //return time
    void displayTime(int,SDL_Renderer *);
};