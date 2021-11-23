#include "Player.h"

Card Player::playCard()
{
	if (hand.empty()) {
		return deck.Draw();
	}

	//Prompt Menu for what card they would like to play
	//Return that Card and remove it from the players Hand

	return Card();
}

bool Player::playJoker()
{
	return false;
}
