#include "hook.hpp"
#include <iostream>
using namespace std;
#pragma once
Hook::Hook(SDL_Texture *tex) : Unit(1, tex)
{
    //numbers = 100; //These could be number of hooks.
    moveHk = 0;
    hookBool = 0;
    cout << "hook created" << endl;
}
void Hook::updateHookRight()
{
    mover.x += 2 + move_speed / 1000;
}
int Hook::GetHookBool()
{
    return hookBool;
}
void Hook::updateHookLeft()
{
    mover.x -= 2 + move_speed / 1000;
}
int Hook::moveHook()
{

    if (mover.y <= 570 && mover.y >= 560)
    {
        moveHk = 1;
        hookBool = 1;
    }
    if (mover.y <= 600 && moveHk == 0)
    {
        mover.y += 5;
        hookBool = 1;
    }
    else if (mover.y > 48 && moveHk == 1)
    {
        mover.y -= 7;
        hookBool = 1;
    }
    else
    {
        hookBool = 0;
        moveHk = 0;
    }
    return hookBool;
}
void Hook::update_speed(int a)
{
    if (move_speed < 2000)
        move_speed += a;
}
void Hook::reduce()
{
    if (move_speed > 0)
        move_speed--;
}