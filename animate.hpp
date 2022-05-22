#include <iostream>
#include "unit.hpp"
using namespace std;
#pragma once
class Anime : public Unit
{
protected:
    SDL_Rect src[18];
    int TTL;
    int LT;
    int interval;
    int version = 0;

public:
    Anime(int, SDL_Texture *);
    ~Anime();
    void draw(SDL_Renderer *);
    void draw_frame(SDL_Renderer *);
    bool check_life();
    int get_version();
};