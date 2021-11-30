#include "Player.h"

Card Player::playCard()
{
	if (hand.empty()) {
		return deck->Draw();
	}

	//Prompt Menu for what card they would like to play
	//Return that Card and remove it from the players Hand

	return Card();
}

bool Player::playJoker()
{
	bool canPlay = false;
	for (Card c : hand) {
		if (c.number == 0) canPlay = true;
	}
	if (canPlay) {
		//Ask the player if they would like to play a Joker Card
		//If player plays a joker return true, otherwise return false
	}

	return false;
}