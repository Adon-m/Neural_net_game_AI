#pragma once
#include "player.h"

bool Player::addCards(Card &x, vector<Card> &y)
{
	
	if(m_Pcards.size()==0)
	{
		m_Pcards.push_back(x);
		for(int i=0;i<y.size();i++)
		{
			if(x.getCardNum()==y.at(i).getCardNum())
			{
				y.erase(y.begin()+i);
			}
		}
		return false;
	}
	else
	{
		for(int j=0;j<m_Pcards.size();j++)
		{
			if(x.getCardNum()==m_Pcards.at(j).getCardNum())
			{
				return true;
			}
		}
		m_Pcards.push_back(x);
		for(int i=0;i<y.size();i++)
		{
			if(x.getCardNum()==y.at(i).getCardNum())
			{
				y.erase(y.begin()+i);
			}
		}
		return false;
	}
	

}
void Player::clearDeal()// returns the cards back to the players card holder M_Pcards
{
	switch(PDeal.size())
	{
	case 1:
		{
			addCards(PDeal.at(0), PDeal);
			break;
		}
	case 2:
		{
			for(int i=0; i<PDeal.size(); i++)
			{
				addCards(PDeal.at(i), PDeal);
				break;
			}
		}
		case 3:
		{
			for(int i=0; i<PDeal.size(); i++)
			{
				addCards(PDeal.at(i), PDeal);
				break;
			}
		}
		case 4:
		{
			for(int i=0; i<PDeal.size(); i++)
			{
				addCards(PDeal.at(i), PDeal);
				break;
			}
		}
		default:
			{
				break;
			}
	}
}
void Player::remCards(Card &x)
{
	for (int i=0;i<m_Pcards.size();i++)
	{
		if(m_Pcards.at(i).getCardNum()==x.getCardNum())
		{
			m_Pcards.erase(m_Pcards.begin()+i);
			break;
		}
	}
		
	

}
bool Player::addToDeal(Card &x)
{
	if(PDeal.size()>=4)// only possible to deal 4 cards
		{return false;}
	if(PDeal.size()<5 && PDeal.size()>0)
	{
		if(PDeal.at(0).getCardName()==x.getCardName())
		{
		PDeal.push_back(x);// add cards to deal and remove it from the players other cards
		remCards(x);
		return true;
		}
	}
		if(PDeal.size()==0)
		{
			PDeal.push_back(x);
			remCards(x);
			return true;
		}

	
}