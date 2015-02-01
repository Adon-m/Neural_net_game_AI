#pragma once
#include "player3.h"
extern class Pot;
using namespace std;

vector<double> inputVals, resultVals, weights;

 
 



 vector<Card *> playable; //a pointer vector for the cards.
 
 int cardPower=0;
 int cardNum=0;

 template<typename T>
std::vector<T>& operator << (std::vector<T>& v, const T & item)
{
    v.push_back(item);  return v;
}
template<typename T>
std::vector<T>& operator,(std::vector<T>& v, const T & item)
{
    v.push_back(item);  return v;
}




typedef vector<Neuron> Layer;

// ****************** class Neuron ******************

double Neuron::transferFunction(double x)
{
    // tanh - output range [-1.0..1.0]

    return tanh(x);
}
void Neuron::feedForward(const Layer &prevLayer)
{
    double sum = 0.0;

    // Sum the previous layer's outputs (which are our inputs)
    // Include the bias node from the previous layer.

    for (unsigned n = 0; n < prevLayer.size(); ++n) {
        sum += prevLayer[n].getOutputVal() *
			prevLayer[n].m_outputWeights.at(m_myIndex);
    }

    m_outputVal = Neuron::transferFunction(sum);
}
Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
   m_numOutputs=numOutputs;

    m_myIndex = myIndex;
}
void Neuron::updateWeights(vector<double>&x)
{
	for (int j=0; j<x.size();j++)
	{
		m_outputWeights.push_back(x.at(j));
	}
	x.clear();
}

void Net::getResults(vector<double> &resultVals) 
{
    resultVals.clear();

    for (unsigned n = 0; n < m_layers.back().size() - 1; ++n) {
        resultVals.push_back(m_layers.back()[n].getOutputVal());
    }
}

void Net::feedForward( vector<double> &inputVals)
{
    assert(inputVals.size() == m_layers[0].size() - 1);

    // Assign (latch) the input values into the input neurons
    for (unsigned i = 0; i < inputVals.size(); ++i) {
        m_layers[0][i].setOutputVal(inputVals[i]);
    }

    // forward propagate
    for (unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum) {
        Layer &prevLayer = m_layers[layerNum - 1];
        for (unsigned n = 0; n < m_layers[layerNum].size()-1; ++n) {
            m_layers[layerNum][n].feedForward(prevLayer);
        }
    }
}

Net::Net()
{
	topology.push_back(2);
	topology.push_back(5);
	topology.push_back(2);
	unsigned numLayers = topology.size();
    for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
        m_layers.push_back(Layer());
        unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];

        // We have a new layer, now fill it with neurons, and
        // add a bias neuron in each layer.
        for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
            m_layers.back().push_back(Neuron(numOutputs, neuronNum));
           // std::cout << "Made a Neuron!" << endl;
        

        // Force the bias node's output to 1.0 (it was the last neuron pushed in this layer):
        m_layers.back().back().setOutputVal(1.0);
    }
}
}


	 
	 

double convertIn(int x)
{
	const double divider = -0.166666;
	switch(x)
	{
	case 2:
		{
		return -0.99999;
		break;
		}
	case 3:
		{
			return divider*5;
			break;
		}
	case 4:
		{
			return divider*4;
			break;
		}
	case 5:
		{
			return divider*3;
			break;
		}
	case 6:
		{
			return divider*2;
			break;
		}
	case 7:
		{
			return divider*1;
			break;
		}
	case 8:
		{
			return 0;
			break;
		}
	case 9:
		{
			return divider*-1;
			break;
		}
	case 10:
		{
			return divider*-2;
			break;
		}
	case 11:
		{
			return divider*-3;
			break;
		}
	case 12:
		{
			return divider*-4;
			break;
		}
	case 13:
		{
			return divider*-5;
			break;
		}
	case 14:
		
		{
			return 0.99999;
			break;
		}
	default:
		{
			return 1;
			break;
		}
	}

}



int CardPowerConvert(double num)
{
	if(num<0)
	{
		double ans=num/-0.1666666;
		 int value = (ans+0.5);
		 switch(value)
		 {
		 case 1:
			 {
				 return 7;
			 }
			 case 2:
			 {
				 return 6;
			 }
			 case 3:
			 {
				 return 5;
			 }
			 case 4:
			 {
				 return 4;
			 }
			 case 5:
			 {
				 return 3;
			 }
			 case 6:
			 {
				 return 2;
			 }
		 }
	}
	else
	{
		double ans=num/0.1666666;
		 int value = (ans+0.5);
		 switch(value)
		 {  
			case 0:
			 {
			 return 8;
			 }
			 case 1:
			 {
				 return 9;
			 }
			 case 2:
			 {
				 return 10;
			 }
			 case 3:
			 {
				 return 11;
			 }
			 case 4:
			 {
				 return 12;
			 }
			 case 5:
			 {
				 return 13;
			 }
			 case 6:
			 {
				 return 14;
			 }
		 }

	}
}
	
