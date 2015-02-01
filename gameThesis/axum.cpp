#pragma once
#include "axum.h"
#include "Card.h"
#include "player.h"

SDL_Surface* screen=NULL;
SDL_Surface *deck=NULL;
SDL_Surface *back=NULL;

// surface messages
SDL_Surface *clear =NULL;
SDL_Surface *deal=NULL;
SDL_Surface *dealtNum=NULL;
SDL_Surface *skipPlay=NULL;
// the screen display fonts and colour initialization
TTF_Font *font=NULL;
SDL_Color textColor ={0,0,0};
// the cards holder and event structure
SDL_Rect cards[52];
SDL_Event event;

SDL_Surface *loadImage( std::string filename )
{
	//The image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the image
	loadedImage = IMG_Load( filename.c_str() );

	//If the image loaded
	if( loadedImage != NULL )
	{
		//Create an optimized image
		optimizedImage = SDL_DisplayFormat( loadedImage );

		//Free the old image
		SDL_FreeSurface( loadedImage );

		//If the image was optimized just fine
		if( optimizedImage != NULL )
		{
			//Map the color key
			Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );

			//Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
		}
	}

	//Return the optimized image
	return optimizedImage;
}
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
	//Holds offsets
	SDL_Rect offset;

	//Get offsets
	offset.x = x;
	offset.y = y;

	//Blit
	SDL_BlitSurface( source, clip, destination, &offset );
}
void setclips()
{
	cards [0].x = CARD_WIDTH *0;
	cards [0].y = CARD_HEIGHT*0;
	cards [0].w = CARD_WIDTH;
	cards [0].h =CARD_HEIGHT;

	cards [1].x = CARD_WIDTH *1;
	cards [1].y = CARD_HEIGHT*0;
	cards [1].w = CARD_WIDTH;
	cards [1].h =CARD_HEIGHT;

	cards [2].x = CARD_WIDTH *2;
	cards [2].y = CARD_HEIGHT*0;
	cards [2].w = CARD_WIDTH;
	cards [2].h =CARD_HEIGHT;

	cards [3].x = CARD_WIDTH *3;
	cards [3].y = CARD_HEIGHT*0;
	cards [3].w = CARD_WIDTH;
	cards [3].h =CARD_HEIGHT;

	cards [4].x = CARD_WIDTH *4;
	cards [4].y = CARD_HEIGHT*0;
	cards [4].w = CARD_WIDTH;
	cards [4].h =CARD_HEIGHT;

	cards [5].x = CARD_WIDTH *5;
	cards [5].y = CARD_HEIGHT*0;
	cards [5].w = CARD_WIDTH;
	cards [5].h =CARD_HEIGHT;

	cards [6].x = CARD_WIDTH *6;
	cards [6].y = CARD_HEIGHT*0;
	cards [6].w = CARD_WIDTH;
	cards [6].h =CARD_HEIGHT;

	cards [7].x = CARD_WIDTH *7;
	cards [7].y = CARD_HEIGHT*0;
	cards [7].w = CARD_WIDTH;
	cards [7].h =CARD_HEIGHT;

	cards [8].x = CARD_WIDTH *8;
	cards [8].y = CARD_HEIGHT*0;
	cards [8].w = CARD_WIDTH;
	cards [8].h =CARD_HEIGHT;

	cards [9].x = CARD_WIDTH *9;
	cards [9].y = CARD_HEIGHT*0;
	cards [9].w = CARD_WIDTH;
	cards [9].h =CARD_HEIGHT;

	cards [10].x = CARD_WIDTH *10;
	cards [10].y = CARD_HEIGHT*0;
	cards [10].w = CARD_WIDTH;
	cards [10].h =CARD_HEIGHT;

	cards [11].x = CARD_WIDTH *11;
	cards [11].y = CARD_HEIGHT*0;
	cards [11].w = CARD_WIDTH;
	cards [11].h =CARD_HEIGHT;

	cards [12].x = CARD_WIDTH *12;
	cards [12].y = CARD_HEIGHT*0;
	cards [12].w = CARD_WIDTH;
	cards [12].h =CARD_HEIGHT;

	cards [13].x = CARD_WIDTH *0;
	cards [13].y = CARD_HEIGHT*1;
	cards [13].w = CARD_WIDTH;
	cards [13].h =CARD_HEIGHT;

	cards [14].x = CARD_WIDTH *1;
	cards [14].y = CARD_HEIGHT*1;
	cards [14].w = CARD_WIDTH;
	cards [14].h =CARD_HEIGHT;

	cards [15].x = CARD_WIDTH *2;
	cards [15].y = CARD_HEIGHT*1;
	cards [15].w = CARD_WIDTH;
	cards [15].h =CARD_HEIGHT;

	cards [16].x = CARD_WIDTH *3;
	cards [16].y = CARD_HEIGHT*1;
	cards [16].w = CARD_WIDTH;
	cards [16].h =CARD_HEIGHT;

	cards [17].x = CARD_WIDTH *4;
	cards [17].y = CARD_HEIGHT*1;
	cards [17].w = CARD_WIDTH;
	cards [17].h =CARD_HEIGHT;

	cards [18].x = CARD_WIDTH *5;
	cards [18].y = CARD_HEIGHT*1;
	cards [18].w = CARD_WIDTH;
	cards [18].h =CARD_HEIGHT;

	cards [19].x = CARD_WIDTH *6;
	cards [19].y = CARD_HEIGHT*1;
	cards [19].w = CARD_WIDTH;
	cards [19].h =CARD_HEIGHT;

	cards [20].x = CARD_WIDTH *7;
	cards [20].y = CARD_HEIGHT*1;
	cards [20].w = CARD_WIDTH;
	cards [20].h =CARD_HEIGHT;

	cards [21].x = CARD_WIDTH *8;
	cards [21].y = CARD_HEIGHT*1;
	cards [21].w = CARD_WIDTH;
	cards [21].h =CARD_HEIGHT;

	cards [22].x = CARD_WIDTH *9;
	cards [22].y = CARD_HEIGHT*1;
	cards [22].w = CARD_WIDTH;
	cards [22].h =CARD_HEIGHT;

	cards [23].x = CARD_WIDTH *10;
	cards [23].y = CARD_HEIGHT*1;
	cards [23].w = CARD_WIDTH;
	cards [23].h =CARD_HEIGHT;

	cards [24].x = CARD_WIDTH *11;
	cards [24].y = CARD_HEIGHT*1;
	cards [24].w = CARD_WIDTH;
	cards [24].h =CARD_HEIGHT;

	cards [25].x = CARD_WIDTH *12;
	cards [25].y = CARD_HEIGHT*1;
	cards [25].w = CARD_WIDTH;
	cards [25].h =CARD_HEIGHT;

	cards [26].x = CARD_WIDTH *0;
	cards [26].y = CARD_HEIGHT*2;
	cards [26].w = CARD_WIDTH;
	cards [26].h =CARD_HEIGHT;

	cards [27].x = CARD_WIDTH *1;
	cards [27].y = CARD_HEIGHT*2;
	cards [27].w = CARD_WIDTH;
	cards [27].h =CARD_HEIGHT;

	cards [28].x = CARD_WIDTH *2;
	cards [28].y = CARD_HEIGHT*2;
	cards [28].w = CARD_WIDTH;
	cards [28].h =CARD_HEIGHT;

	cards [29].x = CARD_WIDTH *3;
	cards [29].y = CARD_HEIGHT*2;
	cards [29].w = CARD_WIDTH;
	cards [29].h =CARD_HEIGHT;

	cards [30].x = CARD_WIDTH *4;
	cards [30].y = CARD_HEIGHT*2;
	cards [30].w = CARD_WIDTH;
	cards [30].h =CARD_HEIGHT;

	cards [31].x = CARD_WIDTH *5;
	cards [31].y = CARD_HEIGHT*2;
	cards [31].w = CARD_WIDTH;
	cards [31].h =CARD_HEIGHT;

	cards [32].x = CARD_WIDTH *6;
	cards [32].y = CARD_HEIGHT*2;
	cards [32].w = CARD_WIDTH;
	cards [32].h =CARD_HEIGHT;

	cards [33].x = CARD_WIDTH *7;
	cards [33].y = CARD_HEIGHT*2;
	cards [33].w = CARD_WIDTH;
	cards [33].h =CARD_HEIGHT;

	cards [34].x = CARD_WIDTH *8;
	cards [34].y = CARD_HEIGHT*2;
	cards [34].w = CARD_WIDTH;
	cards [34].h =CARD_HEIGHT;

	cards [35].x = CARD_WIDTH *9;
	cards [35].y = CARD_HEIGHT*2;
	cards [35].w = CARD_WIDTH;
	cards [35].h =CARD_HEIGHT;

	cards [36].x = CARD_WIDTH *10;
	cards [36].y = CARD_HEIGHT*2;
	cards [36].w = CARD_WIDTH;
	cards [36].h =CARD_HEIGHT;

	cards [37].x = CARD_WIDTH *11;
	cards [37].y = CARD_HEIGHT*2;
	cards [37].w = CARD_WIDTH;
	cards [37].h =CARD_HEIGHT;

	cards [38].x = CARD_WIDTH *12;
	cards [38].y = CARD_HEIGHT*2;
	cards [38].w = CARD_WIDTH;
	cards [38].h =CARD_HEIGHT;

	cards [39].x = CARD_WIDTH *0;
	cards [39].y = CARD_HEIGHT*3;
	cards [39].w = CARD_WIDTH;
	cards [39].h =CARD_HEIGHT;

	cards [40].x = CARD_WIDTH *1;
	cards [40].y = CARD_HEIGHT*3;
	cards [40].w = CARD_WIDTH;
	cards [40].h =CARD_HEIGHT;

	cards [41].x = CARD_WIDTH *2;
	cards [41].y = CARD_HEIGHT*3;
	cards [41].w = CARD_WIDTH;
	cards [41].h =CARD_HEIGHT;

	cards [42].x = CARD_WIDTH *3;
	cards [42].y = CARD_HEIGHT*3;
	cards [42].w = CARD_WIDTH;
	cards [42].h =CARD_HEIGHT;

	cards [43].x = CARD_WIDTH *4;
	cards [43].y = CARD_HEIGHT*3;
	cards [43].w = CARD_WIDTH;
	cards [43].h =CARD_HEIGHT;

	cards [44].x = CARD_WIDTH *5;
	cards [44].y = CARD_HEIGHT*3;
	cards [44].w = CARD_WIDTH;
	cards [44].h =CARD_HEIGHT;

	cards [45].x = CARD_WIDTH *6;
	cards [45].y = CARD_HEIGHT*3;
	cards [45].w = CARD_WIDTH;
	cards [45].h =CARD_HEIGHT;

	cards [46].x = CARD_WIDTH *7;
	cards [46].y = CARD_HEIGHT*3;
	cards [46].w = CARD_WIDTH;
	cards [46].h =CARD_HEIGHT;

	cards [47].x = CARD_WIDTH *8;
	cards [47].y = CARD_HEIGHT*3;
	cards [47].w = CARD_WIDTH;
	cards [47].h =CARD_HEIGHT;

	cards [48].x = CARD_WIDTH *9;
	cards [48].y = CARD_HEIGHT*3;
	cards [48].w = CARD_WIDTH;
	cards [48].h =CARD_HEIGHT;

	cards [49].x = CARD_WIDTH *10;
	cards [49].y = CARD_HEIGHT*3;
	cards [49].w = CARD_WIDTH;
	cards [49].h =CARD_HEIGHT;

	cards [50].x = CARD_WIDTH *11;
	cards [50].y = CARD_HEIGHT*3;
	cards [50].w = CARD_WIDTH;
	cards [50].h =CARD_HEIGHT;

	cards [51].x = CARD_WIDTH *12;
	cards [51].y = CARD_HEIGHT*3;
	cards [51].w = CARD_WIDTH;
	cards [51].h =CARD_HEIGHT;
}
bool Init()
{
	
	try{
		if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
		{
			throw 0;
		}
		
	}
	catch(int e)
	{
		std::cout<<"the initialization failed with error "<<e;
		return false;
	}
	
	screen = SDL_SetVideoMode( ScreenWidth, ScreenHeight, ScreenBPP , SDL_DOUBLEBUF);
	
	try{
	if(screen == NULL)
	{
		
		throw 1;
		return false;
	}
	}
	catch (int e)
	{std::cout <<"an exception in loading SDL screen occured with an error "<<e<<std::endl;
	}
	 SDL_WM_SetCaption( "hannibal", NULL);
	 
	deck=loadImage("cards.png");
	back=loadImage("back.png");
	setclips();
	try
	{
		
	
	throw 2;
	}
	catch(int e)
	{
	std::cout<<"this shit ain't working  "<<e;
	}
	try{
	TTF_Init();
	throw 3;
	}
	catch(int e)
	{
		std::cout<<"the font failed to initialise with an error "<<e;
	}
	font = TTF_OpenFont("font.ttf",60);
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x0D, 0xFF, 0xCC ) );
	
	return true;
}

