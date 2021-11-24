//#pragma once
//#include "Deck.h"
//#include <string>
//#include <list>
//#include <iostream>
//
//class Player {
//	Player(int playerID, Deck& deck) : playerID{ playerID }, deck{ deck } {}
//
//public:
//	/// <summary>
//	/// A Player chooses a Card for them to play if no 
//	/// </summary>
//	/// <returns>The Card that is played</returns>
//	Card playCard();
//
//	/// <summary>
//	/// Prompts the Player if they would like to play a Joker
//	/// </summary>
//	/// <returns>If the user plays a Joker or not, works even if they don't have a joker to play</returns>
//	bool playJoker();
//
//	int playerID;
//private:
//	std::string name;
//	std::list<Card> hand;
//	Deck deck;
//};