#pragma once

#include <string>
using namespace std;


class Card
{
public:
	Card(unsigned int);// the int is the value of the card on the image array
	unsigned int getCardNum(){return cardNum;}
	std::string getCardName(){return cardName;}
	void setPosition ( unsigned int, unsigned int);
	int getPositionX();
	int getPositionY();
	int getSuite(){return suite;}
	int getPower(){return power;}
private:
	unsigned int cardNum;// represents the number the card takes on the array
	std::string cardName;// the value eg 2 aces kings
	unsigned int suite; // the suite value of the card
    int positionX; 
	int positionY;
	int power;
};