//the pot

// adding cards to the pot
bool Pot::addCardsToPot(Player &y)
{
	bool returnVal;
	if(potCards.size()==0 && y.PDeal.size()==0)//if theres nothing in both then theres nothing to play
	{
		previousPotSize=y.PDeal.size();
		setLastPlay();
		y.setPot(0);// keeps a record for the player if anyone else has played after they have
		returnVal=true;
		return returnVal;
	}
	if(potCards.size()==0 && y.PDeal.size()!=0)// if its in the beginning then any cards will do.
	{
		previousPotSize=Pot::getInstance()->getPotSize();
		for(int i=0;i<y.PDeal.size();i++)
		{
			potCards.push_back(y.PDeal.at(i));
			
		}
		y.PDeal.clear();
		setLastPlay();
		y.setPot(potCards.size());
		y.setTurn(false);
		returnVal=true;
		display();
		return returnVal;
		
	}
	if(potCards.size()!=0 && y.PDeal.size()!=0)// check if the card has a higher hierachy value than the one at the last part of the vector
	{
		if (potCards.size()==y.getPot())// if equal means no player has played anything so its ok to play whichever card
		{
			previousPotSize=Pot::getInstance()->getPotSize();
			for (int i=0; i<y.PDeal.size();i++)
			{
				potCards.push_back(y.PDeal.at(i));
				
			}
			y.PDeal.clear();
			setLastPlay();
			y.setPot(potCards.size());
			y.setTurn(false);
			display();
			returnVal=true;
			return returnVal;
		}
	
		if(y.PDeal.at(0).getPower()>potCards.back().getPower())// if a card has been played make sure that the next one is of a higher ordinance than the current one
		{
			previousPotSize=Pot::getInstance()->getPotSize();
			for (int i=0; i<y.PDeal.size();i++)
			{
				potCards.push_back(y.PDeal.at(i));
				
			}
			y.PDeal.clear();
			setLastPlay();
			y.setPot(potCards.size());
			returnVal=true;
			y.setTurn(false);
			display();
			return returnVal;
		}
		if(y.PDeal.at(0).getPower()<=potCards.back().getPower())// if the card is lower then return the card into the players cards and skip a turn
		{
			for(int i=0; i<y.PDeal.size();i++)
			{
				y.addCards(y.PDeal.at(i), y.PDeal);
			}
			y.PDeal.clear();
			y.setPot(potCards.size());
			returnVal=false;
			display();
			return returnVal;
		}
		
	}
	
}

