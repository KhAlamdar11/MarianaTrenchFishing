#include "fishes.hpp"
#include <iostream>
using namespace std;
#pragma once
Fishes::Fishes() : Unit()
{
    dead = 0;
}
Fishes::Fishes(int a, SDL_Texture *tex) : Unit(a, tex)
{
    dead = 0;
    type = a;
    speed = 1;
    worth_points = a;
    if (direction == false)
        setMover(800, mover.y + (rand() % 50) - (rand() % 130), mover.w, mover.h);
    else
        setMover(-100, mover.y + (rand() % 50) - (rand() % 130), mover.w, mover.h);
}
Fishes::~Fishes()
{
    cout << "Fish was Destroyed" << endl;
}
bool Fishes::Captured()
{
}
bool Fishes::getDirection()
{
    return direction;
}
void Fishes::setDirection(bool a)
{
    direction = a;
}
void Fishes::Swim()
{
    if (dead == 1)
    {
        if (mover.y >= 110)
            setMover(mover.x, mover.y - 7, mover.w, mover.h);
        else
            setDead(3);
    }
    else if (dead == 4)
    {
        drop();
    }
    else if (direction == true && freeze == false)
    {
        setMover(mover.x + 1, mover.y, mover.w, mover.h);
    }
    else if (direction == false && freeze == false)
    {
        setMover(mover.x - 1, mover.y, mover.w, mover.h);
    }
}
void Fishes::drop()
{
    if (mover.y < 600)
        setMover(mover.x, mover.y + 5, mover.w, mover.h);
    else
    {
        setDead(2);
    }
}
int Fishes::get_points()
{
    return worth_points;
}

void Fishes::stop_start(bool a)
{
    freeze = a;
}