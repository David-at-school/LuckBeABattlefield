#pragma once
#include "Card.h"
#include <vector>

class Deck {

public:
	Deck();
	Card Draw();
	void Discard(Card& discard);
	void Shuffle();

private:
	std::vector<Card> deck;
	std::vector<Card> discard;

};