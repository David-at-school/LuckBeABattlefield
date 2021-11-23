#pragma once
#include "Card.h"\
#include <string>
#include <list>

class Player {
	
public:
	/// <summary>
	/// A Player chooses a Card for them to play
	/// </summary>
	/// <returns>The Card that is played</returns>
	Card playCard();

private:
	int playerID;
	//string name;
	std::list<Card> hand;
};