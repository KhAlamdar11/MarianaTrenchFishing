#include "unit.hpp"
#include <iostream>
using namespace std;
#pragma once

void Unit::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, assets, &src[frame], &mover); //This allows the Units to have flying animation
    frame++;
    if (frame == 3)
        frame = 0;
}
int Unit::getDead()
{
    return dead;
}

void Unit::setDead(int a)
{
    dead = a;
}
SDL_Rect Unit::getMover() //This returns the size and coordinates of the unit
{
    return mover;
}

void Unit::setMover(int a, int b, int c, int d) //Sets the Size and initial coordinates of a Unit.
{
    SDL_Rect pow = {a, b, c, d};
    mover = pow;
}
SDL_Texture *Unit ::render()
{
    return assets;
}
Unit::~Unit()
{
    cout << "Destructor Called Unit" << endl;
}
Unit::Unit()
{
}
Unit::Unit(int a, SDL_Texture *tex) //a=1 Hook,//The value of a determines whose textures has to be captured by the unit and the correspodingly sets the size and textures for them to render.
{
    if (a == 1) //Hook
    {
        src[0] = {540, 16, 166, 318};
        src[1] = {540, 16, 166, 318};
        src[2] = {540, 16, 166, 318};
        mover = {170, 42, 20, 33};
        assets = tex;
    }
    else if (a == 2) //Boat
    {
        src[0] = {0, 0, 500, 330};
        src[1] = {0, 0, 500, 330};
        src[2] = {0, 0, 500, 330};
        mover = {50, 22, 140, 85};
        assets = tex;
    }
    else if (a == 3) //The numbers will tell what type of fishes are used now onwards
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {0, 70, 100, 70};
            src[1] = {0, 70, 100, 70};
            src[2] = {0, 70, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {0, 0, 100, 70};
            src[1] = {0, 0, 100, 70};
            src[2] = {0, 0, 100, 70};
        }
        mover = {100, 300, 100, 70};
        assets = tex;
    }
    else if (a == 4)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {100, 70, 100, 70};
            src[1] = {100, 70, 100, 70};
            src[2] = {100, 70, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {100, 0, 100, 70};
            src[1] = {100, 0, 100, 70};
            src[2] = {100, 0, 100, 70};
        }
        mover = {300, 500, 100, 70};
        assets = tex;
    }
    else if (a == 5)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {200, 70, 100, 70};
            src[1] = {200, 70, 100, 70};
            src[2] = {200, 70, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {200, 0, 100, 70};
            src[1] = {200, 0, 100, 70};
            src[2] = {200, 0, 100, 70};
        }

        mover = {100, 500, 100, 70};
        assets = tex;
    }
    else if (a == 6)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {300, 70, 100, 70};
            src[1] = {300, 70, 100, 70};
            src[2] = {300, 70, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {300, 0, 100, 70};
            src[1] = {300, 0, 100, 70};
            src[2] = {300, 0, 100, 70};
        }
        mover = {350, 350, 100, 70};
        assets = tex;
    }
    else if (a == 7)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {400, 70, 100, 70};
            src[1] = {400, 70, 100, 70};
            src[2] = {400, 70, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {400, 0, 100, 70};
            src[1] = {400, 0, 100, 70};
            src[2] = {400, 0, 100, 70};
        }
        mover = {350, 200, 100, 70};
        assets = tex;
    }
    else if (a == 8) //next row
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {0, 210, 100, 70};
            src[1] = {0, 210, 100, 70};
            src[2] = {0, 210, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {0, 140, 100, 70};
            src[1] = {0, 140, 100, 70};
            src[2] = {0, 140, 100, 70};
        }
        mover = {700, 300, 100, 70};
        assets = tex;
    }
    else if (a == 9)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {100, 210, 100, 70};
            src[1] = {100, 210, 100, 70};
            src[2] = {100, 210, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {100, 140, 100, 70};
            src[1] = {100, 140, 100, 70};
            src[2] = {100, 140, 100, 70};
        }
        mover = {300, 500, 100, 70};
        assets = tex;
    }
    else if (a == 10)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {200, 210, 100, 70};
            src[1] = {200, 210, 100, 70};
            src[2] = {200, 210, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {200, 140, 100, 70};
            src[1] = {200, 140, 100, 70};
            src[2] = {200, 140, 100, 70};
        }
        mover = {100, 500, 100, 70};
        assets = tex;
    }
    else if (a == 11)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {300, 210, 100, 70};
            src[1] = {300, 210, 100, 70};
            src[2] = {300, 210, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {300, 140, 100, 70};
            src[1] = {300, 140, 100, 70};
            src[2] = {300, 140, 100, 70};
        }
        mover = {350, 350, 100, 70};
        assets = tex;
    }
    else if (a == 12)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {400, 210, 100, 70};
            src[1] = {400, 210, 100, 70};
            src[2] = {400, 210, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {400, 140, 100, 70};
            src[1] = {400, 140, 100, 70};
            src[2] = {400, 140, 100, 70};
        }
        mover = {350, 200, 100, 70};
        assets = tex;
    }
    else if (a == 13) //3rd row
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {0, 355, 100, 70};
            src[1] = {0, 355, 100, 70};
            src[2] = {0, 355, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {0, 280, 100, 70};
            src[1] = {0, 280, 100, 70};
            src[2] = {0, 280, 100, 70};
        }
        mover = {700, 300, 100, 70};
        assets = tex;
    }
    else if (a == 14)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {100, 355, 100, 70};
            src[1] = {100, 355, 100, 70};
            src[2] = {100, 355, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {100, 280, 100, 70};
            src[1] = {100, 280, 100, 70};
            src[2] = {100, 280, 100, 70};
        }
        mover = {700, 300, 100, 70};
        assets = tex;
    }
    else if (a == 15)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {200, 355, 100, 70};
            src[1] = {200, 355, 100, 70};
            src[2] = {200, 355, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {200, 280, 100, 70};
            src[1] = {200, 280, 100, 70};
            src[2] = {200, 280, 100, 70};
        }
        mover = {700, 300, 100, 70};
        assets = tex;
    }
    else if (a == 16)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {300, 355, 100, 70};
            src[1] = {300, 355, 100, 70};
            src[2] = {300, 355, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {300, 280, 100, 70};
            src[1] = {300, 280, 100, 70};
            src[2] = {300, 280, 100, 70};
        }
        mover = {700, 300, 100, 70};
        assets = tex;
    }
    else if (a == 17)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {400, 355, 100, 70};
            src[1] = {400, 355, 100, 70};
            src[2] = {400, 355, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {400, 280, 100, 70};
            src[1] = {400, 280, 100, 70};
            src[2] = {400, 280, 100, 70};
        }
        mover = {700, 300, 100, 70};
        assets = tex;
    }
    else if (a == 18) //4th row
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {0, 490, 100, 70};
            src[1] = {0, 490, 100, 70};
            src[2] = {0, 490, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {0, 420, 100, 70};
            src[1] = {0, 420, 100, 70};
            src[2] = {0, 420, 100, 70};
        }
        mover = {700, 300, 100, 70};
        assets = tex;
    }
    else if (a == 19)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {100, 490, 100, 70};
            src[1] = {100, 490, 100, 70};
            src[2] = {100, 490, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {100, 420, 100, 70};
            src[1] = {100, 420, 100, 70};
            src[2] = {100, 420, 100, 70};
        }
        mover = {300, 500, 100, 70};
        assets = tex;
    }
    else if (a == 20)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {200, 490, 100, 70};
            src[1] = {200, 490, 100, 70};
            src[2] = {200, 490, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {200, 420, 100, 70};
            src[1] = {200, 420, 100, 70};
            src[2] = {200, 420, 100, 70};
        }
        mover = {100, 500, 100, 70};
        assets = tex;
    }
    else if (a == 21)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {300, 490, 100, 70};
            src[1] = {300, 490, 100, 70};
            src[2] = {300, 490, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {300, 420, 100, 70};
            src[1] = {300, 420, 100, 70};
            src[2] = {300, 420, 100, 70};
        }
        mover = {350, 350, 100, 70};
        assets = tex;
    }
    else if (a == 22)
    {
        if (rand() % 2 == 0)
        {
            setDirection(false);
            src[0] = {400, 490, 100, 70};
            src[1] = {400, 490, 100, 70};
            src[2] = {400, 490, 100, 70};
        }
        else
        {
            setDirection(true);
            src[0] = {400, 420, 100, 70};
            src[1] = {400, 420, 100, 70};
            src[2] = {400, 420, 100, 70};
        }
        mover = {350, 280, 100, 70};
        assets = tex;
    }
    else if (a == 23)
    {
        src[0] = {0, 0, 500, 500};
        src[1] = src[0];
        src[2] = src[0];
        assets = tex;
    }
}

void Unit::setDirection(bool a)
{
    direction = a;
}
bool Unit::check_life()
{
    return true;
}
void Unit::set_frame(int a)
{
    frame = a;
}
void Unit::setAssets(SDL_Texture *tex)
{
    assets = tex;
}