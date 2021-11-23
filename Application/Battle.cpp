#include "Battle.h"

int battle2Players(Player player1, Player player2)
{
	Card card1;
	Card card2;
	do {
		//Get Each Players Cards
		card1 = player1.playCard();
		card2 = player2.playCard();
		//Check for Jokers
			//Ask Players if they would like to play a Joker
		//Determine if Tie
	} while (!card1.isEqual(card2));
	//Determine who won
	if (card1.isHigher(card2)) {
		return player1.playerID;
	}
	else {
		return player2.playerID;
	}
}

int battle4Players(Player player1, Player player2, Player player3, Player player4)
{
	return 0;
}
