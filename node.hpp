#include "unit.hpp"
#include <iostream>
#pragma once
#ifndef NODE_H
#define NODE_H
struct node //Created Linked list for every individual element. Seems hard coding to me and there must be a way to create a single linked list for every element but that is unknown to me.
{
    Unit *data;
    node *next;
};
class linkedlist //Explained in the .cpp file.
{
public:
    node *head;
    int size;
    int cap;
    int size_allowed;
    int TOF;
    bool freezed;
    linkedlist();
    void linked(Unit *);            // insert object
    void delete_position(int);
    void show(SDL_Renderer *, bool);
    void show_frame(SDL_Renderer *);
    void delete_all();            
    void update();
    void Refresh_score(int, SDL_Texture *);
    void deleteHead();
    void reduce();
    void set_motion(bool);
};
#endif