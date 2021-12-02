#include "Battle.h"

int battle2Players(Player player1, Player player2, bool reversed)
{
	Card card1;
	Card card2;
	bool tie;
	do {
		tie = false;
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
		if (card1.isEqual(card2)) {
			tie = true;
			player1.deck->Discard(card1);
			player2.deck->Discard(card2);
		}
	} while (tie);
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

int battle4Players(Player player1, Player player2, Player player3, Player player4, bool reversed)
{
	Card card1;
	Card card2;
	Card card3;
	Card card4;
	bool tie = false;
	Card highestCard;
	int highestPlayer;
	do {
		tie = false;
		//Get Each Players Cards
		card1 = player1.playCard();
		card2 = player2.playCard();
		card3 = player3.playCard();
		card4 = player4.playCard();
		//Check for Jokers
		if (player1.playJoker()) {
			reversed = !reversed;
		}
		if (player2.playJoker()) {
			reversed = !reversed;
		}
		if (player3.playJoker()) {
			reversed = !reversed;
		}
		if (player4.playJoker()) {
			reversed = !reversed;
		}
		//If a player plays a 7, then it flips reversed
		if (card1.number == 7) reversed = !reversed;
		if (card2.number == 7) reversed = !reversed;
		if (card3.number == 7) reversed = !reversed;
		if (card4.number == 7) reversed = !reversed;

		//Find who has the highest card(don't care about ties)
		if (!reversed) {
			highestCard = card1;
			highestPlayer = 1;

			if (!highestCard.isHigher(card2)) {
				highestCard = card2;
				highestPlayer = 2;
			}
			if (!highestCard.isHigher(card3)) {
				highestCard = card3;
				highestPlayer = 3;
			}
			if (!highestCard.isHigher(card4)) {
				highestCard = card4;
				highestPlayer = 4;
			}
		}
		else {
			highestCard = card1;
			highestPlayer = 1;

			if (highestCard.isHigher(card2) && card2.number != 0) {
				highestCard = card2;
				highestPlayer = 2;
			}
			if (highestCard.isHigher(card3) && card3.number != 0) {
				highestCard = card3;
				highestPlayer = 3;
			}
			if (highestCard.isHigher(card4) && card4.number != 0) {
				highestCard = card4;
				highestPlayer = 4;
			}
		}
		//Find a tie
		if (highestCard.isEqual(card1) && highestPlayer != 1) {
			tie = true;
		}
		if (highestCard.isEqual(card2) && highestPlayer != 2) {
			tie = true;
		}
		if (highestCard.isEqual(card3) && highestPlayer != 3) {
			tie = true;
		}
		if (highestCard.isEqual(card4) && highestPlayer != 4) {
			tie = true;
		}

		if (tie) {
			player1.deck->Discard(card1);
			player2.deck->Discard(card2);
			player3.deck->Discard(card3);
			player4.deck->Discard(card4);
		}
		//Determine if Tie
	} while (tie);
	//Determine who won - Figure out this logic later
	if (highestCard.isEqual(card1)) {
		return player1.playerID;
	}
	if (highestCard.isEqual(card2)) {
		return player2.playerID;
	}
	if (highestCard.isEqual(card3)) {
		return player3.playerID;
	}
	if (highestCard.isEqual(card4)) {
		return player4.playerID;
	}
}
