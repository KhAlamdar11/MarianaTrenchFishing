#include "myTime.hpp"
myTime::myTime(SDL_Texture *tex) : Unit()
{
    currentTime = 0;
    lastTime = 0;
    startTime = 0;
    assets = tex;
    mover[0] = {760, 570, 30, 30};
    mover[1] = {730, 570, 30, 30};
    mover[2] = {690, 570, 30, 30};
    mover[3] = {720, 585, 10, 10};
    src[0] = {0, 0, 65, 80};
    src[1] = {110, 0, 70, 80};
    src[2] = {230, 0, 70, 80};
    src[3] = {340, 0, 70, 80};
    src[4] = {460, 0, 55, 80};
    src[5] = {0, 120, 60, 86};
    src[6] = {105, 120, 70, 86};
    src[7] = {220, 120, 70, 86};
    src[8] = {340, 120, 70, 86};
    src[9] = {460, 120, 56, 86};
}
myTime::~myTime() {}
void myTime::start(int a)
{
    startTime = a;
}
int myTime::getTime()
{
    return currentTime;
}
void myTime::displayTime(int a, SDL_Renderer *renderer)
{
    currentTime = (a - startTime) / 1000;
    if (lastTime != currentTime)
    {
        lastTime = currentTime;
    }
    int dig1 = 0, dig2 = 0, dig3 = 0;
    int remain = currentTime;
    if (currentTime >= 60)
    {
        dig3 = remain / 60;
        remain = remain % 60;
    }
    if (remain < 60)
    {
        dig1 = remain % 10;
        remain = remain / 10;
        dig2 = remain % 10;
        SDL_RenderCopy(renderer, assets, &src[dig1], &mover[0]);
        SDL_RenderCopy(renderer, assets, &src[dig2], &mover[1]);
        SDL_RenderCopy(renderer, assets, &src[dig3], &mover[2]);
    }
    SDL_RenderCopy(renderer, assets, &src[0], &mover[3]);
}