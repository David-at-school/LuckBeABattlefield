#include "Deck.h"

Deck::Deck() {
	//Add cards to the Deck for all of the cards
	
	//This include 6 cards for the numbers of 1 - 13
	for (int i = 1; i < 14; i++) {
		for (int j = 0; i < 6; j++) {
			deck.push_back(Card(i));
		}
	}

	//And 3 Jokers(0)
	for (int i = 0; i < 3; i++) {
		deck.push_back(Card(0));
	}
}

Card Deck::Draw(){
	//Return the top card of the Deck
	//Then remove it from the Deck
	return Card();
}

void Deck::Discard(Card discard){
	//Send discard to the Discard List
}

void Deck::Shuffle(){
	//Takes all cards in the Deck and Discard and randomly sort them
}
