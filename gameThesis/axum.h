#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <SDL_ttf.h>
#include "player.h"
#include "Player2.h"
#include "player3.h"
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
const int ScreenHeight = 900;
const int ScreenWidth=1080;
const int ScreenBPP = 32;
// card measurements
const int CARD_WIDTH= 73;
const int CARD_HEIGHT =98;
struct PrevPlay
{
	int CardPower;
	int numOfCards;
};
class Pot
{
public:
	
	void initialize();//ádds the cards into the pot vector
	//allocates cards to the players.. should only be used in the begining
	void addCards(Player &x, int);
	//used to play. the cards are added back here..
	bool addCardsToPot( Player &y);
	//return the pots size
	int getPotSize(){return potCards.size();}
	// set the last play variables of the prevplay struct
	void setLastPlay ();
	//returns the last play
	PrevPlay getLastPlay();
	//displays the pots last played card 
	void display ();
	//pass indicator ... displays that the player chooses to skip the turn
	void SkipPlay(int);
	
	static Pot *getInstance();
	
	
	
	PrevPlay lastPlay;
	~Pot();
private:
	Pot(){instance = NULL;}
	static Pot *instance;
	Pot(Pot const&);
	void operator=(Pot const&);
	vector<Card>potCards;
	int previousPotSize;
};

bool Init();
void start();
void display();
void handleEvents();
void positionCards();
