#pragma once
#include "axum.h"
#include "player.h"

class Neuron;
typedef vector<Neuron> Layer;

// ****************** class Neuron ******************
class Neuron
{
public:
    Neuron(unsigned numOutputs, unsigned myIndex);
	   void setOutputVal(double val) { m_outputVal = val; }
    double getOutputVal(void) const { return m_outputVal; }
    void feedForward(const Layer &prevLayer);
	void updateWeights(vector<double>&);
private: 
	static double transferFunction(double x);
	 double m_outputVal;
    vector<double> m_outputWeights;
    unsigned m_myIndex;
	unsigned m_numOutputs;
};
class Net
{
public:
    Net();
	
    void feedForward( vector<double> &inputVals);
	void getResults(vector<double> &resultVals);
	Neuron& getNeuronsInLayer(unsigned l,unsigned n){return m_layers.at(l).at(n);}
private:
    vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
	 vector <unsigned> topology;
};



class Player3 : public Player
{
public:
	vector<double> inputVals, resultVals, weights;
	Net  myNet;
	
	void getInput(int,int);
	
	bool SelectCards(int cardP, int num);
	void dealCards();// returns true or false if it could or could not play the round
	void play(); //combine them all in one function from setup to last play. 
	void setupNet();
private:
};
