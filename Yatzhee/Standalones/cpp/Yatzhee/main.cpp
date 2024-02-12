#include <iostream>
#include "Die.h"



int main()
{
	Die one = Die(default_four_faces);
	for (int i = 0; i < 20; i++){
		one.RollDie();
		one.printInfo();
	}

	return 0;
};
