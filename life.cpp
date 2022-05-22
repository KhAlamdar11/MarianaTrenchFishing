#pragma once
#include "life.hpp"
#include <iostream>
using namespace std;

life::life(SDL_Texture *tex,int a) : Unit(23, tex) //Overloaded Constructor of Unit to create a life point but with no textures
{
    cout << "life created" << endl;
    mover = {790-(22*a), 0, 30, 30};
}
life::~life()
{
    cout << "Destructor Called Life" << endl;
}