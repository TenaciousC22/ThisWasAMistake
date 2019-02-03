#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include <vector>

using namespace std;

class neuralnetwork{
public:
	neuralnetwork();
	
	void build4layer(int,int,int,int);
	void build3layer(int,int,int);
	void calculate();
	//need to figure out how I want to do this
	void setinputs();
	void display();
private:
	std::vector<std::vector<double>> network,weights1,weights2,weights3;
};
#endif