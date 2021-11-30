#include "Deck.h"
#include <random>

Deck::Deck() {
	//Add cards to the Deck for all of the cards
	//This include 6 cards for the numbers of 1 - 13
	for (int i = 1; i <= 13; i++) {
		for (int j = 0; j < 6; j++) {
			deck.push_back(Card(i));
		}
	}
	//And 3 Jokers(0)
	for (int i = 0; i < 3; i++) {
		deck.push_back(Card(0));
	}
	//Then shuffle the deck
	Shuffle();
}

Card Deck::Draw() {
	//If Empty, Shuffle
	if (deck.empty()) {
		Shuffle();
	}
	//Return the top card of the Deck
	Card returnCard = deck.back();
	//Then remove it from the Deck
	deck.pop_back();
	return returnCard;
}

void Deck::Discard(Card& discard) {
	//Send discard to the Discard List
	this->discard.push_back(discard);
}

//Takes all cards in the Deck and Discard and randomly sort them
void Deck::Shuffle() {
	//A friendly reminder that we still need to set up the seed for the random - Tommy

	std::vector<Card> temp;
	for (Card c : deck) {
		temp.push_back(c);
	}
	for (Card c : discard) {
		temp.push_back(c);
	}
	deck = std::vector<Card>();
	discard = std::vector<Card>();

	do {
		//Pick a random card
		int random = rand() % temp.size();
		//Send the random card to the deck
		deck.push_back(temp[random]);
		//remove the card from the temp list
		temp[random] = temp.back();
		temp.pop_back();
	} while (temp.size() != 0);
}