#include "Battle.h"

int battle2Players(Player player1, Player player2, bool reversed)
{
	Card card1;
	Card card2;
	do {
		//Get Each Players Cards
		card1 = player1.playCard();
		card2 = player2.playCard();
		//Check for Jokers
		if (player1.playJoker()) {
			reversed = !reversed;
		}
		if (player2.playJoker()) {
			reversed = !reversed;
		}
		//If a player plays a 7, then it flips reversed
		if (card1.number == 7) reversed = !reversed;
		if (card2.number == 7) reversed = !reversed;
		//Determine if Tie
	} while (card1.isEqual(card2));
	//Determine who won
	if (reversed) { //Is the battle reversed
		if (!card1.isHigher(card2)) {
			return player2.playerID;
		}
		return player1.playerID;
	}
	else {
		if (card1.isHigher(card2)) {
			return player1.playerID;
		}
		return player2.playerID;
	}
}

int battle4Players(Player player1, Player player2, Player player3, Player player4)
{
	return 0;
}