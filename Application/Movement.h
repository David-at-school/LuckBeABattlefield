#pragma once
#include <random>

class Movement
{
public:
	int Randomization(int diceMax, int diceCount);
	void Move(int spaces);

private:
	int moveCount;
	int diceRoll;
	//true = clockwise, false = counter-clockwise
	bool direction;
};