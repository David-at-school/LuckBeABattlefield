#include "Movement.h"

int Movement::Randomization(int diceMax, int diceCount)
{
	diceRoll = 0;

	for (int i = 0; i < diceCount; i++)
	{
		int roll = rand() % diceMax + 1;

		diceRoll += roll;
	}

	return diceRoll;
}

void Movement::Move(int spaces)
{
	if (direction)
	{
		//move along the array clockwise (positively) diceRoll
	}
	else
	{
		//move counter-clockwise (negatively) diceRoll
	}
}
