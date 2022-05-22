#include "SDL.h"
#include <string>
#pragma once
#ifndef UNIT_H
#define UNIT_H
class Unit
{
protected:
    SDL_Texture *assets;        //SDL textues of an object
    SDL_Rect src[3];
    SDL_Rect mover;
    
    bool direction;
    int dead;
public:
    int frame = 0;
    Unit();
    Unit(int, SDL_Texture *);
    virtual void draw(SDL_Renderer *);      //pure virtual draw. All inheritances must have a draw
    SDL_Rect getMover();
    void set_frame(int);
    void setMover(int, int, int, int);
    SDL_Texture *render();
    ~Unit(); //Destructor
    virtual void setDirection(bool);
    virtual bool check_life();
    int getDead();
    void setDead(int a);
    void setAssets(SDL_Texture *);
};
#endif