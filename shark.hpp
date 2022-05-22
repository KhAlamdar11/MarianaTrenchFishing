#include "fishes.hpp"
#include "Boat.hpp"
#include "hook.hpp"
#include <string>
#include <iostream>
using namespace std;
#pragma once
class shark : public Fishes
{
    SDL_Rect src[9];   //src for animation

public:
    int life;
    int direction;
    int time;
    bool aggro;
    bool state;
    shark(SDL_Texture *);
    ~shark();
    void Swim(bool);            // swimming animation
    void draw(SDL_Renderer *, bool);       //frames animation
    bool attack(Boat *);        // boat shark collision detection
    void Rise(Boat *);          // vertical movement of shark
    void Fall(Boat *);
    bool sharkHit(Hook *);      // hook shark collision
};