#include <iostream>
#include <fstream>
#include "neuralnetwork.h"

using namespace std;

int main()
{
	neuralnetwork threelayer,fourlayer;
	threelayer.build3layer(240,120,24);
	fourlayer.build4layer(240,100,60,24);
	threelayer.setinputs();
	fourlayer.setinputs();
	threelayer.calculate();
	fourlayer.calculate();
	return 0;
}