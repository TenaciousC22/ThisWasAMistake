#include "neuralnetwork.h"
#include <iostream>
#include <vector>

using namespace std;

neuralnetwork::neuralnetwork(){}

void neuralnetwork::build3layer(int inputval, int hiddenval, int outputval)
{
	vector<double> input,hidden,output,w1,w2;
	double w1val,w2val;
	for(int i=0;i<inputval;i++)
	{
		input.push_back(0);
	}
	for(int i=0;i<hiddenval;i++)
	{
		hidden.push_back(0);
	}
	for(int i=0;i<outputval;i++)
	{
		output.push_back(0);
	}
	network.push_back(input);
	network.push_back(hidden);
	network.push_back(output);
	w1val=1/static_cast<double>(inputval);
	w2val=1/static_cast<double>(hiddenval);
	for(int i=0;i<inputval;i++)
	{
		w1.push_back(w1val);
	}
	for(int i=0;i<hiddenval;i++)
	{
		w2.push_back(w2val);
		weights1.push_back(w1);
	}
	for(int i=0;i<outputval;i++)
	{
		weights2.push_back(w2);
	}
}

void neuralnetwork::build4layer(int inputval, int hidden1val, int hidden2val, int outputval)
{
	vector<double> input,hidden1,hidden2,output,w1,w2,w3;
	double w1val,w2val,w3val;
	for(int i=0;i<inputval;i++)
	{
		input.push_back(0);
	}
	for(int i=0;i<hidden1val;i++)
	{
		hidden1.push_back(0);
	}
	for(int i=0;i<hidden2val;i++)
	{
		hidden2.push_back(0);
	}
	for(int i=0;i<outputval;i++)
	{
		output.push_back(0);
	}
	network.push_back(input);
	network.push_back(hidden1);
	network.push_back(hidden2);
	network.push_back(output);
	w1val=1/static_cast<double>(inputval);
	w2val=1/static_cast<double>(hidden1val);
	w3val=1/static_cast<double>(hidden2val);
	for(int i=0;i<inputval;i++)
	{
		w1.push_back(w1val);
	}
	for(int i=0;i<hidden1val;i++)
	{
		w2.push_back(w2val);
		weights1.push_back(w1);
	}
	for(int i=0;i<hidden2val;i++)
	{
		w3.push_back(w3val);
		weights2.push_back(w2);
	}
	for(int i=0;i<outputval;i++)
	{
		weights3.push_back(w3);
	}
}

void neuralnetwork::calculate()
{
	int i,j,k;
	double sum;
	for(i=0;i<network[1].size();i++,k++)
	{
		sum=0;
		for(j=0;j<network[0].size();j++,k++)
		{
			sum=sum+(weights1[i][j]*network[0][j]);
		}
		network[1][i]=sum;
	}
	for(i=0;i<network[2].size();i++,k++)
	{
		sum=0;
		for(j=0;j<network[1].size();j++,k++)
		{
			sum=sum+(weights2[i][j]*network[1][j]);
		}
		network[2][i]=sum;
	}
	if(network.size()==4)
	{
		for(i=0;i<network[3].size();i++,k++)
		{
			sum=0;
			for(j=0;j<network[2].size();j++,k++)
			{
				sum=sum+(weights3[i][j]*network[2][j]);
			}
			network[3][i]=sum;
		}
	}
	cout<<k<<endl;
}

void neuralnetwork::setinputs()
{
	for(int i=0;i<network[0].size();i++)
	{
		network[0][i]=1;
	}
}

void neuralnetwork::display()
{
	for(int i=0;i<network.size();i++)
	{
		for(int j=0;j<network[i].size();j++)
		{
			cout<<network[i][j]<<endl;
		}
	}
}