#include "unit.hpp"
#include <iostream>
using namespace std;
#pragma once
#ifndef BOAT_H
#define BOAT_H
class Boat : public Unit //Class for rendering boat
{
protected:
    int life;           //life of the boat
    int points;
    int move_speed = 0; 
    bool direction;       // boat direction, left o right
    bool jump;              //check if boat is jumpong

public:
    Boat(SDL_Texture *);
    bool moveBoatRight();       //boat movers
    bool moveBoatLeft();
    bool Jump();
    void Jump(bool);
    void updateBoat();           //updates boat position
    void update_speed(int);        
    void reduce();                //reduces speed back to normal     
    SDL_Rect getMover();
};
#endif