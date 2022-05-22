#include "Boat.hpp"
#pragma once
Boat::Boat(SDL_Texture *tex) : Unit(2, tex)
{
    cout << "Boat Created" << endl;
    jump = false;
}
bool Boat::moveBoatRight()
{
    bool a = false;
    if (mover.x <= 650)
    {
        mover.x += 2 + move_speed / 1000;
        a = true;
    }
    return a;
}
bool Boat::Jump()
{
    return jump;
}
void Boat::Jump(bool a)
{
    jump = a;
}
void Boat::updateBoat()
{
    if (jump && mover.y == -15)
        jump = false;
    else if (jump && mover.y < 22 && mover.y >= -16)
        mover.y--;
    else if (mover.y < 22)
        mover.y++;
}
bool Boat::moveBoatLeft()
{
    bool a = false;
    if (mover.x >= -90)
    {
        mover.x -= 2 + move_speed / 1000;
        a = true;
    }
    return a;
}
SDL_Rect Boat::getMover()
{
    return mover;
}
void Boat::update_speed(int a)
{
    if (move_speed < 2000)
        move_speed += a;
}
void Boat::reduce()
{
    if (move_speed > 0)
        move_speed--;
}