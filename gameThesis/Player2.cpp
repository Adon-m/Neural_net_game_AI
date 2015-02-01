#include "player2.h"
extern class Pot;
void Player2::dealCards()
{
	srand(time(NULL));
	vector<Card *> playable;
	vector<Card *> multiPlayable;
	
	if (getTurn()==true)

	{
		//choose cards if they are playable
		if( (Pot::getInstance()->getLastPlay().CardPower== 13) && (Pot::getInstance()->getPotSize()==getPot()) && size()>0)
		{
			int i= rand() % size();
			addToDeal(getCards(i));

		}
		{
		for(int i=0;i<size();i++)
		{
			if(getCards(i).getPower()>Pot::getInstance()->lastPlay.CardPower)
			{
			
				playable.push_back(&getCards(i));
				
				
			
			}
			
		}
		}
		//now with playable cards ... lets see if we can play them
	
	}
int lastPlayCardAmt =	Pot::getInstance()->getLastPlay().numOfCards;
int lastPlayCardPwr =  Pot::getInstance()->getLastPlay().CardPower;

Card &toPlay=getCards(0);
if(playable.size()>0)
{
int difference=playable.at(0)->getPower()-lastPlayCardPwr;
switch (lastPlayCardAmt)
{

	//--------------------------------------------------------------------//
case 1:
	{
for(int f=0; f<playable.size(); f++)
{
	
	if(playable.at(f)->getPower()-lastPlayCardPwr<difference)
	{
		difference=playable.at(f)->getPower()-lastPlayCardPwr;
		toPlay=*playable.at(f);
	}
	

}

addToDeal(toPlay);
toPlay=NULL;
break;
	}
	//----------------------------------------------------------------------//

	//----------------------------------------------------------------------//
case 2:
	{// a comparable card
		for(int first=0; first<playable.size(); first++)
		{//check if its the same card power as the second
			for(int sec=0; sec < playable.size();sec++)
			{
				if(playable.at(first)->getPower()==playable.at(sec)->getPower() && playable.at(first)->getCardNum()!=playable.at(sec)->getCardNum())
				{//if it is put it in the multi playable.
					
							multiPlayable.push_back(playable.at(first));
						
					
				
				}
			}
		}
		// if there were doubles found
		if(multiPlayable.size()>0)
		{
			for(int f=0;f<multiPlayable.size();f++)
			{
				if(multiPlayable.at(f)->getPower()-lastPlayCardPwr<difference)
				{
				difference=multiPlayable.at(f)->getPower()-lastPlayCardPwr;
				toPlay=*multiPlayable.at(f);
				}

			}
			for (int final=0;final<multiPlayable.size();final++)
			{
				if(multiPlayable.at(final)->getPower()==toPlay.getPower())
				{
					
					toPlay=*multiPlayable.at(final);
					addToDeal(toPlay);
					
				}
			}
			toPlay=NULL;
		}
		else 
		{
			setIsPass(true);
			return;

		}
		break;
	}

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

case 3:
	{
		// a comparable card
		for(int first=0; first<playable.size(); first++)
		{//check if its the same card power as the second
			for(int sec=0; sec < playable.size();sec++)
			{
				for(int third=0; third<playable.size();third++)
				{
					if(playable.at(first)->getPower()==playable.at(sec)->getPower()&&playable.at(first)->getPower()==playable.at(third)->getPower() && playable.at(first)->getCardNum()!=playable.at(sec)->getCardNum()&&playable.at(first)->getCardNum()!=playable.at(third)->getCardNum()&&playable.at(sec)->getCardNum()!=playable.at(third)->getCardNum())
				{//if it is put it in the multi playable.
					
							multiPlayable.push_back(playable.at(third));
						
					
				
				}
				}
			}
		}
		// if there were doubles found
		if(multiPlayable.size()>0)
		{
			for(int f=0;f<multiPlayable.size();f++)
			{
				if(multiPlayable.at(f)->getPower()-lastPlayCardPwr<difference)
				{
				difference=multiPlayable.at(f)->getPower()-lastPlayCardPwr;
				toPlay=*multiPlayable.at(f);
				}

			}
			for (int final=0;final<multiPlayable.size();final++)
			{
				if(multiPlayable.at(final)->getPower()==toPlay.getPower())
				{
					
					toPlay=*multiPlayable.at(final);
					addToDeal(toPlay);
				}
			}
		}
		else 
		{
			setIsPass(true);
			return;

		}
		break;


	}
	case 4:
	{

	}

default :
	{
		setIsPass(true);
		return;
	}

}
}

}
