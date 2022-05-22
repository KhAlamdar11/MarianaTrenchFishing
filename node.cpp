#include "node.hpp"
#include "animate.hpp"
#include "fishes.hpp"
#pragma once
#include <iostream>
using namespace std;
linkedlist::linkedlist() //Constructor function
{
    head = NULL;
    size = 0;
    size_allowed = 8;
    TOF = 0;
    freezed = false;
}

void linkedlist::linked(Unit *a) //Inserts a Unit * in the linked list.
{
    node *newnode = new node;
    newnode->data = a;
    newnode->next = head;
    head = newnode;
    size++;
}
void linkedlist::delete_position(int a)
{
    if (a == 1)
    {
        node *p = head->next;
        delete head;
        head = p;
        size--;
    }
    else
    {
        node *p = head;
        for (int i = 0; i < a - 2; i++)
        {
            p = p->next;
        }
        node *t = p->next->next;
        delete p->next;
        p->next = t;
        size--;
    }
}
void linkedlist::delete_all() //Deletes every Unit * from the linked list
{
    node *q;
    while (head != NULL)
    {
        q = head->next;
        delete head;
        head = q;
    }
    delete q;
}
void linkedlist::show(SDL_Renderer *renderer, bool is_fish) //Renders every Unit * into the screen
{
    node *q = head; //basically used the same intuition as we used in Show data of linked list
    int p = 1;
    Fishes *DC;
    while (q != NULL)
    {
        if (is_fish == true && q->data->getDead() != 3)
        {
            DC = (Fishes *)(q->data);
            DC->Swim();
        }
        if (q->data->getDead() != 3)
            q->data->draw(renderer);
        if (q != NULL)
            q = q->next;
        p++;
    }
}
void linkedlist::show_frame(SDL_Renderer *renderer) //Renders every Unit * into the screen
{
    int p = 1;
    Anime *DC;
    node *q = head; //basically used the same intuition as we used in Show data of linked list
    while (q != NULL)
    {
        DC = (Anime *)(q->data);
        if (q->data->check_life() == false)
        {
            delete_position(p);
            if (q != NULL)
            {
                q = q->next;
            }
        }
        else
        {
            DC->draw_frame(renderer);
            if (q != NULL)
            {
                q = q->next;
                p++;
            }
        }
    }
}
void linkedlist::deleteHead()
{
    node *currentnode = head;
    head = currentnode->next;
    delete currentnode;
    size--;
}
void linkedlist::update()
{
    Fishes *DC, *DC2;
    node *currentnode = head;
    DC = (Fishes *)(currentnode->data);
    if (currentnode->next != NULL)
        DC2 = (Fishes *)(currentnode->next->data);
    if ((currentnode->data->getDead() == 2) || currentnode->data->getMover().x > 850 & DC->getDirection() == true || currentnode->data->getMover().x < -100 & DC->getDirection() == false)
    {
        head = currentnode->next;
        delete currentnode;
        size--;
    }
    else
    {
        while (currentnode->next != NULL)
        {
            DC = (Fishes *)(currentnode->data);
            if ((currentnode->next->data->getDead() == 2) || currentnode->next->data->getMover().x > 850 & DC2->getDirection() == true || currentnode->next->data->getMover().x < -100 & DC2->getDirection() == false)
            {
                node *prevnode = currentnode;
                node *nextnode = (currentnode->next)->next;
                currentnode = currentnode->next;
                delete currentnode;
                prevnode->next = nextnode;
                size--;
                break;
            }
            else
            {
                currentnode = currentnode->next;
            }
        }
    }
}

void linkedlist::Refresh_score(int Points, SDL_Texture *tex)
{
    if (head != NULL)
        delete_all();
    int remain = Points;
    int k;
    for (int i = 4; i >= 0; i--) ///CHECK THIS OUTTTTT
    {
        Unit *s = new Anime(2, tex);
        s->setMover(i * 20, 0, 20, 20);
        k = remain % 10;
        remain = remain / 10;
        s->set_frame(k);
        linked(s);
    }
}
void linkedlist::reduce()
{
    if (size_allowed > 6 + cap && (rand() % 20) == 1)
        size_allowed--;
    if (freezed == true)
    {
        if (TOF > 0)
        {
            TOF--;
        }
        else
        {
            set_motion(false);
            freezed = false;
        }
    }
}
void linkedlist::set_motion(bool a)
{
    node *q = head;
    Fishes *DC;
    while (q != NULL)
    {
        DC = (Fishes *)(q->data);
        DC->stop_start(a);
        q = q->next;
    }
    if (a == true)
    {
        TOF = 1000;
        freezed = true;
    }
}