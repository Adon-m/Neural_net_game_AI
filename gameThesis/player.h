#pragma once
#include "Card.h"
#include <vector>
class Player
{
private:
	vector<Card> m_Pcards;
	bool isTurn;
	int potSize;
	bool isPass;
public:
	Player(){
	isTurn=false;}
	//~Player(void);
	bool addCards(Card &, vector<Card> &);// adds cards to the playes vector
	void remCards(Card &);// removes cards from the players cards vector
	Card& getCards (int x){return m_Pcards.at(x);} 
	unsigned int size(){return m_Pcards.size();}// returns the size of m_Pcards
	//void setTurnTrue(bool x){isTurn = x;}
	bool getTurn(){return isTurn;}
	void setTurn(bool x){isTurn=x; }
	//setters and getters for the pot size to see if it contains any changes 
	void setPot(int pot){potSize=pot;}
	int getPot(){return potSize;}

	vector<Card> PDeal;// the vector that holds cards to be dealt
	void clearDeal();
	bool addToDeal(Card &x);
	void setIsPass(bool x){isPass=x;}
	bool getIsPass(){return isPass;}
};