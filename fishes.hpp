#include "unit.hpp"
#include <string>
#include <iostream>
using namespace std;
#pragma once
#ifndef FISHES_H
#define FISHES_H
class Fishes : public Unit
{
protected:
    int type;              // what color
    int speed;
    int worth_points;
    bool freeze = false;    // for bonus booster
public:
    Fishes();
    Fishes(int, SDL_Texture *);
    ~Fishes();
    void Swim();
    bool Captured();        //collision detection
    bool getDirection();    
    void setDirection(bool);
    int get_points();       // to add points to score
    void stop_start(bool);
    void drop();            // drop fish
};
#endif