#pragma once
#include "Card.h"

Card::Card(unsigned int x )
{
	cardNum=x;
	if (cardNum >=0 && cardNum <=12)// if the card number is below 13 its clubs
	{
	   suite= 1;
		
	}
	if (cardNum >12 && cardNum <=25)//spades
	{
		suite= 2;
		
	}
	if (cardNum >25 && cardNum <=38)//hearts
	{
		suite= 3;
		
	}
	if (cardNum >38 && cardNum <=51)//diamonds
	{
		suite= 4;
		
	}
	/* set card name */
	
	if((x==0) || (x==13) || (x==26) || (x==39))
	{
		cardName =  "Ace";
		power=13;
	}
	if((x==1)|| (x==14) || (x==27) || (x==40) )
	{
		cardName =  "two";
		power=1;
	}
	if((x==2)||(x==15)||(x==28)||(x==41))
	{
		cardName =  "three";
		power= 2;
	}
	if((x==3)||(x==16)||(x==29)||(x==42))
	{
		cardName =  "four";
		power=3;
	}
	if((x==4)||(x==17)||(x==30)||(x==43))
	{
		cardName =  "five";
		power=4;
	}
	if((x==5)||(x==18)||(x==31)||(x==44))
	{
		cardName =  "six";
		power=5;
	}
	if((x==6)||(x==19)||(x==32)||(x==45))
	{
		cardName =  "seven";
		power=6;
	}
	if((x==7)||(x==20)||(x==33)||(x==46))
	{
		cardName =  "eight";
		power=7;
	}
	if((x==8)||(x==21)||(x==34)||(x==47))
	{
		cardName =  "nine";
		power=8;
	}
	if ((x==9)||(x==22)||(x==35)||(x==48))
	{
		cardName =  "ten";
		power=9;
	}
	if((x==10)||(x==23)||(x==36)||(x==49))
	{
		cardName =  "jack";
		power=10;
	}
	if((x==11)||(x==24)||(x==37)||(x==50))
	{
		cardName =  "queen";
		power=11;
	}
	if((x==12)||(x==25)||(x==38)||(x==51))
	{
		cardName =  "king";
		power=12;
	}

}
void Card::setPosition(unsigned int x, unsigned int y)
{
	positionX=x;

	positionY=y;
}

int Card::getPositionX()
{
	return positionX;
}
int Card::getPositionY()
{
	return positionY;
}