Pot* Pot::instance = NULL;

Pot* Pot::getInstance()
{
		if(instance==NULL)
		{ 
			instance = new Pot();
			
		}
		
			return instance;
	}
void Pot::display()
{
	if(potCards.size()!=0)
	{
		apply_surface(400, 300, deck, screen, &cards[potCards.back().getCardNum()]);
		//convert the int to a const char
		char buff[100];
		sprintf(buff, "%d", lastPlay.numOfCards);
		

		dealtNum= TTF_RenderText_Solid(font, buff, textColor);
		apply_surface(500 , 330, dealtNum, screen);
	}
}
// adds the initial cards to the pot
void Pot::initialize()
{
	for(int i=0;i<52;i++)
	{
		potCards.push_back(Card(i));// push the 52 cards into the Engine card storage
		
	}
	
}
 void  Pot::addCards(Player &x, int num)// the pot will give out all the cards and during gameplay the cards will be put back here...
{
	srand(time(NULL));
	int i=0;
	int a=0;
	bool isIn=false;
	while (a<num)
	{
		i= rand() % 52;
		for(unsigned int j=0;j<potCards.size();j++)
		{
			if(potCards.at(j).getCardNum()==i)
			{
				isIn=x.addCards(Card (i), potCards);
				if(isIn==false)
				{
					a++;
					break;
				}
			}
		}
	}

}
void Pot::setLastPlay()
{
	//the last card to be played's number
	lastPlay.CardPower=potCards.back().getPower();
	//takes the value of the pot before the play and subtracts it from the current size
	lastPlay.numOfCards=Pot::getInstance()->getPotSize()-previousPotSize;

}
PrevPlay Pot::getLastPlay()
{
	return lastPlay;

}
//if  a player chooses to skip, this function displays their choice.
void Pot::SkipPlay(int p)
{
	switch(p)
	{
	case 2:
		{
			skipPlay= TTF_RenderText_Solid(font, " PASS ", textColor);
			apply_surface(10 , 30, dealtNum, screen);
		}
	case 3:
		{
			skipPlay= TTF_RenderText_Solid(font, " PASS ", textColor);
			apply_surface(10 , 900, dealtNum, screen);
		}
	}

}

