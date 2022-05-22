#include "game.hpp"
#include <iostream>
#include <cmath>
using namespace std;
bool pause = true;
#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include "Boat.hpp"
#include "fishes.hpp"
#include "myTime.hpp"
#include "shark.hpp"
#include "life.hpp"
#include "Dragon.hpp"
#include "fire.hpp"
#pragma once

string PrintKeyInfo(SDL_KeyboardEvent *key)
{
	string det = "";
	if (key->type == SDL_KEYDOWN)
	{
		det = SDL_GetKeyName(key->keysym.sym);
	}
	return det;
}
Game::Game() { screen = 1; }

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("God Of Rod", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()

{
	//Loading success flag
	bool success = true;
	assets = loadTexture("assets.png");
	gTexture = loadTexture("bg.png");
	fishes = loadTexture("fishes.png");
	Misce = loadTexture("Poof.png");
	Score = loadTexture("score.png");
	Life = loadTexture("life.png");
	Drogon = loadTexture("Rhaegal.png");
	fire = loadTexture("fire.png");
	Booster = loadTexture("Boosters.png");
	if (assets == NULL || gTexture == NULL || fishes == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}

	return success;
}
void Game::collision(Hook *hook, Boat *boat)
{
	node *p = fish_on_screen.head;
	int q = 1;
	Fishes *DC;
	while (p != NULL)
	{
		DC = (Fishes *)(p->data);
		if (DC->getDirection() == false)
		{
			if (hook->getMover().x >= p->data->getMover().x - 20 && hook->getMover().x <= p->data->getMover().x + 20 && hook->getMover().y <= p->data->getMover().y + 20 && hook->getMover().y >= p->data->getMover().y - 20 && p->data->getDead() != 3)
			{
				Points += DC->get_points();
				score.Refresh_score(Points, Score);
				if (p->data->getDead() == 0)
					p->data->setDead(1);
				fish_on_boat.linked(p->data);
				fish_on_screen.size_allowed++;
				fish_on_screen.cap++;
				hook->moveHk = 1;
				break;
			}
			else
			{
				p = p->next;
				q++;
			}
		}
		else
		{
			if (hook->getMover().x >= p->data->getMover().x + 40 && hook->getMover().x <= p->data->getMover().x + 80 && hook->getMover().y <= p->data->getMover().y + 20 && hook->getMover().y >= p->data->getMover().y - 20 && p->data->getDead() != 3)
			{
				Points += DC->get_points();
				score.Refresh_score(Points, Score);
				if (p->data->getDead() == 0)
					p->data->setDead(1);
				fish_on_boat.linked(p->data);
				fish_on_screen.size_allowed++;
				fish_on_screen.cap++;
				hook->moveHk = 1;
				break;
			}
			else
			{
				p = p->next;
				q++;
			}
		}
		node *K = Spawns.head;
		q = 1;
		Anime *DC3;
		while (K != NULL)
		{
			DC3 = (Anime *)(K->data);
			if (hook->getMover().x >= K->data->getMover().x - 20 && hook->getMover().x <= K->data->getMover().x + 40 && hook->getMover().y <= K->data->getMover().y + 20 && hook->getMover().y >= K->data->getMover().y - 20)
			{
				if (DC3->get_version() == 3)
				{
					boat->update_speed(2000);
					hook->update_speed(2000);
				}
				else if (DC3->get_version() == 4)
				{
					fish_on_screen.size_allowed += 15;
				}
				else if (DC3->get_version() == 5)
				{
					fish_on_screen.set_motion(true);
				}
				Spawns.delete_position(q);
				K = K->next;
			}
			else
			{
				K = K->next;
				q++;
			}
		}
	}
}

SDL_Texture *Game::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture *newTexture = NULL;

	//Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Game::close()
{
	cout << "CLOSE" << endl;
	SDL_DestroyTexture(assets);
	assets = NULL;
	SDL_DestroyTexture(fishes);
	fishes = NULL;
	SDL_DestroyTexture(Life);
	Life = NULL;
	SDL_DestroyTexture(gTexture);

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	fish_on_screen.delete_all();
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


void Game::run()
{
	int q;
	SDL_RenderClear(gRenderer);
	bool quit = false;
	bool win1 = true;
	bool sharkAttack = false;
	bool sharkAttack2 = false;
	bool sharkhit = false;
	bool sharkhit2 = false;
	bool dragonAttack = false;
	bool haveFish = false;
	int fishReleasedTime = 1000000;
	bool fishReleasedTimeBool = false;
	Points = 0;
	Boat boat(assets);
	Hook hook(assets);
	shark shark1(fishes), shark2(fishes);
	Dragon dragon(Drogon, fire);
	myTime time1(Score);
	for (int i = 1; i < 6; i++)
		lyf.linked(new life(Life, i));

	int hookC = 0;
	//Event handler
	SDL_Event e;
	//While application is running
	score.Refresh_score(Points, Score);
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_t && fish_on_boat.size > 0)
			{
				fishReleasedTime = time1.getTime();
				if (time1.getTime() > 5)
				{
					dragon.fishThrown(true);
					fishReleasedTimeBool = true;
				}
				fish_on_boat.head->data->setDead(4);
				fish_on_boat.head->data->setMover(boat.getMover().x, boat.getMover().y, fish_on_boat.head->data->getMover().w, fish_on_boat.head->data->getMover().h);
				Fishes *DC;
				DC = (Fishes *)(fish_on_boat.head->data);
				Points -= DC->get_points();
				score.Refresh_score(Points, Score);
				fish_on_boat.deleteHead();
				fish_on_screen.size_allowed--;
				fish_on_screen.cap--;
			}
		}
		if (screen == 2)
		{
			if (fish_on_screen.size < fish_on_screen.size_allowed && (rand() % 20) == 1)
			{
				q = (rand() % 20) + 3;
				Unit *p = new Fishes(q, fishes);
				fish_on_screen.linked(p);
			}
			if (Spawns.size < 2 && (rand() % 2000) == 240)
			{
				q = (rand() % 3) + 3;
				Unit *p = new Anime(q, Booster);
				Spawns.linked(p);
			}
			//Moveboat and hook function below
			string k = PrintKeyInfo(&e.key);
			if (k == "")
			{
			}
			else
			{
				hook.GetHookBool();
			}
			if (k == "Down" || hookC == 1)
			{
				//cout << "here" << endl;

				hookC = hook.moveHook();
			}

			else if (k == "Right")
			{
				if (boat.moveBoatRight())
					hook.updateHookRight();
			}
			else if (k == "Left")
			{
				if (boat.moveBoatLeft())
					hook.updateHookLeft();
			}
			if (k == "Up")
			{
				if (boat.getMover().y == 22)
				{
					boat.setMover(boat.getMover().x, boat.getMover().y - 1, boat.getMover().w, boat.getMover().h);
					boat.Jump(true);
				}
			}
			else if (k == "Left Shift")
			{
				screen = 3;
			}
			if (k == "Tab")
			{
				screen = 4;
				SDL_Delay(250);
			}
			SDL_RenderClear(gRenderer);												   //removes everything from renderer
			SDL_RenderCopy(gRenderer, gTexture, new SDL_Rect({0, 0, 800, 600}), NULL); //Draws background to renderer
			boat.updateBoat();
			boat.draw(gRenderer);
			hook.draw(gRenderer);
			boat.reduce(); //The reduce functions works like a timer for booster to be over.
			hook.reduce();
			fish_on_screen.reduce();
			if (fish_on_screen.head != NULL)
			{
				if (hook.moveHk == 0)
					collision(&hook, &boat);
				fish_on_screen.update();
				fish_on_screen.show(gRenderer, true);
				//animation.show(gRenderer);
				score.show_frame(gRenderer);
				Spawns.show_frame(gRenderer);
			}

			if (time1.getTime() >= 60 && time1.getTime() <= 120)
			{
				shark1.draw(gRenderer, false);
				shark1.attack(&boat);
				if (shark1.attack(&boat) == true && sharkAttack == false)
				{
					lyf.deleteHead();
				}
				sharkAttack = shark1.attack(&boat);
				if (shark1.sharkHit(&hook) == true && sharkhit == false)
				{
					shark1.life--;
					hook.moveHk = 1;
				}
				sharkhit = shark1.sharkHit(&hook);
			}
			else if (time1.getTime() > 120 && time1.getTime() < 180)
			{
				shark1.draw(gRenderer, true);
				shark1.attack(&boat);
				if (shark1.attack(&boat) == true && sharkAttack == false)
				{
					lyf.deleteHead();
				}
				sharkAttack = shark1.attack(&boat);
			}
			else if (time1.getTime() >= 180 && time1.getTime() < 240)
			{
				if (time1.getTime() > 187)
				{
					shark2.draw(gRenderer, false);
					shark2.attack(&boat);
					if (shark2.attack(&boat) == true && sharkAttack2 == false)
					{
						lyf.deleteHead();
					}
					sharkAttack2 = shark2.attack(&boat);
					if (shark2.sharkHit(&hook) == true && sharkhit2 == false)
					{
						shark2.life--;
						hook.moveHk = 1;
					}
					sharkhit2 = shark2.sharkHit(&hook);
					if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_c)
					{
						shark2.life--;
					}
				}
				shark1.draw(gRenderer, false);
				shark1.attack(&boat);
				if (shark1.attack(&boat) == true && sharkAttack == false)
				{
					lyf.deleteHead();
				}
				sharkAttack = shark1.attack(&boat);
				if (shark1.sharkHit(&hook) == true && sharkhit == false)
				{
					shark1.life--;
					hook.moveHk = 1;
				}
				sharkhit = shark1.sharkHit(&hook);
			}
			else if (time1.getTime() >= 240)
			{
				shark1.draw(gRenderer, true);
				shark1.attack(&boat);
				if (shark1.attack(&boat) == true && sharkAttack == false)
				{
					lyf.deleteHead();
				}
				sharkAttack = shark1.attack(&boat);
				shark2.draw(gRenderer, true);
				shark2.attack(&boat);
				if (shark2.attack(&boat) == true && sharkAttack == false)
				{
					lyf.deleteHead();
				}
				sharkAttack2 = shark2.attack(&boat);
			}
			if (time1.getTime() > 240)
			{
				dragon.draw(gRenderer, boat.getMover().x);
				if (dragon.burnBoat(&boat) == true && dragonAttack == false)
				{
					lyf.deleteHead();
				}
				dragonAttack = dragon.burnBoat(&boat);
				if ((time1.getTime() - fishReleasedTime) > 5 && fishReleasedTimeBool == true)
				{
					dragon.frame = 0;
					dragon.fishThrown(false);
					fishReleasedTimeBool = false;
				}
				if (Points == 0 && haveFish == true)
				{
					screen = 5;
				}
			}
			if (Points > 0)
				haveFish = true;
			else
				haveFish = false;
			time1.displayTime(SDL_GetTicks(), gRenderer);
			if (lyf.head != NULL)
			{
				lyf.show(gRenderer, false);
			}
			else
			{
				screen = 3;
			}
		}
		else if (screen == 1)
		{
			SDL_RenderClear(gRenderer);													 //removes everything from renderer
			SDL_RenderCopy(gRenderer, gTexture, new SDL_Rect({800, 0, 800, 600}), NULL); //Draws background to renderer
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (e.button.button == SDL_BUTTON_LEFT) //CHECK LEFT CLICK
				{
					int xMouse, yMouse;
					SDL_GetMouseState(&xMouse, &yMouse);
					if (xMouse > 300 && yMouse > 240 && xMouse < 500 && yMouse < 305) //To check if start button pressed
					{
						screen = 2;
						time1.start(SDL_GetTicks());
					}
					else if (xMouse > 300 && yMouse > 363 && xMouse < 500 && yMouse < 427) //To check if start button pressed
					{
						screen = 6;
					}
				}
			}
		}
		else if (screen == 3)
		{
			SDL_RenderClear(gRenderer);													 //removes everything from renderer
			SDL_RenderCopy(gRenderer, gTexture, new SDL_Rect({0, 600, 800, 600}), NULL); //Draws background to renderer
			score.show_frame(gRenderer);
		}
		else if (screen == 5)
		{
			SDL_RenderClear(gRenderer);													  //removes everything from renderer
			SDL_RenderCopy(gRenderer, gTexture, new SDL_Rect({1600, 0, 800, 600}), NULL); //Draws background to renderer
			score.show_frame(gRenderer);
		}
		else if (screen == 6)
		{
			SDL_RenderClear(gRenderer);														//removes everything from renderer
			SDL_RenderCopy(gRenderer, gTexture, new SDL_Rect({1600, 600, 800, 600}), NULL); //Draws background to renderer
			if (e.button.button == SDL_BUTTON_LEFT)											//CHECK LEFT CLICK
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				if (xMouse > 38 && yMouse > 530 && xMouse < 127 && yMouse < 580) //To check if start button pressed
				{
					screen = 1;
				}
			}
		}
		else if (screen == 4)
		{
			if (PrintKeyInfo(&e.key) == "Tab")
			{
				screen = 2;
				SDL_Delay(250);
			}
			SDL_RenderClear(gRenderer);													   //removes everything from renderer
			SDL_RenderCopy(gRenderer, gTexture, new SDL_Rect({800, 600, 800, 600}), NULL); //Draws background to renderer
		}

		SDL_RenderPresent(gRenderer); //displays the updated renderer
		SDL_Delay(10);				  //causes sdl engine to delay for specified miliseconds
	}
}
