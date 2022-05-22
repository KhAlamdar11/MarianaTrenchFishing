#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <list>
#include "node.hpp"
#include "hook.hpp"
#include "animate.hpp"
#include "life.hpp"
#include "Boat.hpp"
#include "fishes.hpp"
using namespace std;
#pragma once
class Game
{
protected:
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The window renderer
    SDL_Renderer *gRenderer = NULL;
    // linked lists used for various objects
    linkedlist fish_on_screen;
    linkedlist animation;
    linkedlist score;
    linkedlist lyf;
    linkedlist Spawns;
    linkedlist fish_on_boat;

    int Points;
    //Current displayed texture
    SDL_Texture *gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture *assets = NULL;
    SDL_Texture *fishes = NULL;
    SDL_Texture *Misce = NULL;
    SDL_Texture *Score = NULL;
    SDL_Texture *Life = NULL;
    SDL_Texture *Booster = NULL;
    SDL_Texture *Drogon = NULL;
    SDL_Texture *fire = NULL;
    int screen;
    //win variable
    bool win = false;

public:
    Game();
    bool init();
    bool loadMedia();       // loads png images
    void close();           
    SDL_Texture *loadTexture(std::string path);
    void run();
    void collision(Hook *, Boat *);     //checks collision of fish with hook
};