Player User;
Player2 User2;
Player3 User3;
void start ()
{
	
	Pot::getInstance()->initialize();
	Pot::getInstance()->addCards(User , 18);
	Pot::getInstance()->addCards(User2, 17);
	Pot::getInstance()->addCards(User3, 17);
	User.setTurn(true);
	
	
}
void handleEvents()
{
	if(User.getTurn()==true)
	{
	if (event.type== SDL_MOUSEBUTTONDOWN)
	{
		int x= event.motion.x;
		int y= event.motion.y;
		if(event.button.button == SDL_BUTTON_LEFT)
		{
			for (int i=0;i<User.size();i++)
			{
				if(x>User.getCards(i).getPositionX() && x<User.getCards(i).getPositionX()+CARD_WIDTH && y>User.getCards(i).getPositionY() && y<User.getCards(i).getPositionY()+CARD_HEIGHT)
				{
					User.addToDeal(User.getCards(i));
					SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x0D, 0xFF, 0xCC ) );
				}

			}
			if (x>900 && x<980 && y>500 && y< 540)
			{
				User.clearDeal();
				SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x0D, 0xFF, 0xCC ) );
			}
			if(x>50 && x<130  && y>500 && y<540)// user 1 deal
			{
				if(User.PDeal.size()!=0)
				{
				Pot::getInstance()->addCardsToPot( User);
				User2.setTurn(true);
				User2.setIsPass(false);
				}
			}
			if(x>700 && x>750 && y>800 &&  y<850)
			{

				
				User.clearDeal();
				User2.setTurn(true);
				User2.setIsPass(false);

			}
			
			
		}
	}
	}
	if(User2.getTurn()==true)
	{
		User2.dealCards();
		if(User2.getIsPass()==true)
		{
			Pot::getInstance()->SkipPlay(2);
			User.setTurn(true);
		}
		else
		Pot::getInstance()->addCardsToPot(User2);
		Pot::getInstance()->display();
		User3.setTurn(true);
		User2.setIsPass(false);
	}
	if(User3.getTurn()==true)
	{
		User3.dealCards();
		if(User3.getIsPass()==true)
		{
			Pot::getInstance()->SkipPlay(3);
			User.setTurn(true);
		}
		else
		Pot::getInstance()->addCardsToPot(User3);
		Pot::getInstance()->display();
		User.setTurn(true);
		User3.setIsPass(false);
	}
}
void positionCards ()
	{
		clear= TTF_RenderText_Solid(font, "CLEAR", textColor);
		deal= TTF_RenderText_Solid(font, " deal", textColor);
		skipPlay= TTF_RenderText_Solid(font, " Pass ", textColor);

		apply_surface (050,500,deal, screen );
		apply_surface (900, 500, clear, screen);
		apply_surface (700,800, skipPlay, screen);
		unsigned int width=100;
		unsigned int height=690;
		
		for (int i=0;i<User.size();i++)
		{
			if(ScreenWidth-width<73)
			{
				height=790;
				width=100;
			}
			
			
			User.getCards(i).setPosition(width, height);
		
			apply_surface(User.getCards(i).getPositionX(), User.getCards(i).getPositionY(), deck, screen, &cards[User.getCards(i).getCardNum()]);
			
			width=width+73;
		}
			unsigned int Pheight= 500;
			unsigned int Pwidth=300;
		for(int i=0; i<User.PDeal.size();i++)
		{
			User.PDeal.at(i).setPosition(Pwidth,Pheight);
			apply_surface(User.PDeal.at(i).getPositionX(), User.PDeal.at(i).getPositionY(), deck, screen, &cards[User.PDeal.at(i).getCardNum()]);
			Pwidth=Pwidth+73;
		}
		
	}

