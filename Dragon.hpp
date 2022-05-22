#include "fishes.hpp"
#include "Boat.hpp"
#include "fire.hpp"
#include <string>
#include <iostream>
using namespace std;
#pragma once
class Dragon : public Fishes
{
    SDL_Rect src[6];              //frames for animation
    int life;                     // dragon animation
    int xdirection, ydirection;  // x=0 means right, y=0 means up and vice versa
    Fire DragonFire;               //Fire of dragon
    bool fishReleased;              //check if fish released
public:
    Dragon(SDL_Texture *, SDL_Texture *);
    ~Dragon();
    void Swim();                    // swimming animation
    void draw(SDL_Renderer *,int);  //frame animation
    bool burnBoat(Boat *);          //boat burns when fire hits boat
    void fishThrown(bool);          // change animation if fish thrown
};