bool Player3::SelectCards(int cardP, int num)// returns true or false if there was a card with that cardPower and quantity
{
	

	//the 2 above are the reccomendation from the A.i chances are that the those cards may not be available
	//optionally we could have worked with the Ai using available cards to choose from but that was a daunting and time consuming task
	// so instead if we dont get the correct values from the AI as in there are no such cards then we have to choose a number higher

	//so now we search the cards vector for cards with that particular number and in that quantity

	vector<Card *> playable; //a pointer vector for the cards.

	for(int i=0; i<Player3::size(); i++)
	{
		if(Player3::getCards(i).getCardNum()==cardP)
		{
			//if a card holds that value then push it to the playable vector
			playable.push_back(&getCards(i));
		}
	}

	if(playable.size()>=num)
	{
		return true;
	}
	else
	{
		return false;
	}

	
	

}
void Player3::dealCards()
{
	
	 setupNet();

	 cardPower=Pot::getInstance()->getLastPlay().CardPower;
	 cardNum=Pot::getInstance()->getLastPlay().numOfCards;
	 //latch the inputs and feed forward
	 getInput(cardPower,cardNum);
	 myNet.getResults(resultVals);
	
	double cardPow=resultVals.at(0);
	double resultNum=resultVals.at(1)*4;//number of cards
	



	//to get exact numbers(round them up or down)
	int cardPower=CardPowerConvert(cardPow);
	int cardNum=resultNum+0.5;
	//search for those cards with thise values
	for (int i=0;i<size();i++)
	{
		if(getCards(i).getCardNum()==cardPower)
		{
			addToDeal(getCards(i));
		
		}
		if(PDeal.size()>=cardNum)
		{
			continue;
		}
		else
		{
	//if that value is not found in the cards vector, add 1
	int i=(Pot::getInstance()->getLastPlay().CardPower)+1;
	while(i<16)
	{
		getInput(i,cardNum);
		if(SelectCards(i, cardNum)==false)
		{
			i++;
		}
		else// if it returns true add it to the deal vector and deal it
		{
			for(int i=0;i<playable.size();i++)
			{
				addToDeal(*playable.at(i));
			}
			break;
		}
		
	}
		}
	
	// if i gets to 15 then we know that there was no possibility to play any cards so we must pass
	if(i>14)
	{
		setIsPass(true);
	}
	}
}

void Player3::setupNet()
{
	
	
	
	 
	 //layer 0
	  weights<<-0.172569,
1.18963,
0.0544818,
2.1111,
0.64246;
	 myNet.getNeuronsInLayer(0,0).updateWeights(weights);

	weights<<0.434568,
-0.185841,
2.33075,
-0.0108809,
0.511284;

	 myNet.getNeuronsInLayer(0,1).updateWeights(weights);
	
	 weights<<0.335868,
1.24384,
-2.31975,
-1.90835,
0.1418429;
	  myNet.getNeuronsInLayer(0,2).updateWeights(weights);
	
	  
	  //layer 1
	  weights<<-0.0497808,
0.46758;
	 myNet.getNeuronsInLayer(1,0).updateWeights(weights);

	  weights<<1.09186,
-0.0721393;
	 myNet.getNeuronsInLayer(1,1).updateWeights(weights);
	  
	  weights<<-0.0312104,
1.67373;
	 myNet.getNeuronsInLayer(1,2).updateWeights(weights);
	
	  weights<<1.63465,
0.00439301;
	 myNet.getNeuronsInLayer(1,3).updateWeights(weights);
	
	  weights<<0.398379,
0.1275;
	 myNet.getNeuronsInLayer(1,4).updateWeights(weights);
	
	 weights<<0.690002,
1.63672;
	 myNet.getNeuronsInLayer(1,5).updateWeights(weights);

}

void Player3::getInput(int cardx,int cardNumy)
{
	
	inputVals.clear();
	

	 inputVals.push_back(convertIn(cardx));
	 inputVals.push_back(cardNumy/4);
	 
	myNet.feedForward(inputVals);
	
	 
}