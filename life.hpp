#pragma once
#include "unit.hpp"
#include "SDL.h"
#ifndef LIFE_H
#define LIFE_H
class life : public Unit
{
public:
    life();              //Default Constructor
    life(SDL_Texture *,int); //Overloaded constructor
    ~life();
};
#endif