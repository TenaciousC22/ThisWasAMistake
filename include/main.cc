#include <iostream>
#include <fstream>
#include "neuralnetwork.h"

using namespace std;

int main()
{
	neuralnetwork threelayer,fourlayer;
	threelayer.build3layer(4,3,1);
	fourlayer.build4layer(5,4,3,1);
	threelayer.setinputs();
	fourlayer.setinputs();
	threelayer.calculate();
	fourlayer.calculate();
	threelayer.display();
	fourlayer.display();
	return 0;
}