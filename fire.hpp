#include "unit.hpp"
#include "Boat.hpp"
#include <string>
#include <iostream>
using namespace std;
#pragma once
class Fire : public Unit
{
    SDL_Rect src[6];
    int xdirection;                     // direction of dragon and fire
public:
    Fire();
    void moveFire(SDL_Rect,int,int);     //sync fire and dragon
    void draw(SDL_Renderer *);          //fire animation
    bool burnItAll(Boat *);             //collission detected of fire and boat
